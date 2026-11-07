#include "StudentGroupModule.h"

bool StudentGroupModule::addStudent(string name) {
    students.push_back(Student(name));
    return true;
}

void StudentGroupModule::printAllStudents() {
    cout << "\nStudents List:\n";
    for (int i = 0; i < students.size(); i++)
        cout << i + 1 << ". " << students[i].name << endl;
}

void StudentGroupModule::generateCombinations(int start, int groupSize,
    vector<string>& current,
    vector<vector<string>>& result)
{
    if (current.size() == groupSize) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < students.size(); i++) {
        current.push_back(students[i].name);
        generateCombinations(i + 1, groupSize, current, result);
        current.pop_back();
    }
}

void StudentGroupModule::formGroups(int groupSize) {
    if (groupSize <= 0 || groupSize > students.size()) {
        cout << "Invalid group size!\n";
        return;
    }

    vector<string> current;
    vector<vector<string>> result;

    generateCombinations(0, groupSize, current, result);

    cout << "\nTotal " << result.size() << " groups formed:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << i + 1 << ". ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << " | ";
        }
        cout << endl;
    }
}
