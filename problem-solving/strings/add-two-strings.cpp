
#include <iostream>
#include "utils.h"

using namespace std;

int reverse_of_a_number(int num) {
    int reverse = 0;
    while(num > 0) {
        int digit = num % 10;
        reverse = (reverse * 10) + digit;
        num = num / 10;
    }
    return reverse;
}

string add_two_strings(string str1, string str2) {
    // say str1 = "123", str2 = "456"
    string res;
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    int carry = 0;

    while(i >= 0 || j >= 0) {
        // Covert to int type
        // If i or j is lesser than 0 that means any of them are of unqual length. In that case we want to use 0 to sum.
        int digit1 = (i >= 0) ? str1[i] - '0' : 0;
        int digit2 = (j >= 0) ? str2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        // Carrying MSB
        carry = sum / 10;
        
        // Pushing only LSB
        char ch = (sum % 10) + '0';
        res.push_back(ch);
        i--;
        j--;
    }

    if (carry) {
        res.push_back(carry + '0');
    }

    return reverse_string(res);
}

string multiply_two_strings(string str1, string str2) {
    string res;
    int product_sum = 0;
    int product_factor = 1;
    for(int i = str2.size() - 1; i >= 0; i--) {
        int digit1 = str2[i] - '0';
        int carry = 0;
        int sum = 0;
        for(int j = str1.size() - 1; j >= 0; j--) {
            int digit2 = str1[j] - '0'; 
            int product = (digit1 * digit2) + carry;
            carry = product / 10;
            sum = (sum * 10) + product % 10;
            cout << product << " ";
            cout << reverse_of_a_number(sum) << endl;
        }
        product_sum += reverse_of_a_number(sum) * product_factor;
        product_factor *= 10;
    }
    cout << product_sum << endl;
    return res;
}

int add_two_binary_strings(string bin_str1, string bin_str2) {
    return 0;
}

int main() {
    string str1 = "4321";
    string str2 = "6543";
    string bin_str1 = "1001";
    string bin_str2 = "1010";
    string res = add_two_strings(str1, str2);
    cout << res << endl;

    multiply_two_strings("123", "456");
    return 0;
}