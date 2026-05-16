#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

// Subarray Product Less Than K
// Given an array of integers nums and an integer k, 
// return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
int subarray_product_less_than_k(vector<int> nums, int target) {
    int current_product = 1;

    int low = 0;
    int high = 0;

    int subarray_counter = 0;

    while(high < nums.size()) {
        current_product *= nums[high];
        high++;

        while(current_product >= target) {
            current_product /= nums[low];
        }

        int current_window_size = high - low;
        subarray_counter += 1 + current_window_size;
        low++;
    }

    return subarray_counter;
}

int main() {
    vector<int> nums = {10,5,2,6};
    int ans = subarray_product_less_than_k(nums, 100);
    cout << ans << endl;
}