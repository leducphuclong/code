#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    int n, m, k;        cin >> n >> m >> k;
    vector<vector<int>> p;
    for (int i = 0; i < n; i++) {
        string str;         cin >> str;
        bool ifound = false;
        vector<int> tmp;
        for (int j = 0; j < m; ++j) {
                if(str[j] == 'x'){
                    tmp.push_back(j);
                    ifound = true;
                }
                if(str[j] == '#' && ifound == true){
                    p.push_back(tmp);
                    ifound = false;
                }
            }
            if(ifound)
            p.push_back(tmp);
        
    }

    
    auto check = [&](int v) {
        int t = 0;
        for (auto d : p){
            int pos = d[0];
            int cnt = 1;
            for(int i = 1; i < d.size(); ++i){
                if(pos + 2*v + 1 <= d[i]){
                    pos = d[i];
                    ++cnt;
                }
                else{
                    for(int j = i; j < d.size(); ++j){
                        if(d[j] > pos){
                            pos = d[j];
                            break;
                        }
                    }
                }
                if(pos > d[d.size() - 1])break;
            }
            t = t + cnt;
        }
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