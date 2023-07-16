#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> count(n, 1);  // 记录每个节点的子节点数量
        vector<int> sum(n, 0);    // 记录每个节点到其他节点的距离之和

        // 构建邻接表
        for (const auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 第一次DFS，计算每个节点的子节点数量和到其他节点的距离之和
        dfs1(0, -1, graph, count, sum);

        // 第二次DFS，计算每个节点到根节点的距离之和
        dfs2(0, -1, graph, count, sum, n);

        return sum;
    }

    void dfs1(int node, int parent, const vector<vector<int>>& graph, vector<int>& count, vector<int>& sum) {
        for (const auto& neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs1(neighbor, node, graph, count, sum);
                count[node] += count[neighbor];                                 // 更新节点的子节点数量
                sum[node] += sum[neighbor] + count[neighbor];                   // 更新节点到其他节点的距离之和
            }
        }
    }

    void dfs2(int node, int parent, const vector<vector<int>>& graph, const vector<int>& count, vector<int>& sum, int n) {
        for (const auto& neighbor : graph[node]) {
            if (neighbor != parent) {
                sum[neighbor] = sum[node] - count[neighbor] + (n - count[neighbor]);   // 更新节点到根节点的距离之和
                dfs2(neighbor, node, graph, count, sum, n);
            }
        }
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5} };
    vector<int> result = solution.sumOfDistancesInTree(n, edges);

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
