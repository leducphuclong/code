#include "SV.h"

class SVCNTT: public SV {
    private:
        string LT;
    public:
    SVCNTT(string = "102...", string = "Long 6 mui", bool = true, double = 0.0, string = "Gioi");
    ~SVCNTT();
    void LapTrinh();
    friend ostream& operator<<(ostream&, const SVCNTT&);
    void Show();
    const SVCNTT& operator=(const SVCNTT&);
    bool operator==(const SVCNTT&);
};