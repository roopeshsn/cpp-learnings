#include <iostream>

using namespace std;

class ArrayIterator {
private:
    int* ptr;

public:
    ArrayIterator(int* p) {
        ptr = p;
    }

    int& operator*() {
        return *ptr;
    }

    // we are overloading ++ operator using the operator keyword 
    ArrayIterator& operator++() {
        ptr++;
        return *this;
    }

    // similarly we are overloading !=
    bool operator!=(const ArrayIterator& other) {
        return ptr != other.ptr;
    }
};

class MyArray {
private:
    int* data;
    int size;

public:
    MyArray(int* arr, int s) {
        data = arr;
        size = s;
    }

    ArrayIterator begin() {
        return ArrayIterator(data);
    }

    ArrayIterator end() {
        return ArrayIterator(data + 5);
    }
};

int main() {
    // iterating an array
    int arr[] = {10, 20, 30, 40, 50};
    MyArray myArr(arr, 5);
    for (auto it = myArr.begin(); it != myArr.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}