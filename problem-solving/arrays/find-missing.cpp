#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Find the Missing Number
int find_missing(vector<int> nums) {
    int arr_sum = 0;
    int n = nums.size() + 1;
    int sum = (n * (n + 1)) / 2;
    for(int i = 0; i < nums.size(); i++) {
        arr_sum += nums[i];
    }

    cout << arr_sum << sum << endl;

    return sum - arr_sum;
}

int main() {
    vector<int> nums = {3, 1, 2, 5}; // sum = 11 , n = size + 1
    int res = find_missing(nums);
    cout << res << endl;
    return 0;
}


