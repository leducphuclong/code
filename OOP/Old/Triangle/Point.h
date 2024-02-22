#include <iostream>

class Point {
    // Private
        double xVal, yVal;
        static int n;
    public: 
        Point(double = 10 , double = 10);
        ~Point();
        void Show();
        friend Point operator+(const Point& p1, const Point& p2);
        Point operator-(const Point& p2);
        friend ostream& operator<<(ostream&, const Point&);
        friend istream& operator>>(ostream&, Point&);
};
