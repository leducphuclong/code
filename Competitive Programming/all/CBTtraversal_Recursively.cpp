// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

struct node {
    lo value;
    node *left, *right;
    explicit node(lo x) : value(x), left(NULL), right(NULL) {}
};

// Declare global variables.
vector<lo> nums = {1, 2, 3, 4, 5, 6, 6, 6, 6};

void precompute() {
}

node* InsertLevelOrder(vector<lo> nums, lo i) {
    if (i >= nums.size())
        return nullptr;
    node* root = new node(nums[i]);
    root->left = InsertLevelOrder(nums, 2*i+1);
    root->right = InsertLevelOrder(nums, 2*i+2);
    return root;
}

void PrintTree(node* root) {
    if (root == nullptr)
        return;
    PrintTree(root->left);
    cout << root->value << ' ';
    PrintTree(root->right);
}

void solve() {
    node *root = InsertLevelOrder(nums, 0);
    PrintTree(root);
    cout << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
  return 0;
}
