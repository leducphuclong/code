#include <iostream>

using namespace std;

class SV {
    protected:
        string MSSV, name;
        bool gender;
        double dtb;
    public:
        SV(string = "1022xxx", string = "Long Dep Trai", bool = true, double = 4.0);
        ~SV();
        friend ostream& operator<<(ostream&, const SV&);
        virtual void show();
        const SV& operator=(const SV&);
        virtual bool operator==(const SV&);
};