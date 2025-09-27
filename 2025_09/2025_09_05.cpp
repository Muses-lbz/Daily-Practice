#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = (int)points.size();
        double maxArea = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // 三个点坐标
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];

                    // 三角形面积公式
                    double area = 0.5 * abs(x1 * (y2 - y3) +
                        x2 * (y3 - y1) +
                        x3 * (y1 - y2));
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};

int main() {
    Solution sol;

    // 示例 1
    vector<vector<int>> points1 = { {0,0}, {0,1}, {1,0}, {0,2}, {2,0} };
    cout << "最大三角形面积 (例1): " << sol.largestTriangleArea(points1) << endl;

    // 示例 2
    vector<vector<int>> points2 = { {1,0}, {0,0}, {0,1} };
    cout << "最大三角形面积 (例2): " << sol.largestTriangleArea(points2) << endl;

    return 0;
}
