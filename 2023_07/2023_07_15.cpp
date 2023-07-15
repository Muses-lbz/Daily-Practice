#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result; // 存储结果的二维数组
        int n = nums.size();
        if (n < 4) {
            return result; // 数组长度小于4，直接返回空结果
        }

        sort(nums.begin(), nums.end()); // 对数组进行排序，便于后续处理

        for (int i = 0; i < n - 3; i++) { // 第一个数的循环
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // 跳过重复的第一个数
            }

            for (int j = i + 1; j < n - 2; j++) { // 第二个数的循环
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue; // 跳过重复的第二个数
                }

                int left = j + 1; // 左指针
                int right = n - 1; // 右指针

                while (left < right) { // 双指针遍历数组
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right]; // 计算四数之和

                    if (sum == target) { // 如果满足条件，将结果加入结果集
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });

                        while (left < right && nums[left] == nums[left + 1]) {
                            left++; // 跳过重复的左指针元素
                        }

                        while (left < right && nums[right] == nums[right - 1]) {
                            right--; // 跳过重复的右指针元素
                        }

                        left++; // 移动左指针
                        right--; // 移动右指针
                    }
                    else if (sum < target) {
                        left++; // 和小于目标值，左指针右移
                    }
                    else {
                        right--; // 和大于目标值，右指针左移
                    }
                }
            }
        }

        return result; // 返回结果集
    }
};

int main() {
    vector<int> nums = { 1, 0, -1, 0, -2, 2 }; // 输入数组
    int target = 0; // 目标值

    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, target);

    for (const auto& quad : result) {  // 遍历结果集，输出结果
        for (long long num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }


    return 0;
}
