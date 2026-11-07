#ifndef STUDENTGROUPMODULE_H
#define STUDENTGROUPMODULE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string name;
    Student() {}
    Student(string n) { name = n; }
};

class StudentGroupModule {
private:
    vector<Student> students;

    void generateCombinations(int start, int groupSize,
        vector<string>& current,
        vector<vector<string>>& result);

public:
    bool addStudent(string name);
    void printAllStudents();
    void formGroups(int groupSize);
};

#endif
