// Copyright (c) [year] [author's name]. All rights reserved.
#include<stdio.h>

int x[3];
FILE *fi, *fo;

void recurse(int i, int sum){
    if (i == 3) {
        fprintf(fi, "%d %d %d \n", x[1], x[2], sum);
        return;
    }
    for (int e = 0; e <= sum; ++e) {
        x[i] = e;
        recurse(i+1, sum-e);
    }
}

int main() {
    fi = fopen("in", "r");
    fclose(fi);

    fo = fopen("out", "w");
    recurse(1, 15);
    fclose(fo);
    return 0;
}
