#include <iostream>
using namespace std;

// 递归计算阶乘
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int num = 5;
    cout << num << " 的阶乘是 " << factorial(num) << endl;
    return 0;
}
