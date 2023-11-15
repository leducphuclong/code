#include <iostream>

using namespace std;

class point {
    public:
        int xVal, yVal;
        point(int = 1, int = 1);
        ~point();
        friend ostream& operator<<(ostream&, const point&);
        friend istream& operator>>(istream&, point&);
};