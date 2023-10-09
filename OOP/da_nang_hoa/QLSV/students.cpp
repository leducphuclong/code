#include "students.h"

ostream& operator<<(ostream& o, const students& s) {
    o << "This is the information of all students: " << endl;
    for (int i = 0; i < s.quantity; ++i)
        o << *(s.address+i);
    return o;
}

void students::add(const student& s) {
    
}

student& operator[](const int& i) {
    
}