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
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;
    cin >> n;
    bool reading_input = 1, erased = 0;
    lo suspected_type = 0, ans = 0;
    map<lo, lo> prev_status;
    vector<lo> erase_list;
    for (lo time = 0; time < 5; ++time) {
        // cout << "suspected_type: " << suspected_type << nln;
        map<lo, lo> current_status;
        vector<lo> arr(n);
        for (lo i = 0; i < n; ++i) {
            lo x;   cin >> x;   arr[i] = x;
            if (suspected_type != 0) {
                if (x != suspected_type) {
                    // cout << x << " != " << suspected_type << nln;
                    ans = i+1;
                }
            }
            current_status[x]++;
        }
        if (n == 1) {
            cout << "! " << arr[0] << endl;
            return;
        }
        if (ans) {
            cout << "! " << ans << endl;
            return;
        }
        if (reading_input) {
            reading_input = 0;
            prev_status = current_status;
            cout << "- 0" << endl;
            continue;
        }
        suspected_type = 0;
        for (auto e : current_status) {
            if (e.second > prev_status[e.first]) {
                cout << "hi" << nln;
                suspected_type = e.first;
                break;
            }
        }
        prev_status = current_status;
        if (erased && suspected_type) {
            for (lo i = 0; i < n; ++i)
                if (arr[i] == suspected_type) {
                    cout << "! " << i+1 << endl;
                    return;
                }
        }
        if (suspected_type != 0) {
            for (lo i = 0; i < n; ++i)
                if (arr[i] != suspected_type)
                    erase_list.push_back(i);
            n -= erase_list.size();
        }

        if (!erase_list.empty())
            erased = 1;
        cout << "- " << erase_list.size() << ' ';
        for (auto v : erase_list)
            cout << v+1 << ' ';
        cout << endl;
        erase_list.clear();
    }
}

int main(int argc, char* argv[]) {
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
