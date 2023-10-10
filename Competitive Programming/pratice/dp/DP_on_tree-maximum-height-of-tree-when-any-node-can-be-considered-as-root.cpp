// C++ code to find the maximum path length 
// considering any node as root 
#include <bits/stdc++.h> 

using namespace std; 

#define nln '\n'

// Global Variables
vector<int> in, out, v[100];
int n = 11; 
// End Declaration 

void dfs_in(int u, int p) {
    for (auto i : v[u])
        if (i != p) {
            dfs_in(i, u);
            in[u] = max(in[u], in[i]+1);
        }
}

void dfs_out(int u, int p) {
    // find maximum and second maximum of childs of u
    int mx1 = -1, mx2 = -1;
    for (auto i : v[u]) {
        if (i == p)
            continue;
        if (in[i] >= mx1) {
            mx2 = mx1;
            mx1 = in[i];
        } else if (in[i] > mx2) {
            mx2 = in[i];
        }
    }
    // Find the optimal way according to these mx(s);
    for (auto i : v[u]) {
        if (i == p)
            continue;
        int curr_longest_path = mx1;
        if (mx1 == in[i]) // In this case in[i] is the maximum way
            curr_longest_path = mx2;
        // we can't choose that way, so we need to change to second
        // maximum way
        out[i] = 1+max(out[u], 1+curr_longest_path);
        dfs_out(i, u);
    }
}

void conclude() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(out[i], in[i]);
        cout << "Max height of tree when " << i << "th node can be considered as Root: " << ans << nln;
    }
}

// Driver Code 
int main() 
{ 
    // initialize the tree given in the diagram 
    v[1].push_back(2), v[2].push_back(1); 
    v[1].push_back(3), v[3].push_back(1); 
    v[1].push_back(4), v[4].push_back(1); 
    v[2].push_back(5), v[5].push_back(2); 
    v[2].push_back(6), v[6].push_back(2); 
    v[3].push_back(7), v[7].push_back(3); 
    v[7].push_back(10), v[10].push_back(7); 
    v[7].push_back(11), v[11].push_back(7); 
    v[4].push_back(8), v[8].push_back(4); 
    v[4].push_back(9), v[9].push_back(4); 

    // initialise in and out vectors 
    in.resize(n+1,0); 
    out.resize(n+1,0); 
    // Find the "in" value of each  node
    dfs_in(1, 0);
    // for (int i = 1; i <= n; ++i)
    //     cout << i << ": " << in[i] << nln;
    dfs_out(1, 0);
    // for (int i = 1; i <= n; ++i)
    //     cout << i << ": " << out[i] << nln;
    conclude();
    cout << "Done..." << nln;
    return 0; 
} 
