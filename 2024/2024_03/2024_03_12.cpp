#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class FindElements {
private:
    unordered_set<int> elements; // 用于存储还原后的二叉树中的所有元素值

    // 递归地还原二叉树
    void recoverTree(TreeNode* root, int val) {
        if (root == nullptr) return;
        root->val = val; // 设置当前节点的值
        elements.insert(val); // 将当前节点的值存入集合中
        recoverTree(root->left, 2 * val + 1); // 递归处理左子节点
        recoverTree(root->right, 2 * val + 2); // 递归处理右子节点
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0); // 在构造函数中调用 recoverTree 方法，初始化元素集合
    }

    // 查找目标值是否存在于还原后的二叉树中
    bool find(int target) {
        return elements.find(target) != elements.end(); // 检查目标值是否在集合中
    }
};

int main() {
    vector<bool> results; // 存储查找结果

    // 示例输入
    TreeNode* root = new TreeNode(-1);
    root->right = new TreeNode(-1);

    FindElements* findElements = new FindElements(root);

    // 调用 find 方法并记录结果
    results.push_back(findElements->find(1));
    results.push_back(findElements->find(2));

    // 输出结果
    cout << "Output: [";
    for (bool result : results) {
        cout << (result ? "true" : "false") << ",";
    }
    cout << "]" << endl;

    return 0;
}