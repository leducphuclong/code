#include <iostream>
#include <cstring>


using namespace std;

#define nln '\n'

const int N = 10+5;
bool is_prime[N];
// Neu is_prime[i] == true thi i la so nguyen to
// Nguoc lai, i khong phai la so nguyen to


void sieve() {
    memset(is_prime, true, sizeof is_prime);

    is_prime[1] = false;
    for (int i = 2; i*i < N; ++i) {
        if (is_prime[i] == true) {
            for (int j = i*i; j < N; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    sieve();
    for (int i = 0; i < N; ++i)
        if (is_prime[i] == true)
            cout << i << ' ';
    cout << endl;

    return 0;
}
