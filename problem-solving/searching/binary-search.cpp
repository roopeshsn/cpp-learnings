#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &nums, int num) {
    int start = 0;
    int end = nums.size() - 1;
    int res = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2; // mid = (start + end) / 2 will also work
        if(nums[mid] == num) {
            res = mid;
            return res;
        } else if(nums[mid] > num) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 5, 6, 9, 15, 17, 21, 23, 45};
    int res = binary_search(nums, 21);
    cout << res << endl;
    return 0;
}