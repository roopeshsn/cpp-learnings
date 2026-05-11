#include <iostream>

using namespace std;

int main() {
    // iterating a vector
    vector<int> vec = {10, 20, 30, 40, 50};
    for (auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}