#include <iostream>

using namespace std;

class point {
private:
    int xV, yV;
public:
    point(int = 0, int = 0);
    point(const point&);
    ~point();

    void move_up_right(int d);
    void view_coordinates();

    int get_xV() const { return xV; };
    int get_yV() const { return yV; };

    void set_xV(int v) { xV = v; };
    void set_yV(int v) { yV = v; };

    friend void return_to_O(point &); // we set friend function to access private members
    static int find_zone(const point &); // shared function of
    // all class type "point"

    friend point operator+(const point&, const point&);
    point operator-(const point&);

    // friend const ostream& operator<<(ostream &, const point &);
    friend ostream& operator<<(ostream & , const point &);
    friend istream& operator>>(istream &, point &);

    void operator=(const point &);
    point operator++(int); // post increment
    point& operator++(); // pre increment
    bool operator==(const point &);
};

