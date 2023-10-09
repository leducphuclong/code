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
const lo N = 1e6+2;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool mark[N];   lo min_dvs[N];  // this is the minimum divisor of each number
map<lo, lo> pwr; // this is for storing the prime factors and its powers
lo cnt_dvs = 1; // number of divisors currently and originally
// End of global variable declaration.

void precompute() {
    // find the minimum divisor of all the numbers
    for (lo i = 2; i < N; i += 2)
        min_dvs[i] = 2;
    
    for (lo i = 3; i < N; i += 2) {
        if (mark[i])
            continue;
        mark[i] = true, min_dvs[i] = i;
        for (lo j = i*i; j < N; j += 2*i)
            if (mark[j] == false)
                mark[j] = true, min_dvs[j] = i;
    }
}

void factorize(lo x) {
    lo cur_fre = 0, cur_dvs = 1;
    while (x > 1) {
        if (cur_dvs == min_dvs[x]) {
            cur_fre++;
        } else {
            cnt_dvs /= (pwr[cur_dvs]+1);
            pwr[cur_dvs] += cur_fre;
            cnt_dvs *= (pwr[cur_dvs]+1);

            cur_dvs = min_dvs[x];
            cur_fre = 1;
        }
        x /= cur_dvs;
    }
    cnt_dvs /= (pwr[cur_dvs]+1);
    pwr[cur_dvs] += cur_fre;
    cnt_dvs *= (pwr[cur_dvs]+1);
}

void show_cur_fact() {
    cout << "quantity of divisors: " << cnt_dvs << nln;
    for (auto p : pwr)
        cout << p.first << '^' << p.second << nln;
    cout << nln;
}

void solve() {
    lo n, q;    cin >> n >> q;

    factorize(n); 
    // show_cur_fact();

    lo ini_cnt = cnt_dvs;
    map<lo, lo> org;
    for (auto p : pwr)
        org[p.first] = p.second;
    
    vector<lo> stg;
    while (q--) {
        lo r;   cin >> r;
        if (r == 1) {
            lo x;   cin >> x;
            factorize(x);
            // show_cur_fact();
            stg.push_back(x);
            lo rem = n;
            for (auto v : stg)
                rem *= v, rem %= cnt_dvs;
            if (!rem)
                cout << "YES" << nln;
            else
                cout << "NO" << nln;
        } else {
            cnt_dvs = ini_cnt;
            pwr.clear();
            for (auto p : org)
                pwr[p.first] = p.second;
            stg.clear();
        }
    }
    pwr.clear();
    cnt_dvs = 1;
    cout << nln;
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