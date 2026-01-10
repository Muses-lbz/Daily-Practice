#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

// 模拟一个3秒倒计时
void stopwatch() {
    for (int i = 3; i >= 1; --i) {
        cout << "倒计时: " << i << " 秒" << endl;
        this_thread::sleep_for(seconds(1));
    }
    cout << "时间到！" << endl;
}

int main() {
    stopwatch();
    return 0;
}
