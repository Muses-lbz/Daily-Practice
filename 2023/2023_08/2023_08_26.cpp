#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();

        for (int i = 0; i < n; ) {
            int start = nums[i];
            int end = start;

            // 找到当前区间的结束位置
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
                end = nums[i];
            }

            // 将区间加入到结果中
            if (start == end) {
                result.push_back(to_string(start));
            }
            else {
                result.push_back(to_string(start) + "->" + to_string(end));
            }

            i++; // 移动到下一个潜在的区间起始位置
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 0, 1, 2, 4, 5, 7 };
    vector<string> ranges = solution.summaryRanges(nums);

    // 打印结果
    for (const string& range : ranges) {
        cout << range << " ";
    }

    return 0;
}
