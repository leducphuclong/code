#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    int n, m, k;        cin >> n >> m >> k;

    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        string str;         cin >> str;
        int prev = -1, cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (str[j] == 'x') {
                ++cnt;
                if (prev != -1)
                    p[i].push_back(j-prev+1);
                prev = j;
            }
        }
        if (cnt == 1)
            p[i].push_back(1);
    }

    // for (int i = 0; i < n; ++i) {
    //     for (auto d : p[i])
    //         cout << d << ' ';
    //     cout << endl;
    // }
    // cout << endl;

    auto check = [&] (int v) {
        int boom = k;
        for (auto d : p) {
            while (!d.empty()) {
                if (boom == 0)
                    return false;
                if (d.size() == 1) {
                    boom--;
                    d.pop_back();
                    continue;
                }
                int p1 = d.back();  d.pop_back();
                int p2 = d.back();  d.pop_back();
                if ((p1-p2+1) <= 2*v +1) {
                    boom--;
                } else {
                    if (boom >= 2) {
                        boom -= 2;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    cout << check(0) << endl;


    int low = 0, hight = 1e5, ans = -1;
    while (low <= hight) {
        int guess = (low+hight) >> 1;
        if (check(guess))
            hight = guess-1, ans = guess;
        else
            low = guess+1;
        // cout << "hight: " << hight << endl;
    }

    cout << ans << endl;

    return 0;
}