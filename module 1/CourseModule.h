#ifndef COURSEMODULE_H
#define COURSEMODULE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Course {
public:
    string code;
    string name;

    Course() {}
    Course(string c, string n) {
        code = c;
        name = n;
    }
};

class CourseModule {
private:
    vector<Course> courses;
    vector<vector<int>> adj; // adjacency list (prereq -> dependent)

    int findCourseIndex(string code);

    bool dfsCycle(int v, vector<bool>& visited, vector<bool>& recStack);
public:
    CourseModule();

    bool addCourse(string code, string name);
    bool addPrerequisite(string course, string prereq);

    bool hasCycle();

    void printOneValidOrder();
};

#endif
