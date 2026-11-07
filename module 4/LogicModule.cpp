#include "LogicModule.h"

LogicModule::LogicModule() {}
bool LogicModule::matchPattern(const Fact& fact, const string& pred, const string& subj, const string& val) {
    if (!(pred == "*" || pred == fact.predicate)) return false;
    if (!(subj == "*" || subj == fact.subject)) return false;
    if (!(val == "*" || val == fact.value)) return false;
    return true;
}

bool LogicModule::factExists(const Fact& f) {
    for (int i = 0; i < facts.size(); ++i) {
        if (facts[i].predicate == f.predicate &&
            facts[i].subject == f.subject &&
            facts[i].value == f.value) return true;
    }
    return false;
}

int LogicModule::findConflictIndex(const Fact& f) {
    for (int i = 0; i < facts.size(); ++i) {
        if (facts[i].predicate == f.predicate &&
            facts[i].subject == f.subject &&
            facts[i].value != f.value) return i;
    }
    return -1;
}

bool LogicModule::addFact(const string& predicate, const string& subject, const string& value) {
    Fact f(predicate, subject, value);
    if (factExists(f)) return false; // already present
    int conflict = findConflictIndex(f);
    if (conflict != -1) 
    {
        
        cout << "CONFLICT: existing fact has a different value:\n";
        printFact(facts[conflict]);
        cout << "New fact: ";
        printFact(f);
        return false;
    }
    facts.push_back(f);
    return true;
}

void LogicModule::listFacts() {
    cout << "\nFacts:\n";
    if (facts.size() == 0) {
        cout << "(none)\n";
        return;
    }
    for (int i = 0; i < facts.size(); ++i) {
        cout << i + 1 << ". ";
        printFact(facts[i]);
    }
}

void LogicModule::clearFacts() {
    facts.clear();
}

bool LogicModule::addRule(const string& p_pred, const string& p_subj, const string& p_val,
    const string& c_pred, const string& c_subj, const string& c_val) {
    Rule r(p_pred, p_subj, p_val, c_pred, c_subj, c_val);
    rules.push_back(r);
    return true;
}

void LogicModule::listRules() {
    cout << "\nRules:\n";
    if (rules.size() == 0) {
        cout << "(none)\n";
        return;
    }
    for (int i = 0; i < rules.size(); ++i) {
        cout << i + 1 << ". IF " << rules[i].p_pred << " " << rules[i].p_subj << " " << rules[i].p_val
            << " THEN " << rules[i].c_pred << " " << rules[i].c_subj << " " << rules[i].c_val << "\n";
    }
}

void LogicModule::clearRules() {
    rules.clear();
}

void LogicModule::printFact(const Fact& f) {
    cout << f.predicate << " " << f.subject << " " << f.value << "\n";
}

void LogicModule::runInference() {
    bool addedNew = true;
    int iterations = 0;
    while (addedNew) {
        addedNew = false;
        ++iterations;
        for (int r = 0; r < rules.size(); ++r) {
            Rule cur = rules[r];
            
            for (int f = 0; f < facts.size(); ++f) {
                if (matchPattern(facts[f], cur.p_pred, cur.p_subj, cur.p_val)) {
                    
                    string conclSubj = cur.c_subj;
                    string conclVal = cur.c_val;
                    Fact newFact(cur.c_pred, conclSubj, conclVal);
                    if (!factExists(newFact)) {
                        int conflict = findConflictIndex(newFact);
                        if (conflict != -1) {
                            cout << "Inference conflict detected when applying rule " << (r + 1) << ":\n";
                            printFact(facts[conflict]);
                            cout << "Would infer: ";
                            printFact(newFact);
                            
                        }
                        else {
                            facts.push_back(newFact);
                            addedNew = true;
                        }
                    }
                }
            }
        }
        
        if (iterations > 5000) break;
    }
    cout << "Inference complete. Iterations: " << iterations << "\n";
}

int LogicModule::checkConflicts() {
  
    for (int i = 0; i < facts.size(); ++i) {
        for (int j = i + 1; j < facts.size(); ++j) {
            if (facts[i].predicate == facts[j].predicate &&
                facts[i].subject == facts[j].subject &&
                facts[i].value != facts[j].value) {
                return j;
            }
        }
    }
    return -1;
}
