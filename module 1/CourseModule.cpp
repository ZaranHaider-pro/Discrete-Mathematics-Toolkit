#include "CourseModule.h"

CourseModule::CourseModule() {}

int CourseModule::findCourseIndex(string code) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].code == code)
            return i;
    }
    return -1;
}

bool CourseModule::addCourse(string code, string name) {
    if (findCourseIndex(code) != -1) return false;

    courses.push_back(Course(code, name));
    adj.push_back(vector<int>()); 
    return true;
}

bool CourseModule::addPrerequisite(string course, string prereq) {
    int c = findCourseIndex(course);
    int p = findCourseIndex(prereq);

    if (c == -1 || p == -1) return false;

    adj[p].push_back(c); 
    return true;
}

bool CourseModule::dfsCycle(int v, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;

    for (int u : adj[v]) {
        if (!visited[u] && dfsCycle(u, visited, recStack))
            return true;
        else if (recStack[u])
            return true;
    }

    recStack[v] = false;
    return false;
}

bool CourseModule::hasCycle() {
    int n = courses.size();
    vector<bool> visited(n, false), recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfsCycle(i, visited, recStack))
            return true;
    }
    return false;
}

void CourseModule::printOneValidOrder() {
    if (hasCycle()) {
        cout << "ERROR: Cycle detected in prerequisites. Cannot schedule!" << endl;
        return;
    }

    int n = courses.size();
    vector<int> indegree(n, 0);

    // compute indegree
    for (int i = 0; i < n; i++)
        for (int u : adj[i])
            indegree[u]++;

    vector<int> order;

    for (int step = 0; step < n; step++) {
        int selected = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                selected = i;
                break;
            }
        }

        if (selected == -1) break;

        order.push_back(selected);
        indegree[selected] = -1;

        for (int u : adj[selected])
            indegree[u]--;
    }

    cout << "\nValid Course Order:\n";
    for (int idx : order)
        cout << courses[idx].code << " - " << courses[idx].name << endl;
}
