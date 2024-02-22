#include "student.h"

int main(int argc, char** argv) {
    student s1;
    cout << s1 << endl;

    student s2(1, 2, 3);
    cout << s2 << endl;

    student s3;
    cin >> s3;
    cout << s3 << endl;

    if (s3 == s2) {
        cout << "Student s3 has the same information of student s2!" << endl;
    } else {
        cout << "Student s3 don't have the same information of student s2!" << endl;
    }

    return 0;
}