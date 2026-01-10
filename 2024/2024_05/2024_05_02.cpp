#include <iostream>

using namespace std;

// 树节点的定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 二叉树类的定义
class BinaryTree {
private:
    TreeNode* root;

    // 插入辅助函数
    TreeNode* insertRecursive(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode(data);
        }

        if (data < node->data) {
            node->left = insertRecursive(node->left, data);
        }
        else if (data > node->data) {
            node->right = insertRecursive(node->right, data);
        }

        return node;
    }

    // 搜索辅助函数
    bool searchRecursive(TreeNode* node, int data) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == data) {
            return true;
        }
        else if (data < node->data) {
            return searchRecursive(node->left, data);
        }
        else {
            return searchRecursive(node->right, data);
        }
    }

    // 中序遍历辅助函数
    void inorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // 插入操作
    void insert(int data) {
        root = insertRecursive(root, data);
    }

    // 搜索操作
    bool search(int data) {
        return searchRecursive(root, data);
    }

    // 中序遍历操作
    void inorderTraversal() {
        inorderTraversalRecursive(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    // 插入一些数据
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // 中序遍历
    cout << "Inorder Traversal: ";
    tree.inorderTraversal();

    // 搜索数据
    int searchData = 4;
    cout << "Search for " << searchData << ": ";
    if (tree.search(searchData)) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not Found" << endl;
    }

    return 0;
}
