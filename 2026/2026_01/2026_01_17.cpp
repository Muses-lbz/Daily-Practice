#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;

        // 1. 对数组排序
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        // 2. 找到最小绝对差（只需比较相邻元素）
        for (int i = 1; i < arr.size(); i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        // 3. 收集所有差值等于最小绝对差的元素对
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({ arr[i - 1], arr[i] });
            }
        }

        return result;
    }
};

// 打印二维 vector 的工具函数
void printResult(const vector<vector<int>>& res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if (i != res.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // 示例 1
    vector<int> arr1 = { 4, 2, 1, 3 };
    cout << "示例 1 输出：";
    printResult(solution.minimumAbsDifference(arr1));
    // 期望输出：[[1,2],[2,3],[3,4]]

    // 示例 2
    vector<int> arr2 = { 1, 3, 6, 10, 15 };
    cout << "示例 2 输出：";
    printResult(solution.minimumAbsDifference(arr2));
    // 期望输出：[[1,3]]

    // 示例 3
    vector<int> arr3 = { 3, 8, -10, 23, 19, -4, -14, 27 };
    cout << "示例 3 输出：";
    printResult(solution.minimumAbsDifference(arr3));
    // 期望输出：[[-14,-10],[19,23],[23,27]]

    return 0;
}
