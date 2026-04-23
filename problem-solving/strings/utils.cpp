#include <iostream>

using namespace std;

// Print type of a variable
template<typename T>
void printType(T value) {
    cout << __PRETTY_FUNCTION__ << endl;
}

// Convert string to integer
int convert_string_to_integer(string str) {
    int num = 0;
    for (char ch : str) {
        num = num * 10 + (ch - '0');
    }
    return num;
}

// Reverse string
string reverse_string(string str) {
    string res;
    for (int i = str.size() - 1; i >= 0; i--) {
        res.push_back(str[i]);
    }
    return res;
}

// int main() {
//     string str = "21";
//     printType(str);
//     int num = convert_string_to_integer(str);
//     cout << num << endl;
//     printType(num);

//     cout << "Reverse string" << endl;
//     string reversed_str = reverse_string("123");
//     cout << reversed_str << endl;
// }