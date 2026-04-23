#include <iostream>

using namespace std;

// Implemented using Two-pointers pattern
bool isPalindrome(string str) {
    int start = 0;
    int end = str.size() - 1;
    while(start < end) {
        if(str[start] == str[end]) {
            start += 1;
            end -= 1;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string str = "tamil";
    cout << "Is the string " << str <<  " palindrome: " << isPalindrome(str) << endl;
    return 0;
}