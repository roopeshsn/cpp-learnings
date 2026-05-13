#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print_vector(vector<int> nums) {
    cout << "[";
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

vector<vector<int>> generate_subarrays(int nums[], int n) {
    vector<vector<int>> res;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            vector<int> subarray;
            for(int k = i; k <= j; k++) {
                // print_vector(subarray);
                // cout << nums[k] << " ";
                subarray.push_back(nums[k]);
            }
            res.push_back(subarray);
            // cout << endl;
        }
    }
    return res;
}

int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    vector<vector<int>> res = generate_subarrays(nums, 5);
    for(vector<int> inner : res) {
        cout << "[";
        for(int num : inner) {
            cout << num << ",";
        }
        cout << "]" << endl;
     }
    return 0;
}