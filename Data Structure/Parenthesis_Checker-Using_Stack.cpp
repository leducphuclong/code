// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

typedef char element_type;

typedef struct node {
        element_type element;
        struct node *next;
    } *node_ptr;

typedef node_ptr stackADT;


#define nln '\n'

// Declare global variables.

class Solution {
    string str, open = "{[(", close = "}])";

 public:
    stackADT Initialize() {
        stackADT s = (stackADT)malloc(sizeof(struct node));
        s->next = NULL;
        return s;
    }

    bool IsEmpty(stackADT s) {
        return (s->next == NULL);
    }

    element_type top(stackADT s) {
        return s->next->element;
    }

    void push(stackADT s, element_type element) {
        node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
        new_node->element = element;
        new_node->next = s->next;
        s->next = new_node;
    }

    void pop(stackADT s) {
        node_ptr tmp_node = s->next;
        s->next = s->next->next;
        free(tmp_node);
    }

    void MakeNull(stackADT s) {
        s->next = NULL;
    }

    void GetString() {
        cin >> str;
    }

    bool IsOpening(char ch) {
        for (auto i : open)
            if (ch == i)
                return true;
        return false;
    }

    char CorrespondingOpen(char symbol) {
        for (int i = 0; i < 3; ++i)
            if (symbol == close[i])
                return open[i];
        return ' ';
    }

    bool ParenthesisCheck() {
        stackADT s = Initialize();
        for (const auto ch : str)
            if (IsOpening(ch)) {
                push(s, ch);
            } else {
                if (IsEmpty(s))
                    return false;
                if (top(s) == CorrespondingOpen(ch))
                    pop(s);
                else
                    return false;
            }
        return IsEmpty(s);
    }
};

void precompute() {
}

void solve() {
    Solution obj;
    obj.GetString();
    cout << ((obj.ParenthesisCheck()) ? "true" : "false") << nln;
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
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
