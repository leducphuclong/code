#include "record.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    patient* p1 = new patient("1231", "Long");
    patient* p2 = new patient("1232", "Long2");

    doctor* d1 = new doctor("3131", "D1");
    doctor* d2 = new doctor("3132", "D2");


    return 0;
}
