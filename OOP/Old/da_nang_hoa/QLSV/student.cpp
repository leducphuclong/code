#include "student.h"

student:: student(int id, bool gender, double scrore) {
    this->id = id;
    this->gender = gender;
    this->score = scrore;
    this->next = NULL;
}

student::~student() {
}

ostream& operator<<(ostream& o, const student& s) {
    o << "This is the information of the student have ID: " << s.id << endl;
    o << "Gender: " << s.gender << endl;
    o << "Score: " << s.score << endl;
    return o;
}

istream& operator>>(istream& i, student& s) {
    cout << "Enter the information of the student" << endl;
    cout << "ID: ";
    i >> s.id;
    cout << "Gender: ";
    i >> s.gender;
    cout << "Score: ";
    i >> s.score;
    return i;
}

bool student::operator==(const student& s) {
    return this->id == s.id;
}