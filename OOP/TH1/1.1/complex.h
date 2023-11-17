// Le Duc Phuc Long
// 22T_Nhat1
// Nhom99

#include <iostream>

using namespace std;

class complex {
    private:
    double realPart, imagPart;
    void setComplexNumber(double real, double imag) {
        this->realPart = real;
        this->imagPart = imag;
    }
    void add_real(const complex&);
    void add_image(const complex&);
    void sub_real(const complex&);
    void sub_image(const complex&);
    public:
    complex(double real = 0, double imag = 0);
    ~complex();
    friend ostream& operator<<(ostream& , const complex&);
    friend complex operator+(const complex&, const complex&);
    friend complex operator-(const complex&, const complex&);
};