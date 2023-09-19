#include <iostream>
#include <unordered_map>
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
    unordered_map<TreeNode*, int> memo;

    int rob(TreeNode* root) {
        if (!root) return 0;

        // 检查是否已经计算过当前节点
        if (memo.find(root) != memo.end()) {
            return memo[root];
        }

        // 偷取当前节点的金额
        int robCurrent = root->val;
        if (root->left) {
            robCurrent += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            robCurrent += rob(root->right->left) + rob(root->right->right);
        }

        // 不偷取当前节点的金额
        int skipCurrent = rob(root->left) + rob(root->right);

        // 更新memo并返回当前节点的最高金额
        memo[root] = max(robCurrent, skipCurrent);
        return memo[root];
    }
};

int main() {
    // 创建二叉树示例
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution solution;
    int result = solution.rob(root);
    cout << "小偷能够盗取的最高金额是：" << result << endl;

    // 释放动态分配的内存
    delete root->right->right;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
