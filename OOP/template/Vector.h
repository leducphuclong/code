#include <iostream>

using namespace std;

template<typename T>

class Vector {
    private: 
        T* data;
        int size;
    public:
        Vector();
        Vector(int = 5);
        ~Vector();
        template<typename K>
        friend ostream& operator<< (ostream&, const Vector<K> &);
};