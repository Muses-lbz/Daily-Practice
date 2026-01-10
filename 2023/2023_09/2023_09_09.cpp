#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建图和入度数组
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0)); // 二维数组表示课程之间的依赖关系
        vector<int> indegree(numCourses, 0); // 一维数组表示每门课程的入度

        // 遍历 prerequisites 数组，填充图和入度数组
        for (const vector<int>& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            graph[prerequisite][course] = 1; // 有依赖关系的课程在图中标记为1
            indegree[course]++; // 被依赖课程的入度加1
        }

        queue<int> q; // 创建队列用于拓扑排序

        // 将入度为0的课程加入队列
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // 记录已学习的课程数量

        // 开始拓扑排序
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            // 遍历所有课程，更新入度
            for (int i = 0; i < numCourses; i++) {
                if (graph[course][i] == 1) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }

        // 如果已学习的课程数量等于总课程数，返回 true；否则，返回 false。
        return count == numCourses;
    }
};

int main() {
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = { {1, 0} };
    bool result = solution.canFinish(numCourses, prerequisites);
    if (result) {
        cout << "可以完成所有课程的学习。" << endl;
    }
    else {
        cout << "无法完成所有课程的学习。" << endl;
    }
    return 0;
}
