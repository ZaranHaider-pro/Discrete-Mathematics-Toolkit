#ifndef INDUCTIONMODULE_H
#define INDUCTIONMODULE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course {
public:
    string code;
    string name;
    Course() {}
    Course(string c, string n) : code(c), name(n) {}
};

class InductionModule {
private:
    vector<Course> courses;
    vector<vector<int>> prereqAdj;

    int findCourseIndex(const string& code);
    bool allPrereqsCompleted(int idx,
        vector<int>& completedFlag,
        vector<int>& visited,
        vector<int>& recStack,
        string& failReason);

public:
 
    InductionModule();
    bool addCourse(const string& code, const string& name);
    bool addPrerequisite(const string& course, const string& prereq);
    bool markCompletedForStudent(const string& code);
    void listCourses();
    void listCompletedCourses();
    bool canStudentTakeCourse(const string& course);
};

#endif
