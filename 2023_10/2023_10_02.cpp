#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;        // 初始最大利润为0
        int minPrice = prices[0]; // 初始最小买入价格为第一天的股价

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i]; // 更新最小买入价格
            }
            else {
                int profit = prices[i] - minPrice; // 计算当前卖出价格与最小买入价格的差值
                maxProfit += profit; // 更新最大利润
                minPrice = prices[i]; // 更新最小买入价格为当前股价，相当于在同一天买入卖出
            }
        }

        return maxProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    int maxProfit = solution.maxProfit(prices);

    cout << "最大利润为: " << maxProfit << endl;

    return 0;
}
