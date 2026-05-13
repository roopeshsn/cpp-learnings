#include <iostream>
#include <vector>
#include <map>

using namespace std;

void sum_equals_k(int nums[], int n, int target) {
    map<int, int> nums_map;
    for(int i = 0; i < n; i++) {
        auto pair = nums_map.find(target - nums[i]);
        if(pair != nums_map.end()) {
            cout << pair->second << ", " << i << endl;
            return;
        } else {
            nums_map[nums[i]] = i;
        }
    }
}

int main() {
    int nums[5] = {2,6,5,8,11};
    int n = 5;
    int target = 14;
    sum_equals_k(nums, n, target);
}