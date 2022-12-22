#include <iostream>

using namespace std;

void board(int w, int h) {
    for(int i = 0; i <= h + 1; i++) {
        for(int j = 0; j <= w + 1; j++) {
            if(i == 0 || i == h + 1 || j == 0 || j == w + 1) {
                cout << '#';
            }else {
                cout << ' ';
            }
        }

        cout << endl;
    }
}

int main() {
    board(50, 30);
    return 0;
}