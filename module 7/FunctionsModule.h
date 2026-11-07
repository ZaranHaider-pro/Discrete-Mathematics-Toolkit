#ifndef FUNCTIONSMODULE_H
#define FUNCTIONSMODULE_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

class FunctionsModule {
private:
    string name;                       
    vector<string> domain;             
    vector<string> codomain;           
    vector<string> mapDomain;          
    vector<string> mapImage;           

    int indexOf(const vector<string>& v, const string& x);
    bool mappingExistsForDomain(const string& d);
    bool elementInDomain(const string& d);
    bool elementInCodomain(const string& c);

public:
    FunctionsModule(string nm = "f");

    // name
    void setName(string nm);
    string getName();

    // sets
    void addDomainElement(string d);
    void addCodomainElement(string c);
    void printDomain();
    void printCodomain();

    // mappings
    bool addMapping(string d, string c); 
    void printMapping();

    // properties
    bool isInjective();
    bool isSurjective();
    bool isBijective();
    void printInverse();
    void composeWith(FunctionsModule& g);
};

#endif
