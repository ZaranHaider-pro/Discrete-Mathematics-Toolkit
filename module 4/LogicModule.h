#ifndef LOGICMODULE_H
#define LOGICMODULE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Fact {
    string predicate; 
    string subject;   
    string value;     
    Fact() {}
    Fact(string p, string s, string v) : predicate(p), subject(s), value(v) {}
};

struct Rule {
 
    string p_pred;
    string p_subj;
    string p_val;
    string c_pred;
    string c_subj;
    string c_val;
    Rule() {}
    Rule(string pp, string ps, string pv, string cp, string cs, string cv)
        : p_pred(pp), p_subj(ps), p_val(pv), c_pred(cp), c_subj(cs), c_val(cv) {
    }
};

class LogicModule {
private:
    vector<Fact> facts;
    vector<Rule> rules;

    bool matchPattern(const Fact& fact, const string& pred, const string& subj, const string& val);
    bool factExists(const Fact& f);
    int findConflictIndex(const Fact& f);

public:
    LogicModule();

    
    bool addFact(const string& predicate, const string& subject, const string& value);
    void listFacts();
    void clearFacts();
    bool addRule(const string& p_pred, const string& p_subj, const string& p_val,
        const string& c_pred, const string& c_subj, const string& c_val);
    void listRules();
    void clearRules();

    // inference
    void runInference();
    int checkConflicts();
    void printFact(const Fact& f);
};

#endif
