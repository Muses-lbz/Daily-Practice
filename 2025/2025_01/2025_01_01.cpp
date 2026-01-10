#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyCalendar {
public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for (auto& booking : bookings) {
            // 检查新预定是否与已存在的预定发生重叠
            if (max(startTime, booking.first) < min(endTime, booking.second)) {
                return false;  // 如果重叠，返回 false
            }
        }
        // 如果没有重叠，添加新的预定
        bookings.push_back({ startTime, endTime });
        return true;
    }

private:
    vector<pair<int, int>> bookings;  // 用来存储已预定的时间段
};

int main() {
    MyCalendar myCalendar;
    cout << boolalpha;  // 打印 true/false 而不是 1/0
    cout << myCalendar.book(10, 20) << endl;  // 返回 true
    cout << myCalendar.book(15, 25) << endl;  // 返回 false
    cout << myCalendar.book(20, 30) << endl;  // 返回 true
    return 0;
}
