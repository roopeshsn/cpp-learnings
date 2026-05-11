#include <iostream>

using namespace std;

int main() {
    int num = 21;
    int nums[5] = {1,2,3,4,5};
    int *p = &num;
    cout << *p << endl;
    cout << p << endl;

    // updating the value of x using a pointer variable.
    int x = 5;
    int *y = &x;
    *y = 6;
    cout << x << endl;
    int **z = &y;
    cout << **z << endl;
    return 0;
}