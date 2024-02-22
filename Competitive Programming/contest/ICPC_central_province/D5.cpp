#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    int n, m, k;        cin >> n >> m >> k;

    vector<vector<int>> p;
    for (int i = 0; i < n; i++) {
        string str;         cin >> str;
        int prev = -1;
        for (int j = 0; j < m; ++j) {
            if (str[j] == 'x') {
                if (prev != -1)
                    p[i].push_back(j-prev+1);
                prev = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (auto d : p[i])
            cout << d << ' ';
        cout << endl;
    }

    return 0;
}