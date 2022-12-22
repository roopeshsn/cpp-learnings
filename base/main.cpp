#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int square(int);

class Date {
    int day;
    int month;
    int year;

    public:
    Date(int day, int month, int year) {
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }

    string getDate() {
        return to_string(day) + '/' + to_string(month) + '/' + to_string(year);
    }
};

class Student {
    string name;
    int age;
    Date date;

    public:
    Student(string name, int day, int month, int year)
    : name(name), date(day, month, year) {
    }

    string getDate() {
        date.getDate();
    }
};


int main() {
    // cout << "Hello World";
    int a = 'A';
    string name = "Roopesh";
    cout << "\"Hello\nWorld\"" << endl; // :: -> Scope Resolution Operator
    cout << a << endl;
    cout << name;
    int b = 5;
    cout << b << endl;
    bool c = 65;
    cout << c << endl;
    int d = 020;
    cout << d << endl;
    float e = 178.123456789;
    // cout.precision(10);
    cout << e << endl;
    const float PI = 3.14;
    cout << PI << endl;
    int idx = 0;
    for(char val : name) {
        cout << val << idx;
        idx++;
    }

    // array
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    // cout << nums.begin() << endl;
    // cout << nums.end() << endl;

    // pass by reference
    int ans = square(b);
    cout << ans << endl;
    cout << b << endl;

    // class
    Student roopesh("Roopesh", 21, 06, 2002);
    cout << roopesh.getDate();
    return EXIT_SUCCESS; // not needed
}

int square(int val) {
    return val * val;
}

// function template
template <class T>
T max(T first, T second) {
    T max;
    if(first > second) {
        max = first;
    } else {
        max = second;
    }
    return max;
}