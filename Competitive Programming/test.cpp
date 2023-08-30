#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    set<pair<int,int>> st; //value- index
    st.insert({0, -1});
    int best = -1e9;
    for (int i = 0; i < n; ++i) {
        int l = i - k;
    }
    return 0;
}
/*
    (l, r) opt
    (l, r+1), L <= r+1-l+1 <= R
    if length(l, r+1) < L: do nothing
    elif length(l, r+1) > R:
        while (length(l, r+1) > R) {
            remove l -> inc(l)
            l' : L <= length(l', r+1) <= R, find l' max <=> length(l', r+1) = L
        }
    now: length(after l, r + 1) = R
    find l', length(l', r+1) = L
    length(l, l') = R - L + 1
    set length <= R - L + 1
    min A[l, l'], sum(r+1) - sum(x), x (l, l')
*/