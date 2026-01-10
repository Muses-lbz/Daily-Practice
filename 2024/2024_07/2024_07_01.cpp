#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        // 图的构建，使用邻接表表示
        int n = (int)values.size();
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], time = edge[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        int max_value = 0; // 存储最大路径价值
        vector<bool> visited(n, false); // 记录节点是否被访问过
        int current_time = 0;
        int current_value = values[0];

        // DFS函数定义
        function<void(int)> dfs = [&](int node) {
            // 如果在最大时间内回到起点，更新最大路径价值
            if (node == 0) {
                max_value = max(max_value, current_value);
            }

            // 遍历相邻节点
            for (const auto& [next_node, time] : graph[node]) {
                if (current_time + time <= maxTime) {
                    bool first_visit = !visited[next_node];
                    current_time += time;
                    if (first_visit) {
                        visited[next_node] = true;
                        current_value += values[next_node];
                    }

                    dfs(next_node);

                    if (first_visit) {
                        visited[next_node] = false;
                        current_value -= values[next_node];
                    }
                    current_time -= time;
                }
            }
            };

        visited[0] = true; // 起点0标记为已访问
        dfs(0); // 从节点0开始DFS
        return max_value; // 返回最大路径价值
    }
};

// 主函数
int main() {
    Solution solution;
    vector<int> values1 = { 0, 32, 10, 43 };
    vector<vector<int>> edges1 = { {0, 1, 10}, {1, 2, 15}, {0, 3, 10} };
    int maxTime1 = 49;
    cout << solution.maximalPathQuality(values1, edges1, maxTime1) << endl; // 输出 75

    vector<int> values2 = { 5, 10, 15, 20 };
    vector<vector<int>> edges2 = { {0, 1, 10}, {1, 2, 10}, {0, 3, 10} };
    int maxTime2 = 30;
    cout << solution.maximalPathQuality(values2, edges2, maxTime2) << endl; // 输出 25

    vector<int> values3 = { 1, 2, 3, 4 };
    vector<vector<int>> edges3 = { {0, 1, 10}, {1, 2, 11}, {2, 3, 12}, {1, 3, 13} };
    int maxTime3 = 50;
    cout << solution.maximalPathQuality(values3, edges3, maxTime3) << endl; // 输出 7

    vector<int> values4 = { 0, 1, 2 };
    vector<vector<int>> edges4 = { {1, 2, 10} };
    int maxTime4 = 10;
    cout << solution.maximalPathQuality(values4, edges4, maxTime4) << endl; // 输出 0

    return 0;
}
