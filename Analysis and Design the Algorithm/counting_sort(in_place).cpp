#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define nln '\n'
typedef long long ll;

vector<ll> countingSort(vector<ll>& arr) {
    ll n = arr.size();
    const ll m = *max_element(arr.begin(), arr.end());
    const ll mn = *min_element(arr.begin(), arr.end());
    vector<ll> cnt(m + 1, 0);
    // Count the occurrences of each element
    for (const auto& v : arr)
        cnt[v]++;
    // Update the array with sorted elements in-place
    ll idx = 0;  // Index to iterate through the original array
    for (ll i = m; i >= mn; --i) {
        while (cnt[i] > 0) {
            arr[idx++] = i;
            cnt[i]--;
        }
    }
    return arr;  // Optional: Returning the rearranged array (same reference as input array)
}


int main(int argc, char const *argv[])
{
    // Opening input file
    if (access("in", F_OK) != -1) {
        FILE *file = freopen("in", "r", stdin);
        if (file == NULL) {
            perror("Error opening file!");
            return 1;
        }
    }

    cin.tie(0)->sync_with_stdio(0);
    ll n;  cin >> n;
    vector<ll> arr(n);
    for (auto &v : arr)
        cin >> v;

    vector<ll> sortedArr = countingSort(arr);
    for (const auto& v : sortedArr)
        cout << v << ' ';
    cout << nln;

    return 0;
}
