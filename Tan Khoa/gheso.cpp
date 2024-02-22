#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s, st, a = "", b = "";
    cin >> s >> st;
    sort(s.begin(), s.end());
    long long i = 0, j = 0;
    while (i < s.size() || j < st.size())
    {
        if (i == s.size())
        {
            a += st[j];
            j++;
        }
        else if (j == st.size())
        {
            a += s[i];
            i++;
        }
        else
        {
            if (s[i] < st[j])
            {
                a += s[i];
                i++;
            }
            else
            {
                a += st[j];
                j++;
            }
        }
    }

    if (a[0] == '0')
    {
        for (long long ii = 1; ii < a.size(); ii++)
        {
            if (a[ii] != '0')
            {
                swap(a[0], a[ii]);
                break;
            }
        }
    }

    sort(s.rbegin(), s.rend());
    long long i1 = 0, j1 = 0;
    while (i1 < s.size() || j1 < st.size())
    {
        if (i1 == s.size())
        {
            b += st[j1];
            j1++;
        }
        else if (j1 == st.size())
        {
            b += s[i1];
            i1++;
        }
        else
        {
            if (s[i1] <= st[j1])
            {
                b += st[j1];
                j1++;
            }
            else
            {
                b += s[i1];
                i1++;
            }
        }
    }
    cout << a << '\n'
         << b;
    return 0;
}
