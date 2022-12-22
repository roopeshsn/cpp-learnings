#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    double a = 10;
    cout << typeid(a).name();
    return 0;
}
