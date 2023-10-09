#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    int tc;
    cin >> tc;
    while (tc--) {
        string order;   cin >> order;
        map<char, int> idx;
        int len = order.size();
        for (int i = 0; i < len; i++)
            idx[order[i]] = i;
        
        int n; cin >> n;
        vector<string> s(n);
        for (auto &v : s)
            cin >> v;
        
        auto compare = [&] (const string &s1, const string &s2) {
            int len = min(s1.size(), s2.size());
            for (int i = 0; i < len; i++)
                if (idx[s1[i]] != idx[s2[i]])
                    return idx[s1[i]] < idx[s2[i]];
            return s1.size() <= s2.size();
        };

        sort(s.begin(), s.end(), compare);

        for (auto v : s)
            cout << v << '\n';
    }
    return 0;
}