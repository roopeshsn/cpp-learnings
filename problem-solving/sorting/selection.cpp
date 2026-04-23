#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int selection_sort(int nums[], int n) {
    // 1. Search for minimum number in an array, and replace it's index with the first element.
    // 2. Continue this process until the n-1 index
    for(int i = 0; i <= n - 2; i++) {
        for(int j = i; j <= n - 1; j++) {
            if (nums[i] > nums[j]) {
                // swap
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main() {
    // vector<int> nums = {6, 1, 21, 9, 15, 11, 19, 2};
    int nums[8] = {6, 1, 21, 9, 15, 11, 19, 2};
    selection_sort(nums, 8);
    for(int i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}