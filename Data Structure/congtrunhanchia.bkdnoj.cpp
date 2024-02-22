// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void precompute() {
}

bool is_sign(string str) {
    string sign = "+-*/";
    return sign.find(str) != string::npos;
}

bool priority(string str) {
    return str == "*" || str == "/";
}

lo string2num(string str) {
    lo exp = 1, num = 0;
    for (lo i = str.length()-1; i >= 0; --i)
        num += (str[i]-'0')*exp, exp *= 10;
    return num;
}

void solve() {
    // Convert from infix to postfix
    stack<string> sign;
    vector<string> post_fix;
    string str;
    while (cin >> str) {
        if (!is_sign(str)) {
            post_fix.push_back(str);
        } else {
            while (!sign.empty() && priority(sign.top())) {
                post_fix.push_back(sign.top());
                sign.pop();
            }
            sign.push(str);
        }
    }
    post_fix.pop_back();
    while (!sign.empty()) {
        post_fix.push_back(sign.top());
        sign.pop();
    }
    // Calculate base on postfix
    stack<lo> res;
    for (auto str : post_fix)
        if (!is_sign(str)) {
            res.push(string2num(str));
        } else {
            lo y = res.top(); res.pop();
            lo x = res.top(); res.pop();
            if (str == "+")
                res.push(x+y);
            if (str == "-")
                res.push(x-y);
            if (str == "*")
                res.push(x*y);
            if (str == "/")
                res.push(x/y);
        }
    cout << res.top() << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
