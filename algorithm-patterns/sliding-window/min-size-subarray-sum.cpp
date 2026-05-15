#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int min_size_subarray_sum(vector<int> nums, int target) {
    int current_sum = 0;
    int min_len_window = INT_MAX;

    int low = 0;
    int high = 0;

    while(high <= nums.size()) {
        current_sum += nums[high];
        high++;

        while(current_sum >= target) {
            int current_window_size = high - low;

            min_len_window = min(min_len_window, current_window_size);

            current_sum -= nums[low];
            low++;
        }
    }

    return min_len_window == INT_MAX ? 0 : min_len_window;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int ans = min_size_subarray_sum(nums, 7);
    cout << ans << endl;
}