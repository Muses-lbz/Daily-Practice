#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 主函数：返回最多能采摘多少个连续的水果（只用两个篮子）
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // 记录篮子中每种水果的数量
        int left = 0;                   // 滑动窗口左指针
        int maxFruits = 0;              // 记录最多能采摘的水果数

        // 遍历所有的树（即数组中的水果）
        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++; // 当前水果加入篮子

            // 如果篮子中水果种类超过2种，就收缩左边界
            while (basket.size() > 2) {
                basket[fruits[left]]--;      // 移除左边水果
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]); // 数量为0就彻底移除这种水果
                }
                ++left; // 左指针右移
            }

            // 更新最大采摘数量
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};

// 主函数：用于测试
int main() {
    Solution sol;

    // 示例1
    vector<int> fruits1 = { 1, 2, 1 };
    cout << "最多可采摘水果数量: " << sol.totalFruit(fruits1) << endl; // 输出3

    // 示例2
    vector<int> fruits2 = { 0, 1, 2, 2 };
    cout << "最多可采摘水果数量: " << sol.totalFruit(fruits2) << endl; // 输出3

    // 示例3
    vector<int> fruits3 = { 1, 2, 3, 2, 2 };
    cout << "最多可采摘水果数量: " << sol.totalFruit(fruits3) << endl; // 输出4

    // 示例4（自定义）
    vector<int> fruits4 = { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 };
    cout << "最多可采摘水果数量: " << sol.totalFruit(fruits4) << endl; // 输出5

    return 0;
}
