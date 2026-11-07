#ifndef RELATIONSMODULE_H
#define RELATIONSMODULE_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class RelationsModule {
private:
    vector<string> elements;          // The base set
    vector<pair<string, string>> rel; // Relation pairs

    bool elementExists(string e);
    bool pairExists(string a, string b);

public:
    void addElement(string e);
    void addRelation(string a, string b);
    void printSet();
    void printRelation();

    bool isReflexive();
    bool isSymmetric();
    bool isTransitive();
    bool isEquivalence();
    bool isPartialOrder();
};

#endif
