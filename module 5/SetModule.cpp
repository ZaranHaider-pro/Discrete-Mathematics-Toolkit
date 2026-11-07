#include "SetModule.h"

SimpleSet::SimpleSet(string n) {
    name = n;
}

void SimpleSet::setName(string n) {
    name = n;
}

string SimpleSet::getName() {
    return name;
}

bool SimpleSet::exists(string x) {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i] == x) return true;
    return false;
}

void SimpleSet::addElement(string x) {
    if (!exists(x)) elements.push_back(x);
}

vector<string> SimpleSet::getElements() {
    return elements;
}

void SimpleSet::printSet() {
    cout << name << " = { ";
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i];
        if (i < elements.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
}
int SetModule::findSetIndex(string setName) {
    for (int i = 0; i < sets.size(); i++)
        if (sets[i].getName() == setName)
            return i;
    return -1;
}

bool SetModule::createSet(string setName) {
    if (findSetIndex(setName) != -1) return false;
    sets.push_back(SimpleSet(setName));
    return true;
}

bool SetModule::addElementToSet(string setName, string element) {
    int idx = findSetIndex(setName);
    if (idx == -1) return false;

    sets[idx].addElement(element);
    return true;
}

void SetModule::displaySet(string setName) {
    int idx = findSetIndex(setName);
    if (idx == -1) {
        cout << "Set not found!" << endl;
        return;
    }
    sets[idx].printSet();
}

void SetModule::displayAllSets() {
    for (int i = 0; i < sets.size(); i++)
        sets[i].printSet();
}

void SetModule::setUnion(string A, string B) {
    int a = findSetIndex(A), b = findSetIndex(B);
    if (a == -1 || b == -1) {
        cout << "Invalid sets!" << endl;
        return;
    }
    cout << "Union Result: " << A << " ∪ " << B << " = { ";
    vector<string> eA = sets[a].getElements();
    vector<string> eB = sets[b].getElements();

    for (string x : eA) cout << x << " ";
    for (string y : eB) {
        bool exists = false;
        for (string x : eA)
            if (x == y) exists = true;
        if (!exists) cout << y << " ";
    }
    cout << "}" << endl;
}

void SetModule::setIntersection(string A, string B) {
    int a = findSetIndex(A), b = findSetIndex(B);
    if (a == -1 || b == -1) {
        cout << "Invalid sets!" << endl;
        return;
    }
    cout << "Intersection: { ";
    vector<string> eA = sets[a].getElements();
    vector<string> eB = sets[b].getElements();

    for (string x : eA)
        for (string y : eB)
            if (x == y)
                cout << x << " ";
    cout << "}" << endl;
}

void SetModule::setDifference(string A, string B) {
    int a = findSetIndex(A), b = findSetIndex(B);
    if (a == -1 || b == -1) {
        cout << "Invalid sets!" << endl;
        return;
    }
    cout << "Difference (" << A << " - " << B << "): { ";
    vector<string> eA = sets[a].getElements();
    vector<string> eB = sets[b].getElements();

    for (string x : eA) {
        bool common = false;
        for (string y : eB)
            if (x == y)
                common = true;
        if (!common) cout << x << " ";
    }
    cout << "}" << endl;
}

void SetModule::checkSubset(string A, string B) {
    int a = findSetIndex(A), b = findSetIndex(B);
    if (a == -1 || b == -1) {
        cout << "Invalid sets!" << endl;
        return;
    }
    vector<string> eA = sets[a].getElements();
    vector<string> eB = sets[b].getElements();

    for (string x : eA) {
        bool found = false;
        for (string y : eB)
            if (x == y) found = true;
        if (!found) {
            cout << A << " is NOT a subset of " << B << endl;
            return;
        }
    }
    cout << A << " is a subset of " << B << endl;
}
