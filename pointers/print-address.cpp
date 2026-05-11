#include <iostream>

using namespace std;

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int* ptr = nums;
    int n = 5;
    cout << "Address" << "          Value" << endl;
    for(int i = 0; i < n; i++) {
            cout << &ptr+i << "          " << *ptr+i << endl;
    }
    return 0;
}