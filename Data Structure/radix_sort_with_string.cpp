// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void lowercase(string &str) {
    for (auto &c : str)
        c = tolower(c);
}

void counting_sort(vector<string> &str, int n, int position) {
    int cnt[256] = {0};
    for (auto s : str)
        cnt[tolower(s[position])]++;
    for (int i = 1; i < 256; ++i)
        cnt[i] += cnt[i-1];

    vector<string> out(n);
    for (int i = n-1; i >= 0; --i) {
        cnt[tolower(str[i][position])]--;
        out[cnt[tolower(str[i][position])]] = str[i];
    }
    str = out;
}

void solve() {
    // Input
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<string> str(n);
    for (int i = 0; i < n; ++i)
        getline(cin, str[i], ' ');
    // Radix Sort base on Counting Sort

    for (int p = m-1; p >= 0; --p)
        counting_sort(str, n, p);
    cout << "After radix sorting: ";
    for (auto s : str)
            cout << s << ' ';
        cout << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    // precompute();
    while (T--) {
        solve();
    }
    return 0;
}
