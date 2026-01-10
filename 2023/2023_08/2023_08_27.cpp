#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // 首先根据区间的起始位置进行排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (const auto& interval : intervals) {
            if (interval[0] <= merged.back()[1]) {
                // 如果当前区间的起始位置小于等于前一个区间的结束位置，发生重叠
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
            else {
                // 没有重叠，直接添加新的区间
                merged.push_back(interval);
            }
        }

        return merged;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    vector<vector<int>> result = s.merge(intervals);

    for (const auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}
