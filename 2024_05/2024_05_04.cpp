#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = (int)startTime.size();
		vector<vector<int>> jobs(n);
		for (int i = 0; i < n; i++) {
			jobs[i] = { startTime[i], endTime[i], profit[i] };
		}
		// 按照结束时间排序
		sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2) -> bool {
			return job1[1] < job2[1];
			});
		vector<int> dp(n + 1);
		for (int i = 1; i <= n; i++) {
			// 在时间点 jobs[i-1][0] 之前结束的工作的下标
			// 显式转换为 int 类型
			int k = static_cast<int>(upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
				return st < job[1];
				}) - jobs.begin());

			// 当前工作选择和不选择的最大报酬
			dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
		}
		return dp[n];
	}
};

int main() {
	vector<int> startTime = { 1, 2, 3, 4, 6 };
	vector<int> endTime = { 3, 5, 10, 6, 9 };
	vector<int> profit = { 20, 20, 100, 70, 60 };

	Solution solution;
	int maxProfit = solution.jobScheduling(startTime, endTime, profit);
	cout << "最大报酬：" << maxProfit << endl;

	return 0;
}
