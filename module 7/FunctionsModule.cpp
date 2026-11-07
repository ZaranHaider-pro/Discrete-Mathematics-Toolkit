#include "FunctionsModule.h"
int FunctionsModule::indexOf(const vector<string>& v, const string& x) {
    for (int i = 0; i < (int)v.size(); ++i)
        if (v[i] == x) return i;
    return -1;
}

bool FunctionsModule::elementInDomain(const string& d) {
    return indexOf(domain, d) != -1;
}
bool FunctionsModule::elementInCodomain(const string& c) {
    return indexOf(codomain, c) != -1;
}
bool FunctionsModule::mappingExistsForDomain(const string& d) {
    return indexOf(mapDomain, d) != -1;
}
FunctionsModule::FunctionsModule(string nm) {
    name = nm;
}

void FunctionsModule::setName(string nm) { name = nm; }
string FunctionsModule::getName() { return name; }

void FunctionsModule::addDomainElement(string d) {
    if (!elementInDomain(d)) domain.push_back(d);
}

void FunctionsModule::addCodomainElement(string c) {
    if (!elementInCodomain(c)) codomain.push_back(c);
}

void FunctionsModule::printDomain() {
    cout << "Domain: { ";
    for (int i = 0; i < (int)domain.size(); ++i) {
        cout << domain[i];
        if (i < (int)domain.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
}

void FunctionsModule::printCodomain() {
    cout << "Codomain: { ";
    for (int i = 0; i < (int)codomain.size(); ++i) {
        cout << codomain[i];
        if (i < (int)codomain.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
}

bool FunctionsModule::addMapping(string d, string c) {
    if (!elementInDomain(d)) {
        cout << "Domain element not found. Add it first.\n";
        return false;
    }
    if (!elementInCodomain(c)) {
        cout << "Codomain element not found. Add it first.\n";
        return false;
    }
    int idx = indexOf(mapDomain, d);
    if (idx != -1) {
        mapImage[idx] = c;
        return true;
    }
    mapDomain.push_back(d);
    mapImage.push_back(c);
    return true;
}

void FunctionsModule::printMapping() {
    cout << "Function " << name << " mappings:\n";
    if (mapDomain.size() == 0) {
        cout << "(no mappings defined)\n";
        return;
    }
    for (int i = 0; i < (int)mapDomain.size(); ++i) {
        cout << mapDomain[i] << " -> " << mapImage[i] << "\n";
    }
}

// injective
bool FunctionsModule::isInjective() {
    for (int i = 0; i < (int)mapImage.size(); ++i) {
        for (int j = i + 1; j < (int)mapImage.size(); ++j) {
            if (mapImage[i] == mapImage[j]) return false;
        }
    }
    return true;
}

// surjective
bool FunctionsModule::isSurjective() {
    for (int i = 0; i < (int)codomain.size(); ++i) {
        bool covered = false;
        for (int j = 0; j < (int)mapImage.size(); ++j) {
            if (codomain[i] == mapImage[j]) { covered = true; break; }
        }
        if (!covered) return false;
    }
    return true;
}

bool FunctionsModule::isBijective() {
    // bijective
    
    if (!isInjective()) return false;
    if (!isSurjective()) return false;
    return true;
}

void FunctionsModule::printInverse() {
    if (!isBijective()) {
        cout << "Function is not bijective — inverse does not exist (as a function).\n";
        return;
    }
    cout << "Inverse of " << name << ":\n";
    for (int i = 0; i < (int)mapDomain.size(); ++i) {
        cout << mapImage[i] << " -> " << mapDomain[i] << "\n";
    }
}
void FunctionsModule::composeWith(FunctionsModule& g) {
    cout << "Composing " << g.getName() << " ∘ " << name << ":\n";
    if (mapDomain.size() == 0) {
        cout << "No mappings in " << name << " to compose.\n";
        return;
    }
    
    for (int i = 0; i < (int)mapDomain.size(); ++i) {
        string a = mapDomain[i];
        string b = mapImage[i];
        
        int gIdx = indexOf(g.mapDomain, b);
        if (gIdx == -1) {
            cout << "g does not have image for " << b << " — composition undefined for " << a << "\n";
        }
        else {
            string c = g.mapImage[gIdx];
            cout << a << " -> " << c << "\n";
        }
    }
}
