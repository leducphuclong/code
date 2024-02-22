// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define nln '\n'
#define Max_size_of_hash_table 100

// Declare global variables.

typedef struct Box {
    int key;
    struct Box *next, *prev;
} *Box_ptr, *Box_header;

typedef struct HashTable {
    int cap;
    Box_header Hash_array[Max_size_of_hash_table];
} *HashTable_ptr;

HashTable_ptr Initialize() {
    HashTable_ptr hash_tb;
    hash_tb = (HashTable_ptr)malloc(sizeof(HashTable));
    for (int i = 0; i < Max_size_of_hash_table; ++i) {
        hash_tb->Hash_array[i] = (Box_header)malloc(sizeof(Box)*Max_size_of_hash_table);
        hash_tb->Hash_array[i]->next = NULL;
        hash_tb->Hash_array[i]->prev = NULL;
    }
    return hash_tb;
}

int main(int argc, char* argv[]) {
    HashTable_ptr hash_tb = Initialize();
    printf("OK\n");
    return 0;
}
