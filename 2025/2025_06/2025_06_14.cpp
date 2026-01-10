#include <iostream>
using namespace std;

// 打印右上直角三角形
void printTriangle(int height) {
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= i; ++j)
            cout << "*";
        cout << endl;
    }
}

int main() {
    printTriangle(5);
    return 0;
}
