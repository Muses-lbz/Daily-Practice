#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // 计算最少操作次数，使得数组中元素互不相同
    int minimumOperations(vector<int>& nums) {
        int operations = 0; // 记录操作次数

        while (true) {
            unordered_set<int> seen; // 用于检查是否存在重复元素
            bool hasDuplicate = false;

            // 遍历当前数组，检测是否存在重复元素
            for (int i = 0; i < nums.size(); ++i) {
                if (seen.count(nums[i])) {
                    hasDuplicate = true; // 有重复元素
                    break;
                }
                seen.insert(nums[i]);
            }

            if (!hasDuplicate) break; // 若没有重复，结束操作

            // 移除数组前 3 个元素（如果不足 3 个则全部移除）
            operations++;
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
        }

        return operations;
    }
};

// 主函数用于测试
int main() {
    Solution sol;

    // 示例测试用例
    vector<int> nums = { 1, 2, 3, 4, 2, 3, 3, 5, 7 };

    int result = sol.minimumOperations(nums);

    cout << "最少操作次数为: " << result << endl;

    return 0;
}
