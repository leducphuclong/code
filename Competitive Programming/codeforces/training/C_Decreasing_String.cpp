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

lo sum_sequence(lo l, lo r, lo s) {
    return (r+l)*((r-l)/s+1)/2;
}

string getString(string input, int k) {
    stack<char> resultStack;

    for (char c : input) {
        while (!resultStack.empty() && k > 0 && resultStack.top() > c) {
            resultStack.pop();
            k--;
        }
        resultStack.push(c);
    }

    while (k > 0 && !resultStack.empty()) {
        resultStack.pop();
        k--;
    }

    string resultString = "";
    while (!resultStack.empty()) {
        resultString = resultStack.top() + resultString;
        resultStack.pop();
    }

    return resultString;
}

void solve() {
    string str; cin >> str;
    lo pos; cin >> pos;

    // str = "afdecb"; pos = 20;
    lo n = str.size();
    pos--; int d;
    for (d = 0; d < n; ++d) {
        if (pos < n-d)
            break;
        pos -= (n-d);
    }

    // cout << "d: " << d << nln;
    // cout << "pos: " << pos << nln;
    // cout << "str: " << str << nln;

    string ans;
    for (auto c : str) {
        while (d > 0 && !ans.empty() && ans.back() > c) {
            ans.pop_back();
            d--;
        }
        ans.push_back(c);
    }
    while (d > 0 && !ans.empty()) {
        ans.pop_back();
        d--;
    }

    cout << ans[pos];
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
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