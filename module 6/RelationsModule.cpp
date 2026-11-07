#include "RelationsModule.h"

bool RelationsModule::elementExists(string e) {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i] == e)
            return true;
    return false;
}

void RelationsModule::addElement(string e) {
    if (!elementExists(e))
        elements.push_back(e);
}

bool RelationsModule::pairExists(string a, string b) {
    for (int i = 0; i < rel.size(); i++)
        if (rel[i].first == a && rel[i].second == b)
            return true;
    return false;
}

void RelationsModule::addRelation(string a, string b) {
    if (elementExists(a) && elementExists(b)) {
        if (!pairExists(a, b))
            rel.push_back(make_pair(a, b));
    }
    else {
        cout << "Invalid elements for relation!" << endl;
    }
}

void RelationsModule::printSet() {
    cout << "Set A = { ";
    for (int i = 0; i < elements.size(); i++) {
        cout << elements[i];
        if (i < elements.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
}

void RelationsModule::printRelation() {
    cout << "Relation R = { ";
    for (int i = 0; i < rel.size(); i++) {
        cout << "(" << rel[i].first << "," << rel[i].second << ")";
        if (i < rel.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
}

// Check properties
bool RelationsModule::isReflexive() {
    for (string x : elements)
        if (!pairExists(x, x))
            return false;
    return true;
}

bool RelationsModule::isSymmetric() {
    for (int i = 0; i < rel.size(); i++) {
        string a = rel[i].first;
        string b = rel[i].second;
        if (!pairExists(b, a))
            return false;
    }
    return true;
}

bool RelationsModule::isTransitive() {
    for (int i = 0; i < rel.size(); i++) {
        for (int j = 0; j < rel.size(); j++) {
            string a = rel[i].first;
            string b = rel[i].second;
            string c = rel[j].second;
            if (b == rel[j].first) {
                if (!pairExists(a, c))
                    return false;
            }
        }
    }
    return true;
}

bool RelationsModule::isEquivalence() {
    return isReflexive() && isSymmetric() && isTransitive();
}

bool RelationsModule::isPartialOrder() {
    return isReflexive() && !isSymmetric() && isTransitive();
}
