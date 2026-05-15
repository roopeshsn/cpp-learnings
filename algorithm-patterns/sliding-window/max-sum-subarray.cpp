#include <iostream>
#include <vector>
#include <map>

using namespace std;

int max_average_subarray(vector<int> nums, int k) {
    int sum = 0;
    for(int i = 0; i < k; i++) {
        sum += nums[i];
    }
    int max_sum = sum;

    int start = 0;
    int end = k;

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