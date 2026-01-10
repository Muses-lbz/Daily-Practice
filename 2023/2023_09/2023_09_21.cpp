#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (const auto& edge : edges) {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
            ++degree[x];
            ++degree[y];
        }

        int rest = n;
        {
            /* 删除树中所有无金币的叶子节点，直到树中所有的叶子节点都是含有金币的 */
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (degree[i] == 1 && !coins[i]) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                --degree[u];
                q.pop();
                --rest;
                for (int v : g[u]) {
                    --degree[v];
                    if (degree[v] == 1 && !coins[v]) {
                        q.push(v);
                    }
                }
            }
        }
        {
            /* 删除树中所有的叶子节点, 连续删除2次 */
            for (int _ = 0; _ < 2; ++_) {
                queue<int> q;
                for (int i = 0; i < n; ++i) {
                    if (degree[i] == 1) {
                        q.push(i);
                    }
                }
                while (!q.empty()) {
                    int u = q.front();
                    --degree[u];
                    q.pop();
                    --rest;
                    for (int v : g[u]) {
                        --degree[v];
                    }
                }
            }
        }

        return rest == 0 ? 0 : (rest - 1) * 2;
    }
};

int main() {
    Solution solution;
    vector<int> coins = { 0, 0, 0, 1, 1, 0, 0, 1 };
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 6}, {5, 7} };
    int result = solution.collectTheCoins(coins, edges);
    cout << "最少经过的边数为: " << result << endl;
    return 0;
}
