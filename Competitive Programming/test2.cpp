#include <iostream>
#include <vector>
#include <algorithm>

int lastOccurrenceSmallerOrEqual(const std::vector<int>& sortedVector, int k) {
    auto it = std::upper_bound(sortedVector.begin(), sortedVector.end(), k);
    
    if (it != sortedVector.begin()) {
        return std::distance(sortedVector.begin(), std::prev(it));
    }
    
    return -1; // No element found
}

int main() {
    std::vector<int> sortedVector = {8, 9, 29, 30, 10, 35, 35};
    int k = 10;  // Value to compare

    int index = lastOccurrenceSmallerOrEqual(sortedVector, k);

    if (index != -1) {
        std::cout << "Last occurrence of an element <= " << k << " is at index: " << index << std::endl;
    } else {
        std::cout << "No element <= " << k << " found." << std::endl;
    }

    return 0;
}
