#include "SV.h"

SV::SV(string MSSV, string Name, bool Gender, double DTB): 
MSSV(MSSV), name(Name), gender(Gender), dtb(DTB) {
    cout << "constructing SV" << endl;
}

SV::~SV() {
    cout << "deconstructing SV" << endl;
}

ostream& operator<<(ostream& o, const SV& s) {

    o << "This student have ID: " << s.MSSV << endl;
    o << "Name: " << s.name << endl;
    o << "Gender: " << s.gender << endl;
    o << "GPA: " << s.dtb << endl;
    return o;
}

void SV::show() {
    cout << *this << endl;
}

const SV& SV::operator=(const SV& s) {
    this->MSSV = s.MSSV;
    this->name = s.name;
    this->gender = s.gender;
    this->dtb = s.dtb;
    // *this = s;
    return *this;
}

bool SV::operator==(const SV& s) {
    return this->MSSV == s.MSSV;
}