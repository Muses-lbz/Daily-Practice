#include <iostream>

using namespace std;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        // 计算实际到站时间
        int actualArrivalTime = arrivalTime + delayedTime;

        // 如果实际到站时间超过 24 小时，减去 24 小时
        if (actualArrivalTime >= 24) {
            actualArrivalTime -= 24;
        }

        return actualArrivalTime;
    }
};

int main()
{
    Solution solution;
    int arrival = 12;
    int delay = 12;
    int result = solution.findDelayedArrivalTime(arrival,delay);
    cout << "actualArrivalTime: " << result << endl;
    return 0;
}