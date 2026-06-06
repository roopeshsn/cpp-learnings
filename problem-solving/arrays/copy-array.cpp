#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void copy_array(int *a, int *b, int n) {
    for(int i = 0; i < n; i++) {
        *(b+i) = *(a+i);
    }
}

int* simple_copy(int a[], int n) {
    int b[5];
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    return b;
}

// Three ways to copy an array
// 1. Simple copy
// 2. Pointer arithmetic
// 3. copy, memcpy, memmove
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];
    int n = 5;

    copy_array(a, b, n);

    for(int i = 0; i < n; i++) {
        cout << b[i];
    }

    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << a[i];
    }

    cout << endl;

    cout << a+5 << *(a+5) << endl;
}