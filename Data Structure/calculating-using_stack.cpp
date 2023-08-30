// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

typedef char stringADT[100];

typedef char* element_type;


typedef struct node {
    element_type element;
    struct node *next;
} *node_ptr;

typedef node_ptr stackADT;

#define nln '\n'

const int MAX_SIZE_STRING = 100;

// Declare global variables.

// void precompute() {
// }

stackADT initialize() {
    stackADT s = (stackADT)malloc(sizeof(struct node));
    s->element = static_cast<element_type>(NULL);
    s->next = NULL;
    return s;
}

bool empty(stackADT s) {
    return (s->next == NULL);
}

void push(stackADT s, element_type element) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = strdup(element);
    new_node->next = s->next;
    s->next = new_node;
}

element_type top(stackADT s) {
    if (empty(s))
        return static_cast<element_type>(NULL);
    return s->next->element;
}

void pop(stackADT s) {
    if (empty(s))
        return;
    node_ptr tmp_node = s->next;
    s->next = s->next->next;
    free(tmp_node->element);
    free(tmp_node);
}

void make_null(stackADT s) {
    s->next = NULL;
}

bool sign(element_type element) {
    string s = "+-*/";
    return s.find(element) != string::npos;
}

bool priority(element_type element) {
    return (strcmp(element, "*") == 0) || (strcmp(element, "/") == 0);
}

void print(stackADT s) {
    node_ptr itr_node = s;
    cout << "Print stack: " << nln;
    while (itr_node->next != NULL) {
        cout << "node: " << itr_node->next->element << nln;
        itr_node = itr_node->next;
    }
    cout << "-----------------" << nln;
}

lo string2num(element_type element) {
    lo num = 0, l = strlen(element), exp = 1;
    for (lo i = l-1; i >= 0; --i)
        num += (element[i]-'0')*exp, exp *= 10;
    return num;
}

element_type str2charStr(string str) {
    char *charStr = (char*)malloc(sizeof(char)*str.length()+1);
    strcpy(charStr, str.c_str());
    return charStr;
}

element_type num2string(lo num) {
    string element = to_string(num);
    return str2charStr(element);
}

void solve() {
    stackADT s = initialize();

    char element[MAX_SIZE_STRING];

    vector<string> post_fix;

    while (cin.getline(element, MAX_SIZE_STRING)) {
        // cout << element << ' ';
        if (!sign(element)) {
            post_fix.push_back(element);
        } else {
            while (!empty(s) && priority(top(s))) {
                post_fix.push_back(top(s));
                pop(s);
            }
            push(s, element);
        }
    }

    post_fix.pop_back();

    while (!empty(s)) {
        post_fix.push_back(top(s));
        pop(s);
    }
    // 5+2*2/3+2
    for (auto i : post_fix)
        cout << i;
    cout << nln;

    make_null(s);

    for (auto str : post_fix) {
        // cout << "str: " << str << nln;
        if (sign(str2charStr(str))) {
            lo y = string2num(top(s)); pop(s);
            lo x = string2num(top(s)); pop(s);
            if (str == "+")
                push(s, num2string(x+y));
            if (str == "-")
                push(s, num2string(x-y));
            if (str == "*")
                push(s, num2string(x*y));
            if (str == "/")
                push(s, num2string(x/y));
        } else {
            push(s, str2charStr(str));
        }
        // print(s);
    }

    while (!empty(s)) {
        cout << top(s) << nln;
        pop(s);
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    freopen("in", "r", stdin);
    int T = 1;
    // cin >> T;
    // precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
