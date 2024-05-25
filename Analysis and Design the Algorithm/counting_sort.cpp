// Le Duc Phuc Long, 2024
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define nln '\n'
typedef long long ll;

vector<ll> countingSort(const vector<ll>& arr) {	
	ll n = arr.size();
	const ll M = *max_element(arr.begin(), arr.end());
	vector<ll> cnt(M+1);
	for (const auto &v : arr)
		cnt[v]++;

	vector<ll> prefixSum(M+1);
	prefixSum[0] = cnt[0];
	for (ll i = 1; i <= M; ++i)
		prefixSum[i] = prefixSum[i-1] + cnt[i];


	vector<ll> sortedArr(n);
	for (const auto& v : arr)
		sortedArr[prefixSum[v]-1] = v,
		prefixSum[v]--;
	return sortedArr;
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
	ll n;	cin >> n;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;

	vector<ll> sortedArr = countingSort(arr);
	for (const auto& v : sortedArr)
		cout << v << ' ';
	cout << nln;

	return 0;
}