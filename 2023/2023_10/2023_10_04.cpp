#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k <= 0) return 0;

        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int j = 1; j <= k; j++) {
            int buy = prices[0];
            for (int i = 1; i < n; i++) {
                buy = min(buy, prices[i] - dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i - 1][j], prices[i] - buy);
            }
        }

        return dp[n - 1][k];
    }
};

int main() {
    Solution solution;
    int k = 2;
    vector<int> prices = { 2, 4, 1 };
    int maxProfit = solution.maxProfit(k, prices);

    cout << "最大利润为: " << maxProfit << endl;

    return 0;
}
