#include <iostream>

using namespace std;

// DMA -> Dynamic Memory Allocation -> In Runtime
// In DMA, data will be stored in Heap memory. 
int main() {
    int *a = new int(10);
    cout << *a << endl;
    delete a;
    int *arr = new int[5]{1, 2, 3, 4, 5};
    cout << *(arr+5) << endl;
    delete[] arr;
    return 0;
}

// https://www.quora.com/What-happens-when-we-deallocate-memory-using-delete-operator-in-c-Does-the-value-stored-in-the-heap-memory-get-permanently-deleted-from-existence-or-its-just-left-as-it-is-and-gets-replaced-when-a-new-variable