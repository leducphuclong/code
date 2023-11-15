#include <iostream>

using namespace std;

class number
{
private:
    double val;
public:
    number(double = 3.141592653589793);
    ~number();

    operator int();
    operator double();
    ostream& operator<<(ostream& stream);
};
