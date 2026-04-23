#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 5};
    int factor = 1;
    int sum = 0;
    for(int i = nums.size() - 1; i >= 0; i--) {
        sum = sum + (nums[i] * factor);
        factor = factor * 10;
    }
    cout << sum << endl;
    cout << 6 % 10 << endl;
    cout << 6 / 10 << endl;
    return 0;
}