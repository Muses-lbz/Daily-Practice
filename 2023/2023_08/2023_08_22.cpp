#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prevPerson = -1; // 上一个有人坐的座位的下标
        int maxDistance = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (prevPerson == -1) {
                    // 亚历克斯坐在第一个座位上
                    maxDistance = max(maxDistance, i);
                }
                else {
                    // 亚历克斯坐在两人之间的座位上
                    maxDistance = max(maxDistance, (i - prevPerson) / 2);
                }
                prevPerson = i;
            }
        }

        // 亚历克斯坐在最后一个座位上
        maxDistance = max(maxDistance, n - 1 - prevPerson);

        return maxDistance;
    }
};

int main() {
    Solution solution;
    vector<int> seats = { 1, 0, 0, 0, 1, 0, 1 };
    int result = solution.maxDistToClosest(seats);
    cout << "Max distance to closest person: " << result << endl;

    return 0;
}
