#include <iostream>
using namespace std;

// 判断是否是质数
bool isPrime(int n) {
    if (n <= 1) return false; // 小于等于1不是质数
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int num = 29;
    cout << num << (isPrime(num) ? " 是质数" : " 不是质数") << endl;
    return 0;
}
