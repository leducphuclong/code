#include <iostream>

using namespace std;

class point
{
protected:
public:
    int xVal, yVal;
    point(int = 0, int = 0);
    ~point();
    virtual void show();
};


