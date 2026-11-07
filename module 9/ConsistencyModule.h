#ifndef CONSISTENCYMODULE_H
#define CONSISTENCYMODULE_H

#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include <tuple>
using namespace std;
struct Issue {
    string type;    
    string detail;  
    Issue() {}
    Issue(string t, string d) : type(t), detail(d) {}
};

class ConsistencyModule {
private:
    
    int indexOf(const vector<string>& vec, const string& val);
    bool detectCycleUtil(int v, vector<int>& visited, vector<int>& recStack,
        const vector<vector<int>>& adj);

public:
    vector<Issue> validatePrereqsExistence(const vector<string>& courses,
        const vector<pair<string, string>>& prereqs);
    vector<Issue> detectPrereqCycles(const vector<string>& courses,
        const vector<pair<string, string>>& prereqs);
    vector<Issue> validateFunctionMappings(const vector<string>& domain,
        const vector<string>& codomain,
        const vector<pair<string, string>>& mappings,
        const string& funName = "f");
    vector<Issue> validateRelationElements(const vector<string>& elements,
        const vector<pair<string, string>>& relPairs);

    vector<Issue> validateSets(const vector<pair<string, vector<string>>>& sets);
    vector<Issue> validateFacts(const vector<tuple<string, string, string>>& facts);
    void printIssues(const vector<Issue>& issues);
    void printProjectDocPath();
};

#endif
