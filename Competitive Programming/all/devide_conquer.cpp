#include <iostream>
#include <vector>
#include <algorithm>

class Point {
public:
    int x, y;

    Point(int _x, int _y) : x(_x), y(_y) {}

    int quadrant() const {
        if (x >= 0 && y >= 0)
            return 1;
        if (x <= 0 && y >= 0)
            return 2;
        if (x <= 0 && y <= 0)
            return 3;
        return 4;
    }

    int crossProduct(const Point& a, const Point& b) const {
        return (a.x - x) * (b.y - y) - (b.x - x) * (a.y - y);
    }

    bool operator<(const Point& other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

int orientation(const Point& a, const Point& b, const Point& c) {
    int res = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

bool compare(const Point& p1, const Point& q1, const Point& mid) {
    Point p(p1.x - mid.x, p1.y - mid.y);
    Point q(q1.x - mid.x, q1.y - mid.y);

    int one = p.quadrant();
    int two = q.quadrant();

    if (one != two)
        return one < two;
    return p.crossProduct(q1, p1) < q.crossProduct(p1, q1);
}

std::vector<Point> merger(const std::vector<Point>& a, const std::vector<Point>& b, const Point& mid) {
    std::vector<Point> merged;

    int n1 = a.size(), n2 = b.size();
    int ia = 0, ib = 0;

    for (int i = 1; i < n1; ++i) {
        if (a[i].x > a[ia].x)
            ia = i;
    }

    for (int i = 1; i < n2; ++i) {
        if (b[i].x < b[ib].x)
            ib = i;
    }

    int inda = ia, indb = ib;
    bool done = false;
    while (!done) {
        done = true;
        while (orientation(b[indb], a[inda], a[(inda + 1) % n1]) >= 0)
            inda = (inda + 1) % n1;

        while (orientation(a[inda], b[indb], b[(n2 + indb - 1) % n2]) <= 0) {
            indb = (n2 + indb - 1) % n2;
            done = false;
        }
    }

    int uppera = inda, upperb = indb;
    inda = ia, indb = ib;
    done = false;

    while (!done) {
        done = true;
        while (orientation(a[inda], b[indb], b[(indb + 1) % n2]) >= 0)
            indb = (indb + 1) % n2;

        while (orientation(b[indb], a[inda], a[(n1 + inda - 1) % n1]) <= 0) {
            inda = (n1 + inda - 1) % n1;
            done = false;
        }
    }

    int lowera = inda, lowerb = indb;

    int ind = uppera;
    merged.push_back(a[uppera]);
    while (ind != lowera) {
        ind = (ind + 1) % n1;
        merged.push_back(a[ind]);
    }

    ind = lowerb;
    merged.push_back(b[lowerb]);
    while (ind != upperb) {
        ind = (ind + 1) % n2;
        merged.push_back(b[ind]);
    }

    return merged;
}

std::vector<Point> bruteHull(std::vector<Point> points) {
    std::vector<Point> hull;

    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            int x1 = points[i].x, x2 = points[j].x;
            int y1 = points[i].y, y2 = points[j].y;

            int a1 = y1 -It seems that the code you provided is incomplete. Could you please provide the remaining part of the code so that I can assist you further?