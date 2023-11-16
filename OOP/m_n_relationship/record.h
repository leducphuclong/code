#include "patient.h"
#include "doctor.h"

using namespace std;

class record {
    private:
        string recordID, patientID, doctorID;
    public:
        record(string id = "Unknown", string patientID = "Unknown", string doctorID = "Unknown"):
        recordID(id), patientID(patientID), doctorID(doctorID) {}
        ~record();
        void view();
};

