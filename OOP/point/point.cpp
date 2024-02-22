#include <iostream>
#include "point.h"

using namespace std;

point::point(int x, int y): xV(x), yV(y) {
    this->xV = x, this->yV = y;
}

point::point(const point& p) {
    this->xV = p.xV, this->yV = p.yV;
}

point::~point() {
}

void point::move_up_right(int d) {
    this->xV += d, this->yV += d;
}

void point::view_coordinates() {
    cout << "Coordinates: " << this->get_xV() << " " << this->get_yV() << endl;
}

void return_to_O(point& p) {
    p.xV = p.yV = 0;
}

int point::find_zone(const point& p) { // shared function
    if (p.xV < 0 && p.yV < 0)
        return 3;
    if (p.xV > 0 && p.yV > 0)
        return 1;
    if (p.xV < 0 && p.yV > 0)
        return 2;
    if (p.xV > 0 && p.yV < 0)
        return 4;
    return 0;
}

point operator+(const point& p1, const point& p2) {
    return point(p1.get_xV() + p2.get_xV(), p1.get_yV() + p2.get_yV());
}

point point::operator-(const point& p) {
    return point(this->xV - p.xV, this->yV - p.yV);
}

ostream& operator<<(ostream& out, const point& p) {
    out << "Coordinates: " << p.xV << " " << p.yV << endl;
    return out;
}

istream& operator>>(istream &in, point &p) {
    cout << "Enter coordinates of the point(x, y) : ";
    int x, y;   in >> x; in >> y;
    p.set_xV(x), p.set_yV(y);
    return in;
}

void point::operator=(const point& p) {
    this->set_xV(p.get_xV());
    this->set_yV(p.get_yV());
}

point point::operator++(int) {
    point temp(*this);
    this->xV++, this->yV++;
    return temp;
}

point& point::operator++() {
    this->xV++; this->yV++;
    return *this;
}

bool point::operator==(const point& p) {
    return this->xV == p.xV && this->yV == p.yV;
}