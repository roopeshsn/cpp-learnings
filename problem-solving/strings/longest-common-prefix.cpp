#include<iostream>

using namespace std;

// This problem also can be solved with Trie
// In the node we need to add another field `count of childrens`
string longest_common_prefix(vector<string> words) {
    string res;
    // Loop the characters in the first string of the array
    for(int i = 0; i < words[0].size(); i++) {
        char ch = words[0][i];
        // Compare one character at a time with other strings
        for(int j = 1; j < words.size(); j++) {
            if(i >= words[j].size() || ch != words[j][i]) {
                return res;
            }
        }
        res += ch;
    }
    return res;
}

int main() {
    vector<string> words = {"cluster", "clue", "clutch", "club", "clumsky"};
    cout << longest_common_prefix(words) << endl;
}