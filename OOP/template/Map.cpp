#include "Map.h"

template<typename T, typename U, template<typename K> class V>
Map<T, U, V>::Map() {
    std::cout << "Map constructed !!" << std::endl;
}

template<typename T, typename U, template<typename K> class V>
Map<T, U, V>::~Map() {
    std::cout << "Map destructor !!" << std::endl;
}

// Explicit instantiation for the template class
template class Map<int, int, Vector>;
template class Map<int, double, Vector>;

template<typename T, typename U, template<typename K> class V>
std::ostream& operator<<(std::ostream& o, const Map<T, U, V>& m) {
    o << m.keys;
    o << m.values;
    return o;
}