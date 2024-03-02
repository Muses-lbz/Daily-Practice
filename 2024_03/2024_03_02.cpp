#include <iostream>
#include <vector>
#include <functional> // for std::function

using namespace std;

class Solution {
public:
    // 可达节点数计算函数
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // 标记受限节点
        vector<int> isrestricted(n);
        for (auto x : restricted) {
            isrestricted[x] = 1;
        }

        // 构建图的邻接表
        vector<vector<int>> g(n);
        for (auto& v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int cnt = 0; // 可达节点数
        // 深度优先搜索函数
        function<void(int, int)> dfs = [&](int x, int f) {
            cnt++; // 当前节点可达，计数加一
            for (auto& y : g[x]) {
                // 遍历相邻节点
                if (y != f && !isrestricted[y]) {
                    dfs(y, x); // 递归调用深度优先搜索
                }
            }
            };
        dfs(0, -1); // 从节点 0 开始深度优先搜索
        return cnt; // 返回可达节点数
    }
};

int main() {
    // 使用示例
    Solution solution;
    int n = 7;
    vector<vector<int>> edges = { {0,1},{1,2},{3,1},{4,0},{0,5},{5,6} };
    vector<int> restricted = { 4,5 };
    // 计算最大可达节点数
    int result = solution.reachableNodes(n, edges, restricted);
    cout << "从节点 0 可达的最大节点数: " << result << endl;

    return 0;
}