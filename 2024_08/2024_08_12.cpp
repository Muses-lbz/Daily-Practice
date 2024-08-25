#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;  // 如果不能整除，直接返回 false

        int targetSum = totalSum / k;  // 每个子集的目标和
        vector<int> subsetSums(k, 0);  // 用于跟踪每个子集的当前和
        sort(nums.rbegin(), nums.rend());  // 从大到小排序，优化回溯

        return backtrack(nums, subsetSums, k, targetSum, 0);
    }

private:
    bool backtrack(const vector<int>& nums, vector<int>& subsetSums, int k, int targetSum, int index) {
        if (index == nums.size()) {
            // 如果所有元素都被分配完毕，检查每个子集的和是否等于目标和
            for (int i = 0; i < k; ++i) {
                if (subsetSums[i] != targetSum) return false;
            }
            return true;
        }

        for (int i = 0; i < k; ++i) {
            // 尝试将 nums[index] 添加到第 i 个子集中
            if (subsetSums[i] + nums[index] <= targetSum) {
                subsetSums[i] += nums[index];

                // 递归检查下一个元素
                if (backtrack(nums, subsetSums, k, targetSum, index + 1)) return true;

                // 回溯
                subsetSums[i] -= nums[index];
            }

            // 如果第 i 个子集为空且不能容纳当前元素，则直接返回 false
            if (subsetSums[i] == 0) break;
        }

        return false;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = { 4, 3, 2, 3, 5, 2, 1 };
    int k1 = 4;
    bool result1 = solution.canPartitionKSubsets(nums1, k1);
    cout << "示例 1 输出: " << (result1 ? "True" : "False") << endl;

    // 示例 2
    vector<int> nums2 = { 1, 2, 3, 4 };
    int k2 = 3;
    bool result2 = solution.canPartitionKSubsets(nums2, k2);
    cout << "示例 2 输出: " << (result2 ? "True" : "False") << endl;

    return 0;
}
