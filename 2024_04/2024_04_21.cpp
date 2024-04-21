#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief 在数字1到9中找出所有相加之和为n的k个数的组合
     *
     * @param k 数字个数
     * @param n 目标和
     * @return vector<vector<int>> 返回所有可能的有效组合的列表
     */
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, k, n, 1);
        return result;
    }

private:
    /**
     * @brief 回溯函数，用于生成所有可能的组合
     *
     * @param result 存储结果的二维数组
     * @param current 当前组合
     * @param k 目标数字个数
     * @param remain 剩余目标和
     * @param start 起始数字
     */
    void backtrack(vector<vector<int>>& result, vector<int>& current, int k, int remain, int start) {
        // 如果目标和为0且当前组合长度为k，则将当前组合加入结果集
        if (remain == 0 && current.size() == k) {
            result.push_back(current);
            return;
        }

        // 如果剩余目标和小于0或者当前组合长度已经达到k，则返回
        if (remain < 0 || current.size() >= k) {
            return;
        }

        // 从start开始遍历数字
        for (int i = start; i <= 9; ++i) {
            current.push_back(i); // 将当前数字加入组合
            // 递归调用backtrack函数，继续寻找下一个数字
            backtrack(result, current, k, remain - i, i + 1);
            current.pop_back(); // 回溯，移除当前数字，继续尝试其他数字
        }
    }
};

int main() {
    Solution sol;

    // 示例测试
    int k1 = 3, n1 = 7;
    vector<vector<int>> res1 = sol.combinationSum3(k1, n1);
    cout << "k = " << k1 << ", n = " << n1 << endl;
    for (const auto& comb : res1) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    int k2 = 3, n2 = 9;
    vector<vector<int>> res2 = sol.combinationSum3(k2, n2);
    cout << "k = " << k2 << ", n = " << n2 << endl;
    for (const auto& comb : res2) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    int k3 = 4, n3 = 1;
    vector<vector<int>> res3 = sol.combinationSum3(k3, n3);
    cout << "k = " << k3 << ", n = " << n3 << endl;
    for (const auto& comb : res3) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
