#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int remove_duplicates(int nums[], int n) {
    // Have two pointers left and right - initially both will start from second position (index 1)
    // Left pointer can be used to track the idx where we can insert an unique value
    // Right pointer can be used to iterate every position
    int left = 1;
    for(int right = 1; right < n; right++) {
        if(nums[right] != nums[right-1]) {
            // if the idx right-1 equals idx right then we can put the value in the right idx to left idx.
            nums[left] = nums[right];
            left++;
        }
    }
    return 0;
}

int main() {
    int nums[7] = {1,2,2,3,4,4,5};
    for(int num: nums) {
        cout << num << " ";
    }
    cout << endl;
    remove_duplicates(nums,7);
    for(int num: nums) {
        cout << num << " ";
    }
    return 0;
}