#include <iostream>
#include "point.h" // when include here, we don't neen to
// compile the point.cpp in the command line

using namespace std;

int main(int argc, char* argv[]) {
    point p;
    p.view_coordinates();
    p++;
    p.view_coordinates();

    return 0;
}