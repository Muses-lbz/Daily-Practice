#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // 首先对数组进行排序
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // 遍历数组，固定一个数作为第一个元素
        for (int i = 0; i < n - 2; i++) {
            // 如果当前数与前一个数相等，跳过，避免重复解
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i]; // 目标和为0，所以需要找到两个数使得它们的和等于-target

            int left = i + 1; // 左指针指向当前数的下一个数
            int right = n - 1; // 右指针指向数组末尾

            // 在左指针和右指针之间进行搜索
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target) {
                    left++; // 和小于目标值，左指针右移
                }
                else if (sum > target) {
                    right--; // 和大于目标值，右指针左移
                }
                else {
                    // 找到满足条件的三元组
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // 跳过重复的数
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // 移动指针继续搜索下一个可能的解
                    left++;
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = { -1, 0, 1, 2, -1, -4 };

    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    // 输出结果
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
