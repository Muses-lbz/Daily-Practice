#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int lower = *min_element(nums.begin(), nums.end()); // 窃取能力的最小可能值
        int upper = *max_element(nums.begin(), nums.end()); // 窃取能力的最大可能值

        while (lower <= upper) {
            int middle = (lower + upper) / 2; // 当前的窃取能力

            int count = 0; // 记录窃取的房屋数量
            bool visited = false; // 标记是否访问了一间房屋

            for (int x : nums) {
                if (x <= middle && !visited) {
                    count++;
                    visited = true;
                }
                else {
                    visited = false;
                }
            }

            if (count >= k) {
                upper = middle - 1; // 当前窃取能力过高，减小上界
            }
            else {
                lower = middle + 1; // 当前窃取能力过低，增大下界
            }
        }

        return lower; // 返回最小窃取能力
    }
};

int main() {
    // 测试数据
    vector<int> nums = { 2, 3, 5, 9 };
    int k = 2;

    Solution solution;
    int result = solution.minCapability(nums, k);

    cout << "最小窃取能力为: " << result << endl;

    return 0;
}
