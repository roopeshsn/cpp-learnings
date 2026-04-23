#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> extract_digits(int num) {
    vector<int> digits;
    while(num > 0) {
        int digit = num % 10;
        digits.push_back(digit);
        num = num / 10;
    }
    return digits;
}

int reverse_of_a_number(int num) {
    int reverse = 0;
    while(num > 0) {
        int digit = num % 10;
        reverse = (reverse * 10) + digit;
        num = num / 10;
    }
    return reverse;
}

bool is_palindrome(int num) {
    int temp = num;
    int reverse = reverse_of_a_number(num);
    if(reverse == temp) {
        return true;
    }
    return false;
}

bool is_armstrong_number(int num) {
    // same extracting digits logic, cube it and sum it
    return 0;
}

void print_all_divisors(int num) {
    vector<int> nums;
    for(int i = 0; i <= sqrt(num); i++) {
        if(num % i == 0) {
            nums.push_back(i);
            if((num / i) != i) {
                 nums.push_back(num / i);
            }
        }
    }

    for(int x: nums) {
        cout << x << endl;
    }
}

int min(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
}

// GCD or HCF - Brute force approach
int find_gcd(int num1, int num2) {
    // loop from 1 to num1 and check both numbers are factors of both the numbers
    int gcd = -1;
    for(int i = 0; i <= min(num1, num2); i++) {
        if((num1 % i == 0) && (num2 % i == 0)) {
            gcd = i;
        }
    }
    return gcd;
}

// To find whether a given number is prime or not
// The number is prime if it's divisible by 1 and itself
bool is_prime(int num) {
    // find all the factors - if the count is more than 2 then it's not prime
    return true;
}

// Minimum digits to remove to make a number Perfect Square

int main() {
    vector<int> res = extract_digits(7789);
    for (int digit : res) {
        cout << digit << " ";
    }

    cout << "Reverse of a number" << endl;
    int reverse = reverse_of_a_number(7789);
    cout << reverse << endl;

    cout << "Palindrome" << endl;
    cout << is_palindrome(7) << endl;

    cout << "Print the divisors" << endl;
    print_all_divisors(36);

    cout << "Find GCD or HCF" << endl;
    cout << find_gcd(12, 36) << endl;
    return 0;
}