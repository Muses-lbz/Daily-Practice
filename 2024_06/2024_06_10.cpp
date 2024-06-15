#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        // 按利润从大到小排序
        sort(items.begin(), items.end(), [&](const vector<int>& item1, const vector<int>& item2) -> bool {
            return item1[0] > item2[0];
            });

        unordered_set<int> categorySet;
        long long res = 0, profit = 0;
        stack<int> st;

        // 选择前 k 个项目
        for (int i = 0; i < k; i++) {
            profit += items[i][0];
            if (categorySet.count(items[i][1]) == 0) {
                categorySet.insert(items[i][1]);
            }
            else {
                st.push(items[i][0]);
            }
        }

        // 初始优雅度
        res = profit + (long long)categorySet.size() * categorySet.size();

        // 尝试用剩余的项目进行替换以增加类别
        for (int i = k; i < items.size(); i++) {
            int profitValue = items[i][0];
            int category = items[i][1];

            // 如果当前类别不存在于选取的项目中，并且堆栈中有项目可以替换
            if (categorySet.count(category) == 0 && !st.empty()) {
                profit += profitValue - st.top();
                st.pop();
                categorySet.insert(category);

                // 计算新的优雅度并更新最大优雅度
                long long current_elegance = profit + (long long)categorySet.size() * categorySet.size();
                res = max(res, current_elegance);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> items = { {3, 2}, {3, 1} };
    int k = 1;
    cout << sol.findMaximumElegance(items, k) << endl;  // 预期输出：4
    return 0;
}
