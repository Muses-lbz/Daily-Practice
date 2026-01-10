#include <iostream>
#include <vector>
#include <utility>

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
    pair<TreeNode*, int> findLCA(TreeNode* root) {
        if (!root)
            return { nullptr, 0 };

        auto left = findLCA(root->left);
        auto right = findLCA(root->right);

        if (left.second > right.second)
            return { left.first, left.second + 1 };
        else if (left.second < right.second)
            return { right.first, right.second + 1 };
        else
            return { root, left.second + 1 };
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto result = findLCA(root);
        return result.first;
    }
};

// Helper function to create a binary tree from an array
TreeNode* createTree(vector<int>& values, int index) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

int main() {
    // Example input: [3,5,1,6,2,0,8,null,null,7,4]
    vector<int> values = { 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4 };

    // Create the binary tree from the input array
    TreeNode* root = createTree(values, 0);

    Solution solution;
    TreeNode* result = solution.lcaDeepestLeaves(root);

    cout << "The lowest common ancestor of deepest leaves is: " << result->val << endl;

    // Clean up the dynamically allocated memory
    delete root;

    return 0;
}
