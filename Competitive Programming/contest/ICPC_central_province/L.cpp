#include <bits/stdc++.h>

using namespace std;

void solve(){
    string nrm = "Welcome Hue University of Sciences ";
    vector<string> words;
    string tmp = "";
    for (auto c : nrm) {
        if (c != ' ') {
            tmp += c;
        } else {
            words.push_back(tmp);
            tmp = "";
        }
    }

    map<string, bool> sav;
    while (cin >> tmp)
        sav[tmp] = true;

    bool chk = true;
    for (auto w : words)
        if (sav[w] == false) {
            // cout << "w: " << w << endl;
            chk = false;
        }

    // for (auto p : sav)
    //     cout << p.first << ' ';
    // cout << endl;

    if (chk)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}

int main(int argc, char* argv[]) {
    solve();
    return 0;
}