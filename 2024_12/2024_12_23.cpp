//#include <iostream>
//#include <chrono>
//#include <ctime>
//#include <thread>
//
//using namespace std;
//
//// 模拟限时服务，持续 24 小时
//class TimeLimitedService {
//public:
//    // 构造函数，设置开始时间和服务持续时间
//    TimeLimitedService() {
//        // 获取当前系统时间作为开始时间
//        start_time = chrono::system_clock::now();
//        duration = chrono::hours(24);  // 限时服务时间：24小时
//    }
//
//    // 模拟获取当前时间的函数
//    chrono::system_clock::time_point getCurrentTime() {
//        return chrono::system_clock::now();
//    }
//
//    // 检查限时服务是否过期
//    bool isServiceExpired() {
//        auto current_time = getCurrentTime();
//        auto expire_time = start_time + duration;
//
//        // 如果当前时间超过了服务结束时间，服务过期
//        return current_time >= expire_time;
//    }
//
//    // 打印剩余服务时间
//    void printRemainingTime() {
//        auto current_time = getCurrentTime();
//        auto expire_time = start_time + duration;
//
//        auto remaining_duration = expire_time - current_time;
//        if (remaining_duration.count() > 0) {
//            cout << "服务仍然有效，剩余时间: "
//                << chrono::duration_cast<chrono::hours>(remaining_duration).count() << "小时"
//                << endl;
//        }
//        else {
//            cout << "服务已过期！" << endl;
//        }
//    }
//
//    // 模拟调整本地时间（实际上只是调整程序内的时间戳）
//    void simulateAdjustSystemTime(int days) {
//        // 调整服务时间（模拟系统时间被调回一天）
//        start_time -= chrono::hours(24 * days);
//        cout << "模拟调整时间: 服务开始时间被调整到前 " << days << " 天" << endl;
//    }
//
//private:
//    chrono::system_clock::time_point start_time;  // 服务开始时间
//    chrono::hours duration;  // 服务持续时间
//};
//
//int main() {
//    TimeLimitedService service;
//
//    // 模拟服务启动后 12 小时
//    //this_thread::sleep_for(chrono::hours(12));
//    service.printRemainingTime();
//
//    // 模拟将时间调整至前一天（24小时）
//    service.simulateAdjustSystemTime(1);
//
//    // 再次检查服务剩余时间
//    service.printRemainingTime();
//
//    return 0;
//}

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

using namespace std;

// 模拟限时服务，持续 24 小时
class TimeLimitedService {
public:
    // 构造函数，设置开始时间和服务持续时间
    TimeLimitedService() {
        // 获取当前系统时间作为开始时间
        start_time = chrono::system_clock::now();
        duration = chrono::hours(24);  // 限时服务时间：24小时
    }

    // 模拟获取当前时间的函数
    chrono::system_clock::time_point getCurrentTime() {
        return chrono::system_clock::now();
    }

    // 检查限时服务是否过期
    bool isServiceExpired() {
        auto current_time = getCurrentTime();
        auto expire_time = start_time + duration;

        // 如果当前时间超过了服务结束时间，服务过期
        return current_time >= expire_time;
    }

    // 打印剩余服务时间
    void printRemainingTime() {
        auto current_time = getCurrentTime();
        auto expire_time = start_time + duration;

        auto remaining_duration = expire_time - current_time;
        if (remaining_duration.count() > 0) {
            cout << "服务仍然有效，剩余时间: "
                << chrono::duration_cast<chrono::hours>(remaining_duration).count() << "小时"
                << endl;
        }
        else {
            cout << "服务已过期！" << endl;
        }
    }

    // 模拟调整本地时间并延长有效期（实际上只是调整程序内的时间戳）
    void simulateAdjustSystemTime(int days) {
        // 计算已过的时间
        auto elapsed = chrono::system_clock::now() - start_time;

        // 将已过的时间转换为小时
        auto elapsed_hours = chrono::duration_cast<chrono::hours>(elapsed);

        // 调整服务时间（模拟系统时间被调回一天）
        start_time -= chrono::hours(24 * days);
        duration += elapsed_hours;  // 延长服务有效期（用小时来加）

        cout << "模拟调整时间: 服务开始时间被调整到前 " << days << " 天，并延长服务有效期" << endl;
    }

private:
    chrono::system_clock::time_point start_time;  // 服务开始时间
    chrono::hours duration;  // 服务持续时间
};

int main() {
    TimeLimitedService service;

    // 模拟服务启动后 12 小时
    // this_thread::sleep_for(chrono::hours(12));
    service.printRemainingTime();

    // 模拟将时间调整至前一天（24小时）并延长有效期
    service.simulateAdjustSystemTime(1);

    // 再次检查服务剩余时间
    service.printRemainingTime();

    return 0;
}
