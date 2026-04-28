#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        // 1. 将二维数组拉平成一维数组，方便统一处理
        for (auto& row : grid) {
            for (auto& val : row) {
                nums.push_back(val);
            }
        }

        // 2. 判断是否可以变成单值网格
        // 条件：所有元素与基准值的差必须是 x 的倍数
        int base = nums[0];
        for (int num : nums) {
            if ((num - base) % x != 0) {
                return -1; // 无法通过 ±x 操作变成同一个数
            }
        }

        // 3. 排序，为了找到中位数
        sort(nums.begin(), nums.end());

        // 4. 选择中位数作为目标值（使操作次数最少）
        int n = (int)nums.size();
        int median = nums[n / 2];

        // 5. 计算总操作次数
        // 每个元素变为 median 所需操作次数为 |num - median| / x
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = { {2,4},{6,8} };
    int x1 = 2;
    cout << "示例1输出: " << sol.minOperations(grid1, x1) << endl; // 4

    vector<vector<int>> grid2 = { {1,5},{2,3} };
    int x2 = 1;
    cout << "示例2输出: " << sol.minOperations(grid2, x2) << endl; // 5

    vector<vector<int>> grid3 = { {1,2},{3,4} };
    int x3 = 2;
    cout << "示例3输出: " << sol.minOperations(grid3, x3) << endl; // -1

    return 0;
}