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
typedef int lo;

// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

bool compare(pair<lo, lo> e1, pair<lo, lo> e2) {
    return e1.second < e2.second;
}

void solve() {
    // Input
    lo n, k;
    cin >> n >> k;
    vector<lo> planks(n+1, 0);
    for (lo i = 1; i <= n; ++i)
        cin>> planks[i];
    // Solve
    map<lo, lo> prev_pos_of_color;
    map<lo, lo> max_step_of_color;
    map<lo, bool> just_one;
    for (lo i = 1; i <= n; ++i) {
        if (max_step_of_color[planks[i]] < i-prev_pos_of_color[planks[i]]) {
            max_step_of_color[planks[i]] = i-prev_pos_of_color[planks[i]];
            just_one[planks[i]] = 1;
        } else if (max_step_of_color[planks[i]] == i-prev_pos_of_color[planks[i]]) {  // NOLINT
            just_one[planks[i]] = 0;
        }
        prev_pos_of_color[planks[i]] = i;
    }

    for (lo i = 1; i <= k; ++i)
        if (max_step_of_color[i] < n-prev_pos_of_color[i]) {
            max_step_of_color[i] = n-prev_pos_of_color[i];
            just_one[i] = 1;
        } else if (max_step_of_color[i] == n-prev_pos_of_color[i]) {
            just_one[i] = 0;
        }

    auto proper_plank = min_element(max_step_of_color.begin(),
        max_step_of_color.end(), compare);

    lo color = proper_plank->first;
    lo res = proper_plank->second;
    lo prev_pos = 0;
    set<lo, greater<lo>> steps;
    map<lo, lo> cnt_lengths;
    for (lo i = 1; i <= n+1; ++i) {
        if (planks[i] == color || i == n+1) {
            steps.insert(i-prev_pos-1);
            cnt_lengths[i-prev_pos-1]++;
            prev_pos = i;
        }
    }
    if (cnt_lengths[*steps.begin()] == 1) {
        if (steps.size() == 1) {
            cout << *steps.begin()/2 << nln;
        } else {
            cout << max(*(++steps.begin()), *steps.begin()/2) << nln;
        }
    } else {
        cout << *steps.begin() << nln;
    }
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
