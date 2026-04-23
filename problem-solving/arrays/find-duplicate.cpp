#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Find the Duplicate Number
int find_duplicate(vector<int> nums) {
    unordered_map<int, int> counter; // key: number, value: count
    for(int i = 0; i < nums.size(); i++) {
        int key = nums[i];
        if(counter.count(key)) {
            counter[key] = counter[key] + 1;
        } else {
            counter[key] = 1;
        }
    }

    for (const auto& [key, value] : counter) {
        if(value > 1) {
            return key;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {3, 1, 2, 4, 3, 2};
    int res = find_duplicate(nums);
    cout << res << endl;
    return 0;
}
