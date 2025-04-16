#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int marks;
};

bool compare(Student a, Student b) {
    return a.marks > b.marks;  // Higher marks first
}

int main() {
    vector<Student> students = {{"Alice", 85}, {"Bob", 92}, {"Charlie", 78}};

    sort(students.begin(), students.end(), compare);

    for (auto s : students) {
        cout << s.name << " " << s.marks << endl;
    }

    return 0;
}
