#include <iostream>

using namespace std;

template<typename element_type, int SIZE>

class vector {
    private:
        element_type* data;
        unsigned int size;
    public:
        vector(element_type org);
        ~vector();
        void show();
};