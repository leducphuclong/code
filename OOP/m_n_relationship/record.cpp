#include "record.h"

record::~record() {
}

void record::view() {
    cout << "Patient ID: " << this->patientID << endl;
    cout << "Doctor ID " << this->doctorID << endl;
}
