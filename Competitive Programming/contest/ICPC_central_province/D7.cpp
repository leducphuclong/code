#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    //frpen("in", "r", stdin);
    int n, m, k;        cin >> n >> m >> k;

    vector<vector<pair<int, char>>> p(n);
    for (int i = 0; i < n; i++) {
        string str;         cin >> str;
        for (int j = 0; j < m; ++j) {
            if (str[j] == 'x') {
                p[i].push_back({j, 'x'});
            } else if (str[j] == '#') {
                p[i].push_back({j, '#'});
            }
        }
    }

    auto check = [&] (int v) {
        int boom = k;
        for (auto d : p) {
            while (!d.empty()) {
                if (d.back().second == '#') {
                    d.pop_back();
                    continue;
                }
                if (d.size() == 1) {
                    if (d.back().second == 'x')
                        boom--;
                    if (boom < 0)
                        return false;
                    d.pop_back();
                    continue;
                }
                
                auto par1 = d.back();  d.pop_back();
                auto par2 = d.back();  d.pop_back();

                if (par1.second == '#' && par2.second == '#') {
                    continue;
                }

                if (par1.second == '#' || par2.second == '#') {
                    if (boom > 0)
                        boom--;
                    else
                        return false;
                    continue;
                }
                if ((par1.first - par2.first + 1) <= 2*v+1) {
                    if (boom > 0)
                        boom--;
                    else
                        return false;
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



    int low = 0, hight = 1e6, ans = -1;
    while (low <= hight) {
        int guess = (low+hight) >> 1;
        if (check(guess))
            hight = guess-1, ans = guess;
        else
            low = guess+1;
    }

    cout << ans << endl;

    return 0;
}