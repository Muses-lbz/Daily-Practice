#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        // 计算总子数组数目的中位数位置
        long long median = ((long long)n * (n + 1) / 2 + 1) / 2;

        // 定义检查函数，检测数组中不同元素数目小于等于 t 的连续子数组数目是否大于等于 median
        auto check = [&](int t) -> bool {
            unordered_map<int, int> cnt; // 哈希表用于统计窗口内元素出现的次数
            long long tot = 0; // 统计符合条件的子数组数目
            for (int i = 0, j = 0; i < n; i++) {
                cnt[nums[i]]++; // 右边界元素加入窗口
                // 当窗口内的不同元素数目超过 t 时，移动左边界
                while (cnt.size() > t) {
                    cnt[nums[j]]--; // 移除左边界元素
                    if (cnt[nums[j]] == 0) {
                        cnt.erase(nums[j]); // 如果元素计数为 0，移除该元素
                    }
                    j++;
                }
                tot += i - j + 1; // 计算以 i 为右边界的符合条件的子数组数目
            }
            return tot >= median; // 判断是否满足中位数条件
            };

        int res = 0; // 最终结果
        int lo = 1, hi = n; // 二分查找的范围
        while (lo <= hi) {
            int mid = (lo + hi) / 2; // 计算中间值            
            if (check(mid)) {
                res = mid; // 更新结果
                hi = mid - 1; // 缩小右边界
            }
            else {
                lo = mid + 1; // 缩小左边界
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例输入
    vector<int> nums = { 1, 2, 3 };

    // 计算唯一性数组的中位数并输出
    int result = solution.medianOfUniquenessArray(nums);
    cout << "唯一性数组的中位数为: " << result << endl; // 输出结果

    return 0;
}
