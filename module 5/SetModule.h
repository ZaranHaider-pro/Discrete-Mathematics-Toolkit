#ifndef SETMODULE_H
#define SETMODULE_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class SimpleSet {
private:
    string name;
    vector<string> elements;

    bool exists(string x);
public:
    SimpleSet(string n = "");
    void setName(string n);

    string getName();
    void addElement(string x);
    void printSet();

    vector<string> getElements();
};

class SetModule {
private:
    vector<SimpleSet> sets;

    int findSetIndex(string setName);

public:
    // Create & Show Sets
    bool createSet(string setName);
    bool addElementToSet(string setName, string element);
    void displaySet(string setName);
    void displayAllSets();

    // Operations
    void setUnion(string A, string B);
    void setIntersection(string A, string B);
    void setDifference(string A, string B);
    void checkSubset(string A, string B);
};

#endif
