#include "SVCNTT.h"

SVCNTT::SVCNTT(string MSSV, string Name, bool Gender, double DTB, string LT):
SV(MSSV, Name, Gender, DTB), LT(LT) {
    cout << "Constructing SVCNT" << endl;
}

SVCNTT::~SVCNTT() {
    cout << "Destroying SVCNT" << endl;
}

void SVCNTT::LapTrinh() {
    cout << "Lap trinh: " << this->LT << endl;
}

void SVCNTT::Show() {
    SV::show();
    cout << "Lap trinh: " << this->LT << endl;
}

ostream& operator<<(ostream& o, const SVCNTT& s) {
    o << SV(s) << "LT " << s.LT << endl;
    return o;
}

const SVCNTT& SVCNTT::operator=(const SVCNTT& s) {
    SV::operator=(s);
    this->LT = s.LT;
    return *this;
}

bool SVCNTT::operator==(const SVCNTT& s) {
    return s.MSSV == this->MSSV && s.gender == this->gender;
}
