#include <iostream>

using namespace std;

// Implemented using frequency counting pattern
// In anagram checking we need to count the characters
// If the same number of characters present in the another string then we can say they are anagram
bool areAnagrams(string &a, string &b) {
    if(a.size() != b.size()){
        return false;
    }

    unordered_map<char, int> frequency_a;
    unordered_map<char, int> frequency_b;

    for(char ch: a) {
        frequency_a[ch] += 1;
    }

    for(char ch: b) {
        frequency_b[ch] += 1;
    }

    if(frequency_a == frequency_b) {
        return true;
    }

    return false;
}

int main() {
    string a = "listen";
    string b = "silent";
    cout << "Are the strings " << a << b <<  " anagram: " << areAnagrams(a, b) << endl;
    return 0;
}