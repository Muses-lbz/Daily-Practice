#include <iostream>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year = 2024;
    cout << year << (isLeapYear(year) ? " 是闰年" : " 不是闰年") << endl;
    return 0;
}
