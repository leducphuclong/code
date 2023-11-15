#include "HP.h"

HP::HP(string m, int sl): MaHP(m), SL(sl) {
    cout << "Constructing HP" << endl;
}

HP::~HP() {
    cout << "Destroying HP" << endl;
}

void HP::ShowHP() {
    cout << this->MaHP << ", " << this->SL << endl;
}

void HP::Show() {
    cout << "HP" << endl;
}