#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0; // 记录老板不使用技巧时满意顾客的数量
        int extraSatisfied = 0; // 记录老板使用技巧后额外的满意顾客数量
        int maxExtraSatisfied = 0; // 记录滑动窗口内的最大额外满意顾客数量
        int n = (int)customers.size();

        // 计算老板不使用技巧时满意顾客的数量
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        // 滑动窗口计算额外满意顾客数量
        int left = 0, right = 0;
        while (right < n) {
            // 如果窗口大小大于 minutes，则左边界右移
            if (right - left >= minutes) {
                if (grumpy[left] == 1) {
                    extraSatisfied -= customers[left];
                }
                ++left;
            }

            // 如果当前分钟老板生气，则累加额外满意顾客数量
            if (grumpy[right] == 1) {
                extraSatisfied += customers[right];
            }

            // 更新滑动窗口内的最大额外满意顾客数量
            maxExtraSatisfied = max(maxExtraSatisfied, extraSatisfied);

            ++right;
        }

        // 返回老板不使用技巧时满意顾客数量与使用技巧后最大额外满意顾客数量的总和
        return satisfied + maxExtraSatisfied;
    }
};

int main() {
    Solution solution;
    vector<int> customers = { 1, 0, 1, 2, 1, 1, 7, 5 };
    vector<int> grumpy = { 0, 1, 0, 1, 0, 1, 0, 1 };
    int minutes = 3;
    int maxSatisfied = solution.maxSatisfied(customers, grumpy, minutes);
    cout << "最多有 " << maxSatisfied << " 客户感到满意。" << endl;
    return 0;
}
