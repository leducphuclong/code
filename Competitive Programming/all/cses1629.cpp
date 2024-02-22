#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef int64_t lo;
#define nln '\n'

bool compare(pair<lo, lo> left, pair<lo, lo> right) {
    if (left.second == right.second)
        return left.first < right.first;
    return left.second < right.second;
}

int main() {
    lo n;
    cin >> n;
    pair<lo, lo> arr[n];
    for (lo i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n, compare);

    vector<pair<lo, lo>> movies = {make_pair(arr[0].first, arr[0].second)};
    for (lo i = 1; i < n; ++i)
        if (movies.back().second <= arr[i].first)
            movies.push_back(make_pair(arr[i].first, arr[i].second));

    cout << movies.size() << nln;

    return 0;
}