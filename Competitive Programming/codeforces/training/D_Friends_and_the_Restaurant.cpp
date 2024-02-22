// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;   cin >> n;
    lo x[n], y[n];
    for (lo i = 0; i < n; ++i)
        cin >> x[i];
    for (lo i = 0; i < n; ++i)
        cin >> y[i];
    
    vector<lo> arr;
    for (lo i = 0; i < n; ++i)
        arr.push_back(y[i]-x[i]);
    
    // We we pair all people can't go alone with another person
    // First, put all people can't go alone to vector 'a' (arr[i] < 0)
    // And other can go alone to a vector 'b'

    vector<lo> a, b;
    for (auto v : arr)
        if (v >= 0)
            b.push_back(v);
        else
            a.push_back(v);
    
    // Sort these two vector and use pointer technique 
    // to pair for people can't go alone

    sort(a.begin(), a.end()); // this is a increasing order negative list
    sort(b.rbegin(), b.rend()); // this is a decreasing order positive list

    lo ans = 0;
    vector<lo> l_a, l_b; // The people wasn't paired yet
    while (!a.empty() && !b.empty()) {
        if (abs(a.back()) <= b.back()) {
            a.pop_back();
            ans++;
        } else {
            l_b.push_back(b.back());
        }
        b.pop_back();
    }
    ans += (l_b.size()+b.size())/2; // The people can go alone left
                        // we make a group of 2 and cometo restaurant
                        // we don't need people left in vector a
                        // cuz we already have enought 2 people
                        // and it is optimal too.
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}