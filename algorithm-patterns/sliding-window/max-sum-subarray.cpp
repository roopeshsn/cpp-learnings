#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Maximum Average Subarray I
// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
// Any answer with a calculation error less than 10-5 will be accepted.
int max_average_subarray(vector<int> nums, int k) {
    int sum = 0;

    // first window consisting of k elements
    for(int i = 0; i < k; i++) {
        sum += nums[i];
    }
    int max_sum = sum;

    int start = 0;
    int end = k;

    // This is a fixed window problem
    // subtract the first element from the sum and add k + 1 element
    // increment both start and end pointers - we are moving the window towards right
    // compare current sum with max sum
    while(end <= nums.size()) {
        sum -= nums[start];
        start++;
        sum += nums[end];
        end++;

        max_sum = max(max_sum, sum);
    }

    return max_sum / k;
}

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int ans = max_average_subarray(nums, 4);
    cout << ans << endl;
}