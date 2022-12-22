#include<iostream>

using namespace std;

void reverse(int arr[], int size);
void printArr(int arr[], int size);

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    // int size = my_sizeof(arr)/my_sizeof(arr[0]);
    int size = *(&arr + 1) - arr;
    reverse(arr, size);
    printArr(arr, size);
    return 0;
}

void reverse(int arr[], int size) {
    int i = 0, j = size;
    int *ip, *jp;
    ip = arr;
    jp = arr + size - 1;

    while(i < j) {
        int temp = *ip;
        *ip = *jp;
        *jp = temp;
        i++;
        ip++;
        j--;
        jp--;
    }
}

void printArr(int arr[], int size) {
    int *ptr;
    ptr = arr;
    cout << '[';
    for(int i = 0; i < size; i++) {
        if(i > 0) {
            cout << ' ';
        }
        cout << *(ptr + i);
        if(i < size - 1) {
            cout << ',';
        }
    }
    cout << ']' << endl;
}