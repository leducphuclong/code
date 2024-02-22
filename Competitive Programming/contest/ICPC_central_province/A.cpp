#include <bits/stdc++.h>

class SegmentTree {
private:
    std::vector<int> sequence;
    std::vector<int> tree;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = sequence[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;
            build(leftChild, start, mid);
            build(rightChild, mid + 1, end);
            tree[node] = std::max(tree[leftChild], tree[rightChild]);
        }
    }

    int query(int node, int start, int end, int queryStart, int queryEnd) {
        if (start > queryEnd || end < queryStart) {
            return std::numeric_limits<int>::min();
        }
        if (queryStart <= start && end <= queryEnd) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        int leftMax = query(leftChild, start, mid, queryStart, queryEnd);
        int rightMax = query(rightChild, mid + 1, end, queryStart, queryEnd);
        return std::max(leftMax, rightMax);
    }

public:
    SegmentTree(const std::vector<int>& inputSequence) {
        sequence = inputSequence;
        tree.resize(4 * sequence.size());
        build(1, 0, sequence.size() - 1);
    }

    int findMax(int queryStart, int queryEnd) {
        if (queryStart < 0 || queryEnd >= sequence.size() || queryStart > queryEnd) {
            throw std::invalid_argument("Invalid query range");
        }
        return query(1, 0, sequence.size() - 1, queryStart, queryEnd);
    }
};