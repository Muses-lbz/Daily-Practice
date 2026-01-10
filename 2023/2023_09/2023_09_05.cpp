//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_set>
//
//class Solution {
//public:
//    int minNumber(std::vector<int>& nums1, std::vector<int>& nums2) {
//        // 定义一个 lambda 函数 same 用于找到两个数组中共有的最小数字
//        auto same = [&]() -> int {
//            // 使用无序集合 unordered_set 存储 nums1 中的元素，以便快速查找
//            std::unordered_set<int> s(nums1.begin(), nums1.end());
//            int x = 10; // 初始值设置为 10，用于记录最小公共数字
//            // 遍历 nums2 中的元素
//            for (int num : nums2) {
//                // 如果在 s 中找到相同的元素
//                if (s.count(num)) {
//                    // 将它与当前最小的数字 x 进行比较，更新 x
//                    x = std::min(x, num);
//                }
//            }
//            return x == 10 ? -1 : x; // 如果 x 仍然是 10，则表示没有共有的最小数字
//            };
//
//        // 调用 same 函数，如果返回的最小公共数字不是 -1，则直接返回这个数字
//        int x = same();
//        if (x != -1) {
//            return x;
//        }
//
//        // 找到 nums1 中的最小数字 x 和 nums2 中的最小数字 y
//        int min_x = *std::min_element(nums1.begin(), nums1.end());
//        int min_y = *std::min_element(nums2.begin(), nums2.end());
//
//        // 返回 x 和 y 连接后的最小值
//        return std::min(min_x * 10 + min_y, min_y * 10 + min_x);
//    }
//};
//
//int main() {
//    // 示例输入
//    std::vector<int> nums1 = { 4, 1, 3 };
//    std::vector<int> nums2 = { 5, 7 };
//
//    // 创建 Solution 类的实例
//    Solution solution;
//
//    // 调用 minNumber 函数获取最小数字
//    int result = solution.minNumber(nums1, nums2);
//
//    // 输出结果
//    std::cout << "最小数字为: " << result << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Serialize a tree to a string
    std::string serialize(TreeNode* root) {
        if (!root) return "null"; // 如果节点为空，返回 "null"

        // 使用递归前序遍历生成字符串
        return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Deserialize a string to a tree
    TreeNode* deserialize(std::string data) {
        std::istringstream iss(data);
        return deserializeHelper(iss);
    }

private:
    // 辅助函数：从输入流中反序列化树
    TreeNode* deserializeHelper(std::istringstream& iss) {
        std::string token;
        std::getline(iss, token, ',');
        if (token == "null") return nullptr; // 如果遇到 "null"，返回空节点
        TreeNode* root = new TreeNode(std::stoi(token));
        root->left = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Codec codec;
    std::string serialized = codec.serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    std::cout << "Deserialized tree: " << deserialized->val << std::endl;

    return 0;
}
