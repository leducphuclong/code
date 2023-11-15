#include "SVCNTT.h"

int main(int argc, char **argv) {
    SV s1("102", "NVA", true, 1.1);
    SV s11("102", "NVB", false, 2.1);
    SVCNTT s2("10213", "NVD", false, 0.1, "Khong OK");
    SVCNTT s22("101", "NVD", false, 0.1, "OK");

    // cout << ((s1 == s11) ? "True" : "False") << endl;

    // cout << ((s2 == s22) ? "True" : "False") << endl;

    s22 = s2;
    cout << s22 << endl;

    return 0;
}