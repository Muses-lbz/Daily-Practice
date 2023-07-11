//#include <iostream>
//#include <vector>
//#include <algorithm> //该头文件中包含了一系列的算法函数，如排序、查找、变换等。这些函数被广泛用于处理容器（如数组、向量、列表等）中的数据
//#include <climits> //是 C++ 标准库 <climits> 中定义的头文件，提供了对整数类型的极限值的定义
//
//using namespace std;
//
//class Solution {
//public:
//    int threeSumClosest(vector<int>& nums, int target) {
//        sort(nums.begin(), nums.end()); // 排序数组
//
//        int closestSum = INT_MAX; // 存储最接近的三数之和
//        int minDiff = INT_MAX; // 存储当前的最小差值
//
//        for (int i = 0; i < nums.size() - 2; i++) {
//            int left = i + 1; // 左指针从当前元素的下一个位置开始
//            int right = nums.size() - 1; // 右指针从数组末尾开始
//
//            while (left < right) {
//                int sum = nums[i] + nums[left] + nums[right]; // 当前三数之和
//                int diff = abs(sum - target); // 当前三数之和与目标值的差的绝对值
//
//                if (diff < minDiff) {
//                    minDiff = diff; // 更新最小差值
//                    closestSum = sum; // 更新最接近的三数之和
//                }
//
//                if (sum < target)
//                    left++; // 如果当前和小于目标值，移动左指针，以增加和的大小
//                else
//                    right--; // 如果当前和大于目标值，移动右指针，以减少和的大小
//            }
//        }
//
//        return closestSum; // 返回最接近的三数之和
//    }
//};
//
//int main() {
//    vector<int> nums = { -1, 2, 1, -4 };
//    int target = 1;
//
//    Solution solution;
//    int closestSum = solution.threeSumClosest(nums, target);
//
//    cout << "Closest sum: " << closestSum << endl;
//
//    system("pause"); // 在Windows上暂停程序，防止控制台窗口立即关闭
//    return 0;
//}

//#include <iostream>
//
//struct ListNode 
//{
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//bool hasCycle(ListNode* head)
//{
//    ListNode* slow = head;
//    ListNode* fast = head;
//
//    while (fast && fast->next) 
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        if (slow == fast)
//            return true;
//    }
//
//    return false;
//}
//
//// 示例链表
//// 1 -> 2 -> 3 -> 4 -> 2
//int main() {
//    ListNode* node1 = new ListNode(1);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(3);
//    ListNode* node4 = new ListNode(4);
//
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node2;
//
//    bool hasCycleResult = hasCycle(node1);
//    std::cout << std::boolalpha << hasCycleResult << std::endl;  // 输出：true
//
//    delete node1;
//    delete node2;
//    delete node3;
//    delete node4;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//int binarySearch(std::vector<int>& nums, int target) {
//    int left = 0;
//    int right = nums.size() - 1;
//
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//
//        if (nums[mid] == target)
//            return mid;
//        else if (nums[mid] < target)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//
//    return -1;
//}
//
//// 示例有序数组
//// [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//int main() {
//    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int target = 7;
//
//    int searchResult = binarySearch(nums, target);
//    std::cout << searchResult << std::endl;  // 输出：6
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//bool canJump(std::vector<int>& nums) {
//    int lastPos = nums.size() - 1; // 最后一个位置
//    for (int i = nums.size() - 2; i >= 0; i--) {
//        if (i + nums[i] >= lastPos) {
//            lastPos = i; // 更新最后一个位置
//        }
//    }
//    return lastPos == 0;
//}
//
//int main() {
//    std::vector<int> nums = { 2, 3, 1, 1, 4 };
//    bool result = canJump(nums);
//    std::cout << std::boolalpha << result << std::endl;  // 输出：true
//
//    nums = { 3, 2, 1, 0, 4 };
//    result = canJump(nums);
//    std::cout << std::boolalpha << result << std::endl;  // 输出：false
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

// 合并两个有序数组为一个有序数组
void merge(std::vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;  // 左侧子数组的长度
    int n2 = right - mid;     // 右侧子数组的长度

    std::vector<int> L(n1);   // 创建临时数组存放左侧子数组
    std::vector<int> R(n2);   // 创建临时数组存放右侧子数组

    // 将数据复制到临时数组 L 和 R
    for (int i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    // 归并临时数组 L 和 R 到原数组 nums
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        }
        else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素到原数组 nums
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序主函数
void mergeSort(std::vector<int>& nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // 计算中间位置

        // 分解为两个子问题
        mergeSort(nums, left, mid);            // 对左侧子数组进行排序
        mergeSort(nums, mid + 1, right);       // 对右侧子数组进行排序

        // 合并两个有序子数组
        merge(nums, left, mid, right);
    }
}

int main() {
    std::vector<int> nums = { 5, 2, 9, 1, 3, 6 };
    int n = nums.size();

    mergeSort(nums, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : nums)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
