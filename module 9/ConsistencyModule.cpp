#include "ConsistencyModule.h"
int ConsistencyModule::indexOf(const vector<string>& vec, const string& val) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (vec[i] == val) return i;
    }
    return -1;
}
vector<Issue> ConsistencyModule::validatePrereqsExistence(
    const vector<string>& courses,
    const vector<pair<string, string>>& prereqs)
{
    vector<Issue> issues;
    for (int i = 0; i < (int)prereqs.size(); ++i) {
        string course = prereqs[i].first;
        string prereq = prereqs[i].second;
        if (indexOf(courses, course) == -1) {
            issues.push_back(Issue("MissingCourse",
                "Course '" + course + "' in prerequisite pair (" + course + "," + prereq + ") not found in courses list."));
        }
        if (indexOf(courses, prereq) == -1) {
            issues.push_back(Issue("MissingCourse",
                "Prerequisite '" + prereq + "' in pair (" + course + "," + prereq + ") not found in courses list."));
        }
    }
    return issues;
}
bool ConsistencyModule::detectCycleUtil(int v, vector<int>& visited, vector<int>& recStack,
    const vector<vector<int>>& adj)
{
    visited[v] = 1;
    recStack[v] = 1;
    for (int i = 0; i < (int)adj[v].size(); ++i) {
        int nb = adj[v][i];
        if (!visited[nb]) {
            if (detectCycleUtil(nb, visited, recStack, adj)) return true;
        }
        else if (recStack[nb]) return true;
    }
    recStack[v] = 0;
    return false;
}

vector<Issue> ConsistencyModule::detectPrereqCycles(const vector<string>& courses,
    const vector<pair<string, string>>& prereqs)
{
    vector<Issue> issues;
    int n = courses.size();
    if (n == 0) return issues;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < (int)prereqs.size(); ++i) {
        string course = prereqs[i].first;
        string prereq = prereqs[i].second;
        int ci = indexOf(courses, course);
        int pi = indexOf(courses, prereq);
        if (ci == -1 || pi == -1) continue; 
        adj[pi].push_back(ci);
    }

    vector<int> visited(n, 0), recStack(n, 0);
    bool hasCycle = false;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (detectCycleUtil(i, visited, recStack, adj)) {
                hasCycle = true;
                break;
            }
        }
    }
    if (hasCycle) {
        issues.push_back(Issue("Cycle", "Cycle detected in course prerequisites (invalid prerequisite loop)."));
    }
    return issues;
}
vector<Issue> ConsistencyModule::validateFunctionMappings(const vector<string>& domain,
    const vector<string>& codomain,
    const vector<pair<string, string>>& mappings,
    const string& funName)
{
    vector<Issue> issues;
 
    for (int i = 0; i < (int)mappings.size(); ++i) {
        string d = mappings[i].first;
        string im = mappings[i].second;
        if (indexOf(domain, d) == -1) {
            issues.push_back(Issue("FunctionDomainError",
                funName + ": domain element '" + d + "' in mapping does not exist in domain."));
        }
        if (indexOf(codomain, im) == -1) {
            issues.push_back(Issue("FunctionCodomainError",
                funName + ": image '" + im + "' in mapping for '" + d + "' does not exist in codomain."));
        }
    }
    
    for (int i = 0; i < (int)mappings.size(); ++i) {
        for (int j = i + 1; j < (int)mappings.size(); ++j) {
            if (mappings[i].first == mappings[j].first) {
                issues.push_back(Issue("FunctionDuplicateDomain",
                    funName + ": multiple mappings found for domain element '" + mappings[i].first + "'."));
            }
        }
    }
    return issues;
}

vector<Issue> ConsistencyModule::validateRelationElements(const vector<string>& elements,
    const vector<pair<string, string>>& relPairs)
{
    vector<Issue> issues;
    for (int i = 0; i < (int)relPairs.size(); ++i) {
        string a = relPairs[i].first;
        string b = relPairs[i].second;
        if (indexOf(elements, a) == -1) {
            issues.push_back(Issue("RelationElementMissing",
                "Relation uses element '" + a + "' which is not in base set."));
        }
        if (indexOf(elements, b) == -1) {
            issues.push_back(Issue("RelationElementMissing",
                "Relation uses element '" + b + "' which is not in base set."));
        }
    }
    return issues;
}
vector<Issue> ConsistencyModule::validateSets(const vector<pair<string, vector<string>>>& sets) {
    vector<Issue> issues;
    for (int i = 0; i < (int)sets.size(); ++i) {
        const string& sname = sets[i].first;
        const vector<string>& elems = sets[i].second;
        if (elems.size() == 0) {
            issues.push_back(Issue("EmptySet", "Set '" + sname + "' is empty."));
        }
        // duplicate element check
        for (int a = 0; a < (int)elems.size(); ++a) {
            for (int b = a + 1; b < (int)elems.size(); ++b) {
                if (elems[a] == elems[b]) {
                    issues.push_back(Issue("DuplicateElement", "Set '" + sname + "' contains duplicate element '" + elems[a] + "'."));
                }
            }
        }
    }
    return issues;
}
vector<Issue> ConsistencyModule::validateFacts(const vector<tuple<string, string, string>>& facts) {
    vector<Issue> issues;
    
    for (int i = 0; i < (int)facts.size(); ++i) {
        string pi = get<0>(facts[i]);
        string si = get<1>(facts[i]);
        string vi = get<2>(facts[i]);
        for (int j = i + 1; j < (int)facts.size(); ++j) {
            string pj = get<0>(facts[j]);
            string sj = get<1>(facts[j]);
            string vj = get<2>(facts[j]);
            if (pi == pj && si == sj && vi != vj) {
                string detail = "Conflict for predicate '" + pi + "' and subject '" + si +
                    "': values '" + vi + "' vs '" + vj + "'.";
                issues.push_back(Issue("FactConflict", detail));
            }
        }
    }
    return issues;
}

void ConsistencyModule::printIssues(const vector<Issue>& issues) {
    if (issues.empty()) {
        cout << "No issues found. Data is consistent for the checks performed.\n";
        return;
    }
    cout << "\nConsistency issues found (" << issues.size() << "):\n";
    for (int i = 0; i < (int)issues.size(); ++i) {
        cout << i + 1 << ". [" << issues[i].type << "] " << issues[i].detail << "\n";
    }
    cout << endl;
}
void ConsistencyModule::printProjectDocPath() {
    cout << "Project document path: /mnt/data/Discrete Final Project.docx\n";
}
