#include <iostream>

using namespace std;

template<typename T, typename U, template<typename K> class V>

class Map {
    private:
        V<T> keys;
        V<U> values;
    public:
        Map();
        ~Map();
        template<typename T1, typename U1, template<typename K1> class V1>
        friend ostream& operator<<(ostream&, const Map<T1, U1, V1>&);
};
