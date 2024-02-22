#include "student.h"

student::student(int id, bool gender, double score): 
id(id), gender(gender), score(score){
}

student::~student() {
}

ostream& operator<<(ostream& os, const student& s) {
    os << "Information of student: " << endl;
    os << "ID: " << s.id << endl;
    os << "Gender: " << s.gender << endl;
    os << "Score: " << s.score << endl;
    return os;
}

istream& operator>>(istream& is, student& s) { 
    cout << "Enter information of student: " << endl;
    cout << "Enter ID: "; is >> s.id;
    cout << "Enter gender: "; is >> s.gender;
    cout << "Enter score: "; is >> s.score;
    return is;
}

bool student::operator==(const student& s) const {
    return s.gender == gender && s.id == id && s.score == score;
}