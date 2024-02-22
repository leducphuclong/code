#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int arr[] = {7, 12, 14, 16};
    int n = (sizeof arr) / (sizeof (int));
    int ss[1 << n]; memset(ss, 0, sizeof ss);
    for (int x = 0; x < (1 << n); ++x) {
        ss[x] = arr[0];
        for (int i = x; i >= 1; i = (i-1)&x)
                ss[x] += arr[i];
    }

    for (int x = 0; x < n; ++x)
        cout << ss[x] << ' ';
    cout << endl;
    return 0;
}