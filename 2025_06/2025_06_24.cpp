#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 模拟投掷骰子
int rollDice() {
    return rand() % 6 + 1; // 返回1~6
}

int main() {
    srand(time(0)); // 设置随机种子
    cout << "你投出的点数是：" << rollDice() << endl;
    return 0;
}
