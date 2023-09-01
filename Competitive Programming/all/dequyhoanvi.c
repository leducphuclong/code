#include<stdio.h>

const int N = 100;

bool vst[N]; int arr[N]; int n = 3, cnt = 0;

void recurse(int i){
    if (i > n){
        ++cnt;
        for (int j = 1; j <= n; ++j)
            printf("%i ", arr[j]);
        printf("%c", '\n');
        return;
    }
    for (int k = 1; k <= n; ++k)
        if (vst[k] == 0){
            arr[i] = k;
            vst[k] = 1;
            recurse(i+1);
            vst[k] = 0;
        }

}

int main(){
    recurse(1);
    printf("%i", cnt);
    return 0;
}