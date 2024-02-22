#include "point.h"

using namespace std;

int main(int argc, char** argv) {
    point x1;
    point x2(1), x3(2, 2);
    point x4(x3);
   
    x1.move_up_right(1);

    cout << "Coordinate of x1 should be (1, 1): " << endl;
    x1.view_coordinates();
    
    cout << "Coordinate of x2 should be (1, 0): " << endl;
    x2.view_coordinates();

    cout << "Coordinate of x3 should be (2, 2): " << endl;
    x3.view_coordinates();

    cout << "Coordinate of x4 should be (2, 2): " << endl;
    x4.view_coordinates();

    x4.set_xV(9);

    cout << "Coordinate of x4 now should be (9, 2)" << endl;
    x4.view_coordinates();

    return_to_O(x3);

    cout << "Coordinate of x3 now should be (0, 0)" << endl;
    x3.view_coordinates();

   
    x1 = x1 - x2;

    cout << "Coordinate of x1 now should be (0, 1)" << endl;
    x1.view_coordinates();

    x2 = x1 - x2;
    cout << "Coordinate of x2 now should be (-1, 1)" << endl;
    x2.view_coordinates();

    
    x4 = x3.operator-(x1);

    cout << "Coordinate of x4 now should be (0, -1)" << endl;
    x4.view_coordinates();

    x1 = x4;

    cout << "Coordinate of x1 now should be (0, -1)" << endl;
    x1.view_coordinates();

    x1++;
    cout << "Coordinate of x1 now should be (1, 0)" << endl;
    x1.view_coordinates();

    x2.operator++();
    cout << "Coordinate of x2 now should be (0, 2)" << endl;
    x2.view_coordinates();

    ++x2;
    cout << "Coordinate of x2 now should be (1, 3)" << endl;
    cout << x2 << endl;

    x1 = x2;
    cout << "this should be the value 1: " << (x1 == x2) << endl;
    cout << "This should be the value 0: " << (x1 == x3) << endl;

    point x5;
    cout << "Enter the coordinates of x5: ";
    cin >> x5;
    cout << "Entered oordinate of x5 is " << x5 << endl;

    
    cout << "DONE" << endl;
    
    return 0;
}
