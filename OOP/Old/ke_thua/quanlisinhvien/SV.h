#include "HP.h"
#include "LSH.h"

using namespace std;

class SV: public HP, public LSH {
    private:
        string MSSV;
    public:
        SV(string = "", int = 0, string = "", int = 1990, string = 0);
        ~SV();
        void ShowSV();
};