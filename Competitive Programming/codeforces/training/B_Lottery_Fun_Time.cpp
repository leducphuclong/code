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
const lo first_money = 300'000;
const lo second_money = 4'000;
const lo third_money = 500;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n;   cin >> n;
    vector<string> tks(n);
    for (auto &v : tks) cin >> v;
    // Count sub strings
    map<string, lo> cnt_l6, cnt_l4, cnt_l2;
    for (auto t : tks)
        cnt_l6[t]++, cnt_l4[t.substr(2, 4)]++, cnt_l2[t.substr(4, 2)]++;

    // Find the first prize
    string fprize = "", sprize = "", thprize = "";
    lo max_fre_fprize = 0, min_ticket_discard = LLONG_MAX;
    for (auto p : cnt_l6) {
        string last6 = p.first; lo f6 = p.second;
        string last4 = last6.substr(2, 4); lo f4 = cnt_l4[last4];
        string last2 = last6.substr(4, 2); lo f2 = cnt_l2[last2];
        if (f6*first_money >= f4*second_money && f6*first_money >= f2*third_money) {
            if (f6 > max_fre_fprize || (f6 == max_fre_fprize && f2 <= min_ticket_discard))
                max_fre_fprize = f6, min_ticket_discard = f2, fprize = last6;
        }
    }
    string last2_of_first_prize = "";
    if (fprize != "")
        last2_of_first_prize = fprize.substr(4, 2);

    // Find the second prize
    // cout << "fprize: " << fprize << nln;
    // cout << "sprize: " << sprize << nln;
    lo max_fre_sprize = 0; min_ticket_discard = LLONG_MAX;
    for (auto p : cnt_l4) {
        string last4 = p.first;     lo f4 = p.second;
        string last2 = last4.substr(2, 2);      lo f2 = cnt_l2[last2];
        // cout << "l4: " << last4 << nln;
        // cout << "f4: " << f4 << nln;
        // cout << "f2: " << f2 << nln;
        if (last2 == last2_of_first_prize)  { 
            // cout << "this is for first prize..." << nln;
            continue;
        }
        if (f4*second_money >= f2*third_money) {
            if (f4 > max_fre_sprize || (f4 == max_fre_fprize && f2 <= min_ticket_discard))
                max_fre_sprize = f4, min_ticket_discard = f2, sprize = last4;
        }
        // cout << "max_fre_sprize: " << max_fre_sprize << nln;
        // cout << "min_ticket_discard: " << min_ticket_discard << nln;
        // cout << "sprize: " << sprize << nln;
    }

    string last2_of_second_prize = "";
    if (sprize != "")
        last2_of_second_prize = sprize.substr(2, 2);

    vector<lo> f3_can;

    for (auto p : cnt_l2) {
        string last2 = p.first; lo f2 = p.second;
        if (last2 == last2_of_first_prize || last2 == last2_of_second_prize)
                continue;
        f3_can.push_back(f2);
    }

    sort(f3_can.rbegin(), f3_can.rend());
    lo lmt = 3;
    lo n3 = f3_can.size();

    lo max_fre_thprize = 0;
    for (lo i = 0; i < min(lmt, n3); ++i)
        max_fre_thprize += f3_can[i];

    cout << max_fre_fprize*first_money + max_fre_sprize*second_money + max_fre_thprize*third_money << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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