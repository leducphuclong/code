// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Bài này khả năng 90% nằm trong đề

/* Đề: cho một biểu thức, kiểm tra xem các dấu ngoặc trong biểu thức đó
có đang được dùng đúng hay không?
Ví dụ: (2+3)*1+[(2+3)+1] -> Đúng
       (2+3)*[1 -> Sai
*/

/* Thuật toán bài là sử dụng thực hiện các thao tác rất đơn giản
    - Đọc từng kí tự trong biểu thức:
    - Nếu là số hoặc là dấu thì kệ bà nó
    - Nếu là ngoặc thì kiểm tra xem nó là ngoặc đóng hay ngoặc mở
    - Nếu như là ngoặc mở, đơn giản push thằng vào stack
    - Nếu là ngoặc đóng, kiểm tra xem top của stack có phải là ngoặc mở tương
ứng của nó hay là không.
    - Tương ứng nghĩa là:
        ( với )
        [ với ]
        { với }
    - Nếu như top không phải là ngoặc tương ứng thì trả về kết quả là Sai (
Ngoặc dùng bị sai)
    - Nếu như top là ngoặc tương ứng thì liền pop ra khỏi stack

    Lặp lại các bước trên cho đến khi duyệt hết các kí tự trong biểu
mà stack là rỗng thì trả về là True (Ngoặc dùng đúng) ngược lại False.
*/

// Include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef char element_type;

typedef struct node {
    element_type element;
    struct node *next;
} *node_ptr;

typedef node_ptr stack;

// Constant

// Declare global variables.
// End of global variable declaration.

stack initialize(stack s) {
    s = (stack)malloc(sizeof(struct node));
    s->next = NULL;
    return s;
}

void push(stack s, element_type element) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = element;
    new_node->next = s->next;
    s->next = new_node;
}

element_type top(stack s) {
    return s->next->element;
}

bool empty(stack s) {
    return s->next == NULL;
}

void pop(stack s) {
    if (empty(s))
        return;
    node_ptr tmp = s->next;
    s->next = s->next->next;
    free(tmp);
}

int is_parenthesis(char ch) {
    if (ch == '(' || ch == '[' || ch == '{')
        return 1;
    if (ch == ')' || ch == ']' || ch == '}')
        return 2;
    return 0;
}

char corresponding(char ch) {
    if (ch == '(')
        return ')';
    if (ch == '[')
        return ']';
    if (ch == '{')
        return '}';
    return ' ';
}

bool check_parenthesis(char* exp) {
    int l = strlen(exp);
    stack s = initialize(s);
    for (int i = 0; i < l; ++i) {
        int check = is_parenthesis(exp[i]);
        if (!check)
            continue;
        if (check == 1) {
            push(s, exp[i]);
        } else if (check == 2) {
            if (exp[i] == corresponding(top(s)))
                pop(s);
            else
                return false;
        }
    }
    return empty(s);
}

int main(int argc, char* argv[]) {
    if (check_parenthesis("(2+3)*1+[(2+3)+1]"))
        printf("This expression is correct!\n");
    else
        printf("This expression is not correct\n");

    if (check_parenthesis("(2+3)*1+[(2+3)+{1]}"))
        printf("This expression is correct!\n");
    else
        printf("This expression is not correct\n");
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
