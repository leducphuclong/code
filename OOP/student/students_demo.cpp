#include "students.h"

int main(int argc, char** argv) {
    students ss;

    ss.add(student(1, 0, 3));
    ss.add(student(2, 0, 4));
    ss.add(student(3, 1, 5));

    cout << "Original Information: " << endl;
    cout << ss << endl;

    cout << "The student has index 1: " << endl;
    cout << ss[1] << endl;

    student tmp(4, 0, 6);

    cout << "After the student has index 1 replaced: " << endl;
    ss.replace(tmp, 1);
    cout << ss[1] << endl;

    ss.remove(tmp);
    cout << "After remove the temporary student: " << endl;
    cout << ss << endl;

    ss.remove(1);
    cout << "After remove the student has index 1: " << endl;
    cout << ss << endl;

    return 0;
}