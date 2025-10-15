#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 2) return 0;

        vector<int> inc(n, 1), dec(n, 1);

        // inc[i]: 以 nums[i] 结尾的最长递增长度
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }

        // dec[i]: 从 nums[i] 开始的最长递增长度
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i + 1] > nums[i]) {
                dec[i] = dec[i + 1] + 1;
            }
        }

        int ans = 0;
        // 枚举所有分界点（相邻两段之间）
        for (int i = 1; i < n; ++i) {
            // 左段是 [i - inc[i-1], i-1]
            // 右段是 [i, i + dec[i] - 1]
            ans = max(ans, min(inc[i - 1], dec[i]));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = { 2,5,7,8,9,2,3,4,3,1 };
    cout << "示例 1：" << endl;
    cout << "输入: [2,5,7,8,9,2,3,4,3,1]" << endl;
    cout << "输出: " << sol.maxIncreasingSubarrays(nums1) << endl << endl;

    vector<int> nums2 = { 1,2,3,4,4,4,4,5,6,7 };
    cout << "示例 2：" << endl;
    cout << "输入: [1,2,3,4,4,4,4,5,6,7]" << endl;
    cout << "输出: " << sol.maxIncreasingSubarrays(nums2) << endl << endl;

    return 0;
}
