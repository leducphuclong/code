#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <random>
#include <cfloat>
#include <chrono>
#include <bitset>
#include <complex>
#include <immintrin.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int32_t num_tests;
    std::cin >> num_tests;

    for(int32_t t = 0; t < num_tests; t++) {
        int64_t k;
        std::cin >> k;

        std::vector<int32_t> digits;
        while(k > 0) {
            digits.push_back(k % 9);
            k /= 9;
        }
        std::reverse(digits.begin(), digits.end());
        for (auto i : digits)
            cout << i << ' ';
        cout << endl;

        for(int32_t i = 0; i < digits.size(); i++){
            // cout << "dg: " << digits[i] << endl;
            std::cout << (char)(digits[i] < 4 ? (digits[i] + '0') : (digits[i] + '1'));
        }
        std::cout << "\n";
    }
    return 0;
}