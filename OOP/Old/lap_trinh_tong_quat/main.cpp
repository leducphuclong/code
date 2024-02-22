#include "point.h"
#include "vector.cpp"

int main(int argc, char **argv) {
    vector<point, 3> v(point(11, 12));
    v.show();
    return 0;
}