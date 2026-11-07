#include "ProofModule.h"

// Strong Induction Proof
void ProofModule::printInductionProof(vector<string> missing) {
    if (missing.empty()) {
        cout << "By strong induction, student has completed every prerequisite.\n";
        cout << "Base case and induction hypothesis satisfied.\n";
    }
    else {
        cout << "Strong Induction Fails!\n";
        cout << "Missing prerequisite chain elements: { ";
        for (int i = 0; i < missing.size(); i++) {
            cout << missing[i] << " ";
        }
        cout << "}\n";
    }
}

// Set Subset Proof
void ProofModule::printSubsetProof(const vector<string>& missing) {
    if (missing.empty()) {
        cout << "Subset property holds because all elements of A exist in B.\n";
    }
    else {
        cout << "Not a subset! Missing elements: { ";
        for (auto& m : missing) cout << m << " ";
        cout << "}\n";
    }
}

// Relation Proofs
void ProofModule::reflexiveProof(const vector<string>& missing) {
    if (missing.empty()) {
        cout << "Relation is reflexive: every (a,a) pair exists.\n";
    }
    else {
        cout << "Not reflexive! Missing pairs: { ";
        for (auto& x : missing)
            cout << "(" << x << "," << x << ") ";
        cout << "}\n";
    }
}

void ProofModule::symmetricProof(const vector<pair<string, string>>& failed) {
    if (failed.empty()) {
        cout << "Symmetric property holds.\n";
    }
    else {
        cout << "Not symmetric! Missing reverse pairs: { ";
        for (auto& p : failed)
            cout << "(" << p.second << "," << p.first << ") ";
        cout << "}\n";
    }
}

void ProofModule::transitiveProof(
    const vector<pair<string, string>>& failedFrom,
    const vector<pair<string, string>>& failedTo
) {
    if (failedFrom.empty()) {
        cout << "Transitive property holds.\n";
        return;
    }
    cout << "Not transitive!\n";
    for (int i = 0; i < failedFrom.size(); i++) {
        cout << "Because (" << failedFrom[i].first << "," << failedFrom[i].second
            << ") and (" << failedTo[i].first << "," << failedTo[i].second
            << ") exist but (" << failedFrom[i].first << "," << failedTo[i].second
            << ") does not.\n";
    }
}

// Function Proofs
void ProofModule::injectiveProof(const string& d1, const string& d2, const string& img) {
    cout << "Not injective because f(" << d1 << ") = f(" << d2 << ") = " << img
        << " and " << d1 << " != " << d2 << endl;
}

void ProofModule::surjectiveProof(const vector<string>& missing) {
    if (missing.empty()) {
        cout << "Function is surjective: every element in codomain is covered.\n";
    }
    else {
        cout << "Not surjective! Missing preimages for codomain elements: { ";
        for (auto& m : missing) cout << m << " ";
        cout << "}\n";
    }
}
