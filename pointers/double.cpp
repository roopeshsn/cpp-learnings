#include <iostream>

using namespace std;

void multiply_by_two(int* nums, int size) {
    for(int i = 0; i < size; i++) {
        nums[i] = nums[i] * 2;
    }
}

int main() {
    int nums[5] = {1,2,3,4,5};
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    multiply_by_two(nums, 5);
    for(int num : nums) {
        cout << num << " ";
    }
    return 0;
}