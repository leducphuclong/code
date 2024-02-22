#include "students.h"

students::students() {
    this->list = nullptr;
    this->count = 0;
}

students::~students() {
    delete this->list;
    this->count = 0;
}

ostream& operator<<(ostream& os, const students& ss) {
    os << "Here are the list of students: " << endl;
    for (int i = 0; i < ss.count; ++i)
        os << *(ss.list+i) << endl;
    return os;
}

student& students::operator[](const int& index) {
    return this->list[index];   
}

void students::add(const student& s) {
    student* tmp_list = new student[this->count+1];

    for (int i = 0; i < this->count; ++i)
        tmp_list[i] = this->list[i];
    tmp_list[this->count] = s;

    this->list = tmp_list;
    this->count++;
}

void students::replace(student& s, const int& index) {
    this->list[index] = s;
}

int students::indexOf(const student& s) {
    for (int i = 0; i < this->count; ++i)
        if (this->list[i] == s)
            return i;
    return -1;
}

void students::remove(const student& s) {
    for (int i = 0; i < this->count; ++i)
        if (this->list[i] == s) {
            for (int j = count-2; j >= i; j--)
                this->list[j] = this->list[j+1];
            break;
        }
    this->count--;
}

void students::removeAt(const int& index) {
    for (int i = count-2; i >= index; i--)
        this->list[i] = this->list[i+1];
    this->count--;
}

void students::update(const int& index) {
    cout << "Update the student at index: " << index << endl;
    cin >> this->list[index];
}