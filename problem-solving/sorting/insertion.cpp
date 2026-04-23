#include <iostream>

using namespace std;

int insertion_sort(int nums[], int n) {
    // 1. Start from second index and compare the previous elements
    for(int i = 1; i < n; i++) {
        int temp = nums[i];
        int j = i-1;
        while (j >= 0 && nums[j] > temp) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }
    return 0;
}

int main() {
    int nums[8] = {2, 9, 5, 3, 14, 11, 21, 18};
    insertion_sort(nums, 8);
    for(int i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}