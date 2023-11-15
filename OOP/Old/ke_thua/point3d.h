#include "point.h"

class point3d : public point {
    protected:
        int zVal;
    public:
        point3d(int = 0, int = 0, int = 0);
        ~point3d();
        void show3d();
        void show();
};