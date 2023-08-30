// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define nln '\n'

// Declare global variables.

typedef int element_type;

typedef struct  node {
    element_type element;
    struct node *next, *prev;
} *node_ptr, *header_node_ptr, *list_node;

typedef list_node *list_node_ptr;

typedef struct hash_tbl {
    unsigned int table_size;
    list_node *lists;
} *hash_tbl_ptr;

hash_tbl_ptr Initialize(unsigned int table_size) {
    hash_tbl_ptr H;

    H = (hash_tbl_ptr)malloc(sizeof(struct hash_tbl));
    if (H == NULL)
        printf("Memory Error\n");

    H->table_size = table_size;


    H->lists = (list_node_ptr)malloc(sizeof(struct node)*table_size);
    if (H->lists == NULL)
        printf("Memory Error\n");

    for (int i = 0; i < table_size; ++i) {
        H->lists[i] = (node_ptr)malloc(sizeof(struct node));
        if (H->lists[i] == NULL)
            printf("Memory Error\n");
        H->lists[i]->element = 0;
        H->lists[i]->next = NULL;
        H->lists[i]->prev = NULL;
    }
    return H;
}

int hashing(int key, int capacity) {
    return key % capacity;
}

void print_hash_table(hash_tbl_ptr H) {
    for (int i = 0; i < H->table_size; ++i) {
        printf("i: ");
        node_ptr itr_node = H->lists[i];
        while (itr_node->next != NULL) {
            printf("%i ", itr_node->next->element);
            itr_node = itr_node->next;
        }
        printf("\n");
    }
}

void Insert(hash_tbl_ptr H, element_type key) {
    // Hashing
    int hash_key = hashing(key, H->table_size);
    // Adding
    node_ptr header_node = H->lists[hash_key];

    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = key;
    new_node->next = NULL;
    new_node->prev = NULL;

    new_node->next = header_node->next;
    new_node->prev = header_node;
    if (header_node->next != NULL)
        header_node->next->prev = new_node;
    header_node->next = new_node;
}

int main(int argc, char* argv[]) {
    hash_tbl_ptr H;
    int table_size = 10;
    H = Initialize(table_size);
    H->table_size = table_size;

    Insert(H, 10);
    print_hash_table(H);

    printf("Ok It's good for now !!\n");
    return 0;
}
