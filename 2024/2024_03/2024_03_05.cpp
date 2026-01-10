#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // 定义取模值
        const long long MOD = (__int64)(1e9 + 7);
        // 建立图的邻接表表示
        vector<vector<pair<int, int>>> graph(n);
        // 记录到每个节点的最短距离
        vector<long long> dist(n, numeric_limits<long long>::max());
        // 记录到每个节点的最短路径数量
        vector<long long> ways(n);

        // 构建图的邻接表表示
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        // 记录节点是否已经访问过
        vector<bool> visited(n, false);
        // 起点到达自身的最短距离为0，路径数量为1
        dist[0] = 0;
        ways[0] = 1;

        // 使用Dijkstra算法计算最短路径数量
        for (int i = 0; i < n; ++i) {
            int u = -1;
            // 找到未访问节点中距离起点最近的节点
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            // 更新u的邻居节点的最短距离和路径数量
            for (auto& [v, time] : graph[u]) {
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u];
                }
                else if (dist[u] + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        // 返回终点的最短路径数量
        return (int)ways[n - 1];
    }
};

int main() {
    Solution solution;
    int n = 5;
    // 构建示例路网
    vector<vector<int>> roads = { {0,1,2},{0,2,4},{1,2,1},{1,3,7},{2,3,3},{2,4,5},{3,4,2} };
    // 计算最短路径数量
    int result = solution.countPaths(n, roads);
    cout << "从路口0到路口" << n - 1 << "的最短路径数量为：" << result << endl;
    return 0;
}
