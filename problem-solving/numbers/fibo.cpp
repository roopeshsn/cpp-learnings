#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo_series(int n) {
    // Fibonacci series: 0 1 1 2 3 5 8
    vector<int> nums;
    int a = 0;
    int b = 1;
    nums.push_back(a);
    nums.push_back(b);
    int temp;
    for(int i = 0; i < n; i++) {
        temp = a + b;
        nums.push_back(temp);
        a = b;
        b = temp;
    }
    return nums;
}

int main() {
    vector<int> nums = fibo_series(10);
    for(int num: nums) {
        cout << num << " ";
    }
    return 0;
}