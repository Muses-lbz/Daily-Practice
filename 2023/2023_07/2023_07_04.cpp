//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//// 比较函数，用于排序
//static int cmp(const void* a, const void* b)
//{
//    return *(int*)a - *(int*)b;
//}
//
//// 计算二维数组中最大值之和的函数
//int matrixSum(int** nums, int numsSize, int* numsColSize)
//{
//    int res = 0;
//    int m = numsSize; // 行数
//    int n = numsColSize[0]; // 列数
//
//    // 对每一行进行排序
//    for (int i = 0; i < m; i++)
//    {
//        qsort(nums[i], n, sizeof(int), cmp);
//    }
//
//    // 计算每一列的最大值之和
//    for (int j = 0; j < n; j++)
//    {
//        int maxVal = 0;
//        for (int i = 0; i < m; i++)
//        {
//            maxVal = (int)fmax(maxVal, nums[i][j]);
//        }
//        res += maxVal;
//    }
//
//    return res;
//}
//
//int main()
//{
//    int numsSize = 4;
//    int numsColSize[] = { 3, 3, 3, 3 };
//
//    // 动态分配二维数组的内存空间
//    int** nums = (int**)malloc(numsSize * sizeof(int*));
//    if (nums == NULL) {
//        printf("Memory allocation failed.\n");
//        return 1;
//    }
//    for (int i = 0; i < numsSize; i++) {
//        nums[i] = (int*)malloc(numsColSize[i] * sizeof(int));
//        if (nums[i] == NULL) {
//            printf("Memory allocation failed.\n");
//            return 1;
//        }
//    }
//
//    // 手动赋值给 nums 数组的元素
//    nums[0][0] = 7;
//    nums[0][1] = 2;
//    nums[0][2] = 1;
//    nums[1][0] = 6;
//    nums[1][1] = 4;
//    nums[1][2] = 2;
//    nums[2][0] = 6;
//    nums[2][1] = 5;
//    nums[2][2] = 3;
//    nums[3][0] = 3;
//    nums[3][1] = 2;
//    nums[3][2] = 1;
//
//    int result = matrixSum(nums, numsSize, numsColSize);
//    printf("Result: %d\n", result);
//
//    // 释放动态分配的内存
//    for (int i = 0; i < numsSize; i++) {
//        free(nums[i]);
//    }
//    free(nums);
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct ListNode 
//{
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution 
//{
//public:
//	// 反转链表的函数
//	ListNode* reverseList(ListNode* head)
//	{
//		ListNode* prev = nullptr;
//		ListNode* curr = head;
//		while (curr)
//		{
//			ListNode* next = curr->next;
//			curr->next = prev;
//			prev = curr;
//			curr = next;
//		}
//		return prev;
//	}
//	// 将两个链表相加的函数
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//	{
//		l1 = reverseList(l1);
//		l2 = reverseList(l2);
//		ListNode* dummyHead = new ListNode(0); // 创建一个虚拟头节点
//		ListNode* curr = dummyHead; // 当前节点指针
//		int carry = 0; // 进位值
//
//		while (l1 || l2 || carry) 
//		{
//			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry; // 当前位置的数字之和
//			carry = sum / 10; // 计算进位值
//			curr->next = new ListNode(sum % 10); // 创建新节点存储相加结果的个位数
//			curr = curr->next; // 更新当前节点指针
//
//			// 更新 l1 和 l2 的指针
//			if (l1) l1 = l1->next;
//			if (l2) l2 = l2->next;
//		}
//
//		return reverseList(dummyHead->next); // 返回结果链表的头节点
//	}
//};
//
//// 打印链表的函数
//void printList(ListNode* head) 
//{
//	ListNode* curr = head;
//	while (curr) 
//	{
//		cout << curr->val << " ";
//		curr = curr->next;
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	Solution obj;
//
//	// 创建链表 l1: 7->2->4->3
//	ListNode* l1 = new ListNode(7);
//	l1->next = new ListNode(2);
//	l1->next->next = new ListNode(4);
//	l1->next->next->next = new ListNode(3);
//
//	// 创建链表 l2: 5->6->4
//	ListNode* l2 = new ListNode(5);
//	l2->next = new ListNode(6);
//	l2->next->next = new ListNode(4);
//
//	// 将两个链表相加
//	ListNode* result = obj.addTwoNumbers(l1, l2);
//
//	// 打印结果链表
//	cout << "Result: ";
//	printList(result);
//
//	// 释放内存
//	ListNode* curr = nullptr;
//	while (result) 
//	{
//		curr = result;
//		result = result->next;
//		delete curr;
//	}
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* dummyHead = new ListNode(0);
//        ListNode* curr = dummyHead;
//        int carry = 0;
//
//        while (l1 || l2 || carry) {
//            int sum = carry;
//            if (l1) {
//                sum += l1->val;
//                l1 = l1->next;
//            }
//            if (l2) {
//                sum += l2->val;
//                l2 = l2->next;
//            }
//
//            carry = sum / 10;
//            curr->next = new ListNode(sum % 10);
//            curr = curr->next;
//        }
//
//        return dummyHead->next;
//    }
//};
//
//// 创建链表的辅助函数
//ListNode* createList(int arr[], int n) {
//    ListNode* dummyHead = new ListNode(0);
//    ListNode* curr = dummyHead;
//    for (int i = 0; i < n; i++) {
//        curr->next = new ListNode(arr[i]);
//        curr = curr->next;
//    }
//    return dummyHead->next;
//}
//
//// 打印链表的函数
//void printList(ListNode* head) {
//    ListNode* curr = head;
//    while (curr) {
//        cout << curr->val << " ";
//        curr = curr->next;
//    }
//    cout << endl;
//}
//
//int main() {
//    Solution obj;
//
//    int arr1[] = { 2, 4, 3 };
//    int arr2[] = { 5, 6, 4 };
//    int n1 = sizeof(arr1) / sizeof(arr1[0]);
//    int n2 = sizeof(arr2) / sizeof(arr2[0]);
//
//    // 创建链表 l1 和 l2
//    ListNode* l1 = createList(arr1, n1);
//    ListNode* l2 = createList(arr2, n2);
//
//    // 将链表相加并获取结果链表
//    ListNode* result = obj.addTwoNumbers(l1, l2);
//
//    // 将结果链表逆序输出
//    printList(result);
//
//    // 释放内存
//    ListNode* curr = nullptr;
//    while (result) {
//        curr = result;
//        result = result->next;
//        delete curr;
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> numMap;  // 创建一个哈希表，用于存储数组元素和对应的索引

        // 遍历数组元素
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // 计算目标值与当前元素的差值

            // 检查哈希表中是否存在与当前元素配对的数字
            // 如果存在，则找到了符合条件的两个数，将它们的索引存入结果数组
            if (numMap.count(complement) && numMap[complement] != i) {
                result.push_back(i);
                result.push_back(numMap[complement]);
                break;
            }

            // 将当前元素及其索引存储到哈希表中
            numMap[nums[i]] = i;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> indices = obj.twoSum(nums, target);

    cout << "Indices: ";
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}