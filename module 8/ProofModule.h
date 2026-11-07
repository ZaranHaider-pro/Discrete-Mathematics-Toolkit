#ifndef PROOFMODULE_H
#define PROOFMODULE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

class ProofModule {
public:
    // Induction proof 
    void printInductionProof(vector<string> missing);

    // Set theory
    void printSubsetProof(const vector<string>& missing);

    // Relation properties
    void reflexiveProof(const vector<string>& missing);
    void symmetricProof(const vector<pair<string, string>>& failed);
    void transitiveProof(const vector<pair<string, string>>& failedFrom,
        const vector<pair<string, string>>& failedTo);

    // Function mapping proofs
    void injectiveProof(const string& d1, const string& d2, const string& img);
    void surjectiveProof(const vector<string>& missing);
};

#endif
