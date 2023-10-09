#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    Point p1, p2(11, 3), p3(p2);
    p1.Show();
    p2.Show();
    p3.Show();
    p3.TT(1);
    p3.Show();

    p3.Set_xVal(p2.Get_xVal());
    p3.Show();
    ChangePoint(p1);
    p1.Show();

    //-----------------
    Point *p = new Point(4, 5, 6);
    p->Print_Counters();
    Point::Print_Counters();
    // p.Print_Counters();
    delete p;
    p1.Print_Counters();
    return 0;
}