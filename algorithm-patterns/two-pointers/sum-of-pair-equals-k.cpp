#include <iostream>
#include <vector>
#include <map>

using namespace std;

// start will point to index 0
// end will point to last index
// second = target - nums[start]
// as the array is sorted we will use the technique similar to binary search
void sum_equals_k(int nums[], int n, int target) {
    sort(nums, nums+n);
    int start = 0;
    int end = n - 1;
    while(start < end) {
        int second = target - nums[start];
        if(nums[end] > second) {
            end--;
        } else if (nums[end] < second) {
            start++;
        } else {
            cout << nums[start] << " " << nums[end];
            return;
        }
    }
    return;
}

int main() {
    int nums[5] = {2,6,5,8,11};
    int n = 5;
    int target = 14;
    sum_equals_k(nums, n, target);
}