//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    int maxSizeSlices(vector<int>& slices) {
//        int n = slices.size();
//        int k = n / 3;
//        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//
//        auto calculateMaxSum = [&](int start, int end) {
//            vector<int> slice(slices.begin() + start, slices.begin() + end);
//            int m = slice.size();
//            vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
//
//            for (int i = 1; i <= m; ++i) {
//                for (int j = 1; j <= k; ++j) {
//                    dp[i][j] = max(dp[i - 1][j], (i >= 2 ? dp[i - 2][j - 1] : 0) + slice[i - 1]);
//                }
//            }
//
//            return dp[m][k];
//            };
//
//        int maxSum1 = calculateMaxSum(0, n - 1);
//        int maxSum2 = calculateMaxSum(1, n);
//
//        return max(maxSum1, maxSum2);
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> slices = { 1, 2, 3, 4, 5, 6 };
//    cout << solution.maxSizeSlices(slices) << endl;
//    return 0;
//}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // 辅助函数：计算在一系列连续的披萨块中，选择不相邻的若干块所能得到的最大和
        auto calculateMaxSum = [&](int start, int end) {
            vector<int> slice(slices.begin() + start, slices.begin() + end);
            int m = slice.size();
            vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= k; ++j) {
                    // 选择当前披萨块或不选择，取较大值
                    dp[i][j] = max(dp[i - 1][j], (i >= 2 ? dp[i - 2][j - 1] : 0) + slice[i - 1]);
                }
            }

            return dp[m][k];
            };

        // 情况1：选择第一块披萨，不选择最后一块
        int maxSum1 = calculateMaxSum(0, n - 1);

        // 情况2：不选择第一块披萨，选择最后一块
        int maxSum2 = calculateMaxSum(1, n);

        // 返回两种情况下的较大值作为最终答案
        return max(maxSum1, maxSum2);
    }
};

int main() {
    Solution solution;
    vector<int> slices = { 1, 2, 3, 4, 5, 6 };
    cout << solution.maxSizeSlices(slices) << endl;
    return 0;
}
