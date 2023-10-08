#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划算法的实现
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        vector<int> cooldown(n, 0);

        buy[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            buy[i] = max(cooldown[i - 1] - prices[i], buy[i - 1]);
            sell[i] = buy[i - 1] + prices[i];
            cooldown[i] = max(sell[i - 1], cooldown[i - 1]);
        }

        return max(sell[n - 1], cooldown[n - 1]);
    }
};

int main() {
    // 输入股票价格数组
    vector<int> prices = { 1, 2, 3, 0, 2 };

    // 创建Solution对象
    Solution solution;

    // 调用maxProfit函数计算最大利润
    int maxProfit = solution.maxProfit(prices);

    // 输出结果
    cout << "最大利润为：" << maxProfit << endl;

    return 0;
}
