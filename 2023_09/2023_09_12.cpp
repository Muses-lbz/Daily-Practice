#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 构建有向图，表示课程的先决条件
        unordered_map<int, unordered_set<int>> graph;
        for (const vector<int>& prereq : prerequisites) {
            graph[prereq[0]].insert(prereq[1]);
        }

        // 使用动态规划来计算所有课程的直接和间接先决条件
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; ++i) {
            dfs(graph, isPrerequisite, i, i);
        }

        // 对每个查询进行答案计算
        vector<bool> result;
        for (const vector<int>& query : queries) {
            result.push_back(isPrerequisite[query[0]][query[1]]);
        }

        return result;
    }

private:
    void dfs(unordered_map<int, unordered_set<int>>& graph, vector<vector<bool>>& isPrerequisite, int source, int current) {
        // 如果已经计算过当前课程是先决条件，直接返回
        if (isPrerequisite[source][current]) {
            return;
        }

        // 标记当前课程为先决条件
        isPrerequisite[source][current] = true;

        // 递归查找当前课程的所有直接和间接先决条件
        for (int neighbor : graph[current]) {
            dfs(graph, isPrerequisite, source, neighbor);
        }
    }
};

int main() {
    Solution solution;
    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1, 0}, {2, 1}, {3, 2} };
    vector<vector<int>> queries = { {0, 1}, {1, 3}, {3, 0}, {0, 2} };

    vector<bool> result = solution.checkIfPrerequisite(numCourses, prerequisites, queries);

    // 打印查询结果
    for (bool res : result) {
        if (res) {
            cout << "是先决条件" << endl;
        }
        else {
            cout << "不是先决条件" << endl;
        }
    }

    return 0;
}
