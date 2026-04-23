#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int bubble_sort(int nums[], int n) {
    // 1. Check the current number and the adjacent number
    // 2. Swap the position if the current number is greater than the adjacent number
    // 3. One optimization can be done is that we can avoid i = n-2, n-3, ... iterations if the array is sorted.
    // TC: outer loop: sum of n-1, n-2, n-3 till 2
    for(int i = n - 1; i > 0; i--) {
        bool is_sorted = false;
        for(int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                // swap
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                is_sorted = true;
            }
        }
        if(is_sorted == false) {
            break;
        }
    }
}

int main() {
    // vector<int> nums = {6, 1, 21, 9, 15, 11, 19, 2};
    int nums[8] = {6, 1, 21, 9, 15, 11, 19, 2};
    bubble_sort(nums, 8);
    for(int i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}