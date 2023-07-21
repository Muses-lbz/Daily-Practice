//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
//
//class Solution {
//public:
//    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//        deque<pair<int, int>> window; // Stores pairs of (yi - xi, xi)
//        int res = INT_MIN;
//
//        for (const auto& point : points) {
//            int x = point[0];
//            int y = point[1];
//
//            // Remove points outside the window (xi - xj > k)
//            while (!window.empty() && x - window.front().second > k) {
//                window.pop_front();
//            }
//
//            if (!window.empty()) {
//                int val = window.front().first + y + x;
//                res = max(res, val);
//            }
//
//            // Remove points with smaller yi - xi since they won't be candidates for max value
//            while (!window.empty() && y - x >= window.back().first) {
//                window.pop_back();
//            }
//
//            window.push_back({ y - x, x });
//        }
//
//        return res;
//    }
//};
//
//int main() {
//    vector<vector<int>> points = { {1, 3}, {2, 0}, {5, 10}, {6, -10} };
//    int k = 1;
//
//    Solution sol;
//    int result = sol.findMaxValueOfEquation(points, k);
//
//    cout << "最大值为: " << result << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> window; // 存储(xi - yi, xi)这样的pair
        int res = INT_MIN;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];

            // 步骤 1：移除窗口外的点 (xi - xj > k)
            while (!window.empty() && x - window.front().second > k) {
                window.pop_front();
            }

            // 步骤 2：计算当前值 (yi + yj + |xi - xj|)
            if (!window.empty()) {
                int val = window.front().first + y + x;
                res = max(res, val);
            }

            // 步骤 3：移除窗口内比当前点更小的点 (yi - xi较小的点不可能成为最大值的候选)
            while (!window.empty() && y - x >= window.back().first) {
                window.pop_back();
            }

            // 将当前点加入窗口
            window.push_back({ y - x, x });
        }

        return res;
    }
};

int main() {
    vector<vector<int>> points = { {1, 3}, {2, 0}, {5, 10}, {6, -10} };
    int k = 1;

    Solution sol;
    int result = sol.findMaxValueOfEquation(points, k);

    cout << "最大值为: " << result << endl;

    return 0;
}