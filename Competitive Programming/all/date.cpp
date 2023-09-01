// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define lo int64_t
#define nln '\n'

const lo MOD = 1e9+7;

using std::cout, std::cin, std::vector;

void dfs(lo v, vector<lo> adj[], vector<bool> &vst, vector<lo> &res){
	if (vst[v])
		return;
	vst[v] = true;
	for (auto u : adj[v])
		if (!vst[u])
			dfs(u, adj, vst, res);
	res.push_back(v);
}

vector<lo> topological_sorting(lo V, vector<lo> adj[]){
	vector<lo> res;
	vector<bool> vst(V+1, 0);
	for (lo v = 1; v <= V; ++v)
		dfs(v, adj, vst, res);
	return res;
}

void solve() {
	lo V, E;
	cin >> V >> E;

	vector<lo> adj[V+1];
	while (E--){
		lo u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<lo> topo_order = topological_sorting(V, adj), dp(V+1, 0);
	dp[1] = 1;
	while (!topo_order.empty()){
		for (auto v : adj[topo_order.back()])
			dp[v] += dp[topo_order.back()], dp[v] %= MOD;
		topo_order.pop_back();
	}
	cout << dp[V] << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
  return 0;
}
