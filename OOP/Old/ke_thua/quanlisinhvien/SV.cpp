#include "SV.h"

SV::SV(string mhp, int sl, string mlsh, int k, string m): HP(mhp, sl), LSH(mlsh, k), MSSV(m) {
    cout << "Constructing SV" << endl;
}

SV::~SV() {
    cout << "Destroying SV" << endl;
}

void SV::ShowSV() {
    HP::ShowHP();
    LSH::ShowLSH();
    cout << this->MSSV << endl;
}