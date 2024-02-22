#include "point3d.h"

class point4d : public point3d {
    int tVal;
    public:
        explicit point4d(int = 4, int = 4, int = 4, int = 4);
        ~point4d();
        void show4d();
        void show();
};
