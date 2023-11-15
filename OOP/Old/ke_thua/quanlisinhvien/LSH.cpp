#include "LSH.h"

LSH::LSH(string m, int k): MaLSH(m), Khoa(k) {
    cout << "Constructing LSH" << endl;
}

LSH::~LSH() {
    cout << "Destroying LSH" << endl;
}

void LSH::ShowLSH() {
    cout << this->MaLSH << ", " << this->Khoa << endl;
}

void LSH::Show() {
    cout << "LSH" << endl;
}
