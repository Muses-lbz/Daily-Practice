#include <iostream>
using namespace std;

// 打印九九乘法表
void printMultiplicationTable() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << j << "×" << i << "=" << j * i << "\t";
        }
        cout << endl;
    }
}

int main() {
    printMultiplicationTable();
    return 0;
}
