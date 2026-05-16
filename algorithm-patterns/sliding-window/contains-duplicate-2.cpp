#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Contains Duplicate II
// Given an integer array nums and an integer k, 
// return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
bool contain_nearby_duplicate(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    set<int> hashset;
    for(right = 0; right < nums.size(); right++) {
        if(right - left > k) {
            hashset.erase(nums[left]);
            left++;
        }
        if(hashset.count(nums[right])) {
            return true;
        }
        hashset.insert(nums[right]);
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};
    int ans = contain_nearby_duplicate(nums, 3);
    cout << ans << endl;
}