// Le Duc Phuc Long, 2024
#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

vector<ll> countingSort(vector<ll>& arr, ll exp) {	
	ll n = arr.size();
	vector<ll> cnt(10);
	for (const auto &v : arr)
		cnt[v/exp%10]++;


	vector<ll> prefixSum(10);
	prefixSum[0] = cnt[0];
	for (ll i = 1; i < 10; ++i)
		prefixSum[i] = prefixSum[i-1] + cnt[i];


	vector<ll> sortedArr(n);
	reverse(arr.begin(), arr.end());
	for (const auto& v : arr)
		sortedArr[prefixSum[v/exp%10]-1] = v,
		prefixSum[v/exp%10]--;
	return sortedArr;
}

vector<ll> radixSort(const vector<ll>& arr) {
	const ll M = *max_element(arr.begin(), arr.end());
	vector<ll> sortedArr = arr;
	for (ll exp = 1; exp <= M; exp *= 10)
		sortedArr = countingSort(sortedArr, exp);
	return sortedArr;
}

int main(int argc, char const *argv[])
{
	cin.tie(0)->sync_with_stdio(0);
	ll n;	cin >> n;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;

	vector<ll> sortedArr = radixSort(arr);
	for (auto v : sortedArr)
		cout << v << ' ';
	cout << nln;

	return 0;
}