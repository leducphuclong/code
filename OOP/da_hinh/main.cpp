#include "point3d.h"
#include "point4d.h"

int main(int argc, const char* argv[]) {
    point3d A(8, 9, 10);
    A.show3d(); 
    point4d B;
    B.show();
    return 0;
}