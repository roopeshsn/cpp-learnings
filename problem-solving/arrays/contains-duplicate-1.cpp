#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool contains_duplicate_hashmap(vector<int>& nums) {
    map<int, int> nums_map;
    for(int i = 0; i < nums.size(); i++) {
        auto it = nums_map.find(nums[i]);
        if(it != nums_map.end()) {
            nums_map[nums[i]] += 1;
        } else {
            nums_map[nums[i]] = 1;
        }
    }

    for(auto it = nums_map.begin(); it != nums_map.end(); ++it) {
        if(it->second > 1) {
            return true;
        }
    }

    return false;
}

bool contains_duplicate_set(vector<int>& nums) {

}

bool contains_duplicate_sorting(vector<int>& nums) {
    
}