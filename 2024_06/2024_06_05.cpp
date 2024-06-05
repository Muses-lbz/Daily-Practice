//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//void removeDuplicates(std::vector<int>& vec) {
//    // Step 1: 排序
//    std::sort(vec.begin(), vec.end());
//
//    // Step 2: 使用 std::unique 移动重复元素
//    auto uniqueEnd = std::unique(vec.begin(), vec.end());
//
//    // Step 3: 使用 erase 移除重复元素
//    vec.erase(uniqueEnd, vec.end());
//}
//
//int main() {
//    std::vector<int> vec = { 1, 2, 2, 3, 4, 4, 5, 1, 6 };
//
//    removeDuplicates(vec);
//
//    // 输出去重后的结果
//    for (int num : vec) {
//        std::cout << num << " ";
//    }
//
//    return 0;
//}

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class BinaryIndexedTree {
private:
    std::vector<int> tree; // 树状数组

public:
    // 构造函数，初始化树状数组
    BinaryIndexedTree(int n) : tree(n + 1) {}

    // 在索引 i 处添加一个元素
    void add(int i) {
        while (i < tree.size()) {
            tree[i] += 1;
            i += i & -i; // 更新索引，跳到父节点
        }
    }

    // 获取从 1 到 i 的元素和
    int get(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1; // 更新索引，跳到前一个节点
        }
        return res;
    }
};

class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        int n = (int)nums.size();

        // 创建排序后的 nums 副本
        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        // 创建值到索引的映射
        std::unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[sortedNums[i]] = i + 1;
        }

        // 初始化 arr1 和 arr2
        std::vector<int> arr1 = { nums[0] };
        std::vector<int> arr2 = { nums[1] };

        // 初始化树状数组
        BinaryIndexedTree tree1(n), tree2(n);
        tree1.add(index[nums[0]]);
        tree2.add(index[nums[1]]);

        // 遍历 nums 的剩余元素
        for (int i = 2; i < n; ++i) {
            int idx = index[nums[i]];
            int count1 = (int)(arr1.size() - tree1.get(idx)); // arr1 中严格大于 nums[i] 的数量
            int count2 = (int)(arr2.size() - tree2.get(idx)); // arr2 中严格大于 nums[i] 的数量

            // 根据规则将 nums[i] 添加到 arr1 或 arr2
            if (count1 > count2 || (count1 == count2 && arr1.size() <= arr2.size())) {
                arr1.push_back(nums[i]);
                tree1.add(idx);
            }
            else {
                arr2.push_back(nums[i]);
                tree2.add(idx);
            }
        }

        // 连接 arr1 和 arr2 形成最终结果
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};

int main() {
    // 测试用例
    std::vector<int> nums1 = { 2, 1, 3, 3 };
    std::vector<int> nums2 = { 5, 14, 3, 1, 2 };

    Solution solution;

    // 计算并输出结果
    std::vector<int> result1 = solution.resultArray(nums1);
    std::vector<int> result2 = solution.resultArray(nums2);

    std::cout << "Result for nums1: ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Result for nums2: ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
