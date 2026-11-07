#include "InductionModule.h"
InductionModule::InductionModule() {}
int InductionModule::findCourseIndex(const string& code) {
    for (int i = 0; i < (int)courses.size(); ++i) {
        if (courses[i].code == code) return i;
    }
    return -1;
}

bool InductionModule::addCourse(const string& code, const string& name) {
    if (findCourseIndex(code) != -1) return false; 
    courses.push_back(Course(code, name));
    prereqAdj.push_back(vector<int>()); 
    return true;
}

bool InductionModule::addPrerequisite(const string& course, const string& prereq) {
    int ci = findCourseIndex(course);
    int pi = findCourseIndex(prereq);
    if (ci == -1 || pi == -1) return false;
    for (int x : prereqAdj[ci]) if (x == pi) return false;
    prereqAdj[ci].push_back(pi);
    return true;
}
bool InductionModule::markCompletedForStudent(const string& code) {
    int idx = findCourseIndex(code);
    if (idx == -1) return false;
    static vector<int> persistentCompleted; 
    if ((int)persistentCompleted.size() < (int)courses.size()) {
        persistentCompleted.resize(courses.size(), 0);
    }
    persistentCompleted[idx] = 1;
    cout << "Marked " << code << " as completed for Student1.\n";
    return true;
}

void InductionModule::listCourses() {
    cout << "\nAvailable Courses:\n";
    for (int i = 0; i < (int)courses.size(); ++i) {
        cout << i + 1 << ". " << courses[i].code << " - " << courses[i].name << "\n";
    }
}
void InductionModule::listCompletedCourses() {
    static vector<int> persistentCompleted;
    if ((int)persistentCompleted.size() < (int)courses.size())
        persistentCompleted.resize(courses.size(), 0);

    cout << "\nStudent1 Completed Courses:\n";
    int count = 0;
    for (int i = 0; i < (int)courses.size(); ++i) {
        if (persistentCompleted[i]) {
            cout << "- " << courses[i].code << " (" << courses[i].name << ")\n";
            ++count;
        }
    }
    if (count == 0) cout << "No courses completed yet.\n";
}
bool InductionModule::allPrereqsCompleted(int idx,
    vector<int>& completedFlag,
    vector<int>& visited,
    vector<int>& recStack,
    string& failReason)
{
    if ((int)visited.size() <= idx) visited.resize(courses.size(), 0);
    if ((int)recStack.size() <= idx) recStack.resize(courses.size(), 0);

    if (visited[idx]) return true; 
    visited[idx] = 1;
    recStack[idx] = 1;
    for (int p : prereqAdj[idx]) {
        
        if (recStack[p]) {
            failReason = "Cycle detected in prerequisites (invalid prerequisite loop).";
            return false;
        }
        if (completedFlag[p] == 0) {
            failReason = "Missing prerequisite: " + courses[p].code;
            return false;
        }
        if (!allPrereqsCompleted(p, completedFlag, visited, recStack, failReason))
            return false;
    }

    recStack[idx] = 0;
    return true;
}

bool InductionModule::canStudentTakeCourse(const string& course) {
    int idx = findCourseIndex(course);
    if (idx == -1) {
        cout << "Course not found.\n";
        return false;
    }
    static vector<int> persistentCompleted;
    if ((int)persistantCompleted.size() < (int)courses.size()) {
        
    }
    
    extern vector<int> studentCompleted;
    if ((int)studentCompleted.size() < (int)courses.size())
        studentCompleted.resize(courses.size(), 0);

    vector<int> completedFlag = studentCompleted;

    vector<int> visited(courses.size(), 0);
    vector<int> recStack(courses.size(), 0);
    string failReason = "";
    bool ok = allPrereqsCompleted(idx, completedFlag, visited, recStack, failReason);

    if (!ok) {
        cout << "Cannot take " << course << ": " << failReason << "\n";
        return false;
    }

    cout << "Student1 CAN take " << course << " (all prerequisites satisfied).\n";
    return true;
}
vector<int> studentCompleted; 


bool InductionModule::markCompletedForStudent(const string& code) {
    int idx = findCourseIndex(code);
    if (idx == -1) return false;

    if ((int)studentCompleted.size() < (int)courses.size())
        studentCompleted.resize(courses.size(), 0);

    studentCompleted[idx] = 1;
    cout << "Marked " << code << " as completed for Student1.\n";
    return true;
}
void InductionModule::listCompletedCourses() {
    if ((int)studentCompleted.size() < (int)courses.size())
        studentCompleted.resize(courses.size(), 0);

    cout << "\nStudent1 Completed Courses:\n";
    int count = 0;
    for (int i = 0; i < (int)courses.size(); ++i) {
        if (studentCompleted[i]) {
            cout << "- " << courses[i].code << " (" << courses[i].name << ")\n";
            ++count;
        }
    }
    if (count == 0) cout << "No courses completed yet.\n";
}
