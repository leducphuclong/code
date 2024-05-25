#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

class Solution {
    map<char, string> phone_key;

public:
    void recurs(vector<string> &sav, string digits, int idx, string cur) {
        if (idx == digits.size()) {
            if (cur.empty() == false)
                sav.push_back(cur);
            return;
        }
        for (auto c : phone_key[digits[idx]])
            recurs(sav, digits, idx+1, cur + c);
    }

    vector<string> letterCombinations(string digits) {
        phone_key['2'] = "abc", phone_key['3'] = "def",
        phone_key['4'] = "ghi", phone_key['5'] = "jkl",
        phone_key['6'] = "mno", phone_key['7'] = "pqrs",
        phone_key['8'] = "tuv", phone_key['9'] = "wxyz";
        vector<string> sav;
        recurs(sav, digits, 0, "");
        return sav;
    }

    void show(vector<string> result) {
        for (auto s : result) {
                for (auto c : s)
                    cout << c;
                cout << nln;
            }
    }

    vector<string> letterCombinations2(string digits) {
        phone_key['2'] = "abc", phone_key['3'] = "def",
        phone_key['4'] = "ghi", phone_key['5'] = "jkl",
        phone_key['6'] = "mno", phone_key['7'] = "pqrs",
        phone_key['8'] = "tuv", phone_key['9'] = "wxyz";
        int n = digits.size();
        vector<string> result = {string(n, '\0')};

        for (int i = 0; i < n; ++i) {
            int m = result.size();
            string& chars = phone_key[digits[i]];
            for (int k = 1; k < chars.size(); ++k)
                for (int j = 0; j < m; ++j)
                    result.push_back(result[j]);

            show(result);
            cout << nln;
            // break;
            for (int k = 0; k < chars.size(); ++k) {
                for (int j = 0; j < m; ++j)
                    result[k*m + j][i] = chars[k];
            }

            show(result);
            cout << nln;
            cout << "--------------------------------" << nln;
        }
        cout << "size: " << result.size() << nln;

        return result;
    }
};

int main() {
    string dgt; cin >> dgt;
    Solution doing;
    vector<string> res;
    // for (auto str : res)
    //     cout << str << nln;
    // cout << nln;

    res = doing.letterCombinations2(dgt);
    for (auto str : res)
        cout << str << nln;
    cout << nln;

    return 0;
}