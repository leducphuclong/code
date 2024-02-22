// Copyright (c) 5-4-2023, Le Duc Phuc Long

#include<bits/stdc++.h> // NOLINT

using namespace std; // NOLINT

typedef int64_t lo;

#define nln '\n'

vector find_cycle(lo u, lo n, vector<lo> adj[], vector<bool> vst){
    if (vst.size() == 0){
        vst.resize(n, 0);
    }
    vst[u] = 1;
    for (auto v : adj[u])
        if (!)
}

int main() {
    lo n = 5, m = 8;
    vector<lo> adj[n+1];
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[1].push_back(5);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[2].push_back(4);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(2);
    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(1);
    adj[5].push_back(4);
    return 0;
}
