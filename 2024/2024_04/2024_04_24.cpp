#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <functional> // 添加此行

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // 构建无向图
        unordered_map<int, vector<int>> graph;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            for (TreeNode* child : vector<TreeNode*>{ node->left, node->right }) {
                if (child != nullptr) {
                    // 添加节点和其子节点到图中
                    graph[node->val].push_back(child->val);
                    graph[child->val].push_back(node->val);
                    dfs(child);
                }
            }
            };
        dfs(root);

        // BFS 遍历图
        queue<vector<int>> q;
        q.push({ start, 0 }); // 起始节点和其感染时间放入队列中
        unordered_set<int> visited;
        visited.insert(start);
        int time = 0;
        while (!q.empty()) {
            auto arr = q.front();
            q.pop();
            int nodeVal = arr[0];
            time = arr[1];
            for (int childVal : graph[nodeVal]) {
                if (!visited.count(childVal)) {
                    q.push({ childVal, time + 1 }); // 更新感染时间并放入队列
                    visited.insert(childVal);
                }
            }
        }
        return time;
    }
};

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = nullptr;
    root->right->right = new TreeNode(4);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    int start = 3; // 感染开始的节点值

    Solution solution;
    int minutes = solution.amountOfTime(root, start);

    cout << "感染整棵树需要 " << minutes << " 分钟" << endl;

    // 释放内存
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
