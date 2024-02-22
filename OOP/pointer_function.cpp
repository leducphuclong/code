#include <iostream>
#include <iomanip>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int cal(int a, int b, int (*f)(int, int)) {
    return (*f)(a, b);
}

bool increasing(int a, int b) {
    return a < b;
}

bool decreasing(int a, int b) {
    return a >= b;
}

void swap(int &a, int &b) {
    auto tmp = a; a = b; b = tmp;
}

void sort(int *arr, int n, bool (*cmp)(int, int) = increasing) {
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if ((*cmp)(arr[i], arr[j]) == false) 
            // use pointer function cmp to call actual comparison function out there
                swap(arr[i], arr[j]);
}

void show(int *arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

int main(int argc, char* argv[]) {
    int (*f) (int, int);
    f = sum;
    cout << (*f)(2, 1) << ' ' << cal(2, 1, f) << endl;
    f = sub;
    cout << (*f)(2, 1) << ' ' << cal(2, 1, f) <<  endl << endl;
    
    int arr[] = {3, 2, 1, 9, 8, 10, 7, 11};
    int n = sizeof(arr) / sizeof(int);
    cout << "We have original arr: " << endl;;
    show(arr, n);

    sort(arr, n, increasing); 
    cout << "The array after sort increasingly: " << endl;    
    show(arr, n);

    sort(arr, n, decreasing);
    cout << "The array after sort decreasingly: " << endl; 
    show(arr, n);

    sort(arr, n);
    cout << "The array after sort defaully: " << endl;
    show(arr, n);
    
    return 0;
}