#include <iostream>
#include <cstdlib>

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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        helper(root, moves);
        return moves;
    }

private:
    int helper(TreeNode* node, int& moves) {
        if (!node) {
            return 0;
        }

        int left_moves = helper(node->left, moves);
        int right_moves = helper(node->right, moves);

        moves += abs(left_moves) + abs(right_moves);
        int diff = node->val + left_moves + right_moves - 1;

        return diff;
    }
};

// 用于构建二叉树
TreeNode* buildTree(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    TreeNode* root = new TreeNode(val);
    root->left = left;
    root->right = right;
    return root;
}

int main() {
    // 构建测试用例
    TreeNode* root = buildTree(3,
        buildTree(0),
        buildTree(0)
    );

    Solution solution;
    int moves = solution.distributeCoins(root);
    std::cout << "Minimum moves: " << moves << std::endl;

    // 释放内存，防止内存泄漏
    // 这一步在实际问题中可能不需要，取决于具体情况
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
