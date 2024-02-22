#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    int n, m, k;        cin >> n >> m >> k;
    vector<int> p;
    
    for (int i = 0; i < n; i++) {
        string str;         cin >> str;
        bool first = false;
        int pos_first = -1, pos_last = -1;
        
        for (int j = 0; j < m; ++j) {
            if (str[j] == 'x' && first == false) {
                first = true;
                pos_first = j;
            }
            if (str[j] == 'x')
                pos_last = j;
            
            if (str[j] == '#') {
                if (pos_last != -1)
                    p.push_back(pos_last - pos_first + 1);
                first = false;
                pos_last = -1;
            }
        }

        if (pos_last != -1)
            p.push_back(pos_last - pos_first + 1);
    }

    auto check = [&](int v) {
        int t = 0;
        for (auto d : p)
            t += ceil((double)d / (2*v + 1));
        
        return t <= k;
    };

    int low = 0, hight = 1e5, ans = -1;
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