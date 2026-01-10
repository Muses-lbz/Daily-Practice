//#include <iostream>
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//        if (root1 == nullptr) {
//            return root2;
//        }
//        if (root2 == nullptr) {
//            return root1;
//        }
//
//        TreeNode* mergedNode = new TreeNode(root1->val + root2->val);
//        mergedNode->left = mergeTrees(root1->left, root2->left);
//        mergedNode->right = mergeTrees(root1->right, root2->right);
//
//        return mergedNode;
//    }
//};
//
//// Helper function to print the merged tree
//void printTree(TreeNode* root) {
//    if (root == nullptr) {
//        return;
//    }
//    std::cout << root->val << " ";
//    printTree(root->left);
//    printTree(root->right);
//}
//
//int main() {
//    Solution solution;
//
//    // Example trees
//    TreeNode* root1 = new TreeNode(1);
//    root1->left = new TreeNode(3);
//    root1->right = new TreeNode(2);
//    root1->left->left = new TreeNode(5);
//
//    TreeNode* root2 = new TreeNode(2);
//    root2->left = new TreeNode(1);
//    root2->right = new TreeNode(3);
//    root2->left->right = new TreeNode(4);
//    root2->right->right = new TreeNode(7);
//
//    TreeNode* mergedTree = solution.mergeTrees(root1, root2);
//
//    std::cout << "Merged Tree: ";
//    printTree(mergedTree);
//
//    return 0;
//}

//#include <iostream>
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//        // 如果 root1 为空，返回 root2，表示将 root2 合并到 root1 上
//        if (root1 == nullptr) {
//            return root2;
//        }
//        // 如果 root2 为空，返回 root1，表示将 root1 合并到 root2 上
//        if (root2 == nullptr) {
//            return root1;
//        }
//
//        // 创建新节点，值为两个节点值相加
//        TreeNode* mergedNode = new TreeNode(root1->val + root2->val);
//
//        // 递归地合并左子树和右子树
//        mergedNode->left = mergeTrees(root1->left, root2->left);
//        mergedNode->right = mergeTrees(root1->right, root2->right);
//
//        return mergedNode;
//    }
//};
//
//// 辅助函数用于打印树的内容
//void printTree(TreeNode* root) {
//    if (root == nullptr) {
//        return;
//    }
//    std::cout << root->val << " ";
//    printTree(root->left);
//    printTree(root->right);
//}
//
//int main() {
//    Solution solution;
//
//    // 示例树
//    TreeNode* root1 = new TreeNode(1);
//    root1->left = new TreeNode(3);
//    root1->right = new TreeNode(2);
//    root1->left->left = new TreeNode(5);
//
//    TreeNode* root2 = new TreeNode(2);
//    root2->left = new TreeNode(1);
//    root2->right = new TreeNode(3);
//    root2->left->right = new TreeNode(4);
//    root2->right->right = new TreeNode(7);
//
//    // 合并树
//    TreeNode* mergedTree = solution.mergeTrees(root1, root2);
//
//    std::cout << "合并后的树内容: ";
//    printTree(mergedTree);
//
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char ch[80] = "123abcdEFG*&";
//	int j;
//	puts(ch);
//	for (j = 0; ch[j] != '\0'; j++)
//		if (ch[j] >= 'A' && ch[j] <= 'Z')
//			ch[j] = ch[j] + 'e' - 'E';
//	puts(ch);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if (ch % 2 != 0 && (ch >= 'a' && ch <= 'z'))
//			ch = ch - 'a' + 'A';
//		putchar(ch);
//	}
//	printf("\n");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int findFirstOccurrence(int* data, int dataLen, int target) {
//    int left = 0;
//    int right = dataLen - 1;
//    int result = -1;
//
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (data[mid] == target) {
//            result = mid;
//            right = mid - 1;
//        }
//        else if (data[mid] < target) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//
//    return result;
//}
//
//int findLastOccurrence(int* data, int dataLen, int target) {
//    int left = 0;
//    int right = dataLen - 1;
//    int result = -1;
//
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (data[mid] == target) {
//            result = mid;
//            left = mid + 1;
//        }
//        else if (data[mid] < target) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//
//    return result;
//}
//
//int GetNumberOfK(int* data, int dataLen, int k) {
//    int firstIdx = findFirstOccurrence(data, dataLen, k);
//    int lastIdx = findLastOccurrence(data, dataLen, k);
//
//    if (firstIdx != -1 && lastIdx != -1) {
//        return lastIdx - firstIdx + 1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int main() {
//    int n, k;
//    printf("Enter the number of elements: ");
//    scanf_s("%d", &n);
//
//    int* data = (int*)malloc(n * sizeof(int));
//    if (data == NULL) {
//        printf("Memory allocation failed.\n");
//        return 1; // 返回非零表示错误
//    }
//
//    printf("Enter the elements: ");
//    for (int i = 0; i < n; ++i) {
//        scanf_s("%d", &data[i]);
//    }
//
//    printf("Enter the value to count: ");
//    scanf_s("%d", &k);
//
//    int result = GetNumberOfK(data, n, k);
//    printf("Number of occurrences of %d: %d\n", k, result);
//
//    return 0;
//}

//#include <stdio.h>
//
//int dominantIndex(int* nums, int numsSize) {
//    int maxIndex = 0;
//    int maxVal = nums[0];
//
//    // 找到最大值和对应的索引
//    for (int i = 1; i < numsSize; ++i) {
//        if (nums[i] > maxVal) {
//            maxVal = nums[i];
//            maxIndex = i;
//        }
//    }
//
//    // 检查最大值是否至少是其他数字的两倍
//    for (int i = 0; i < numsSize; ++i) {
//        if (i != maxIndex && nums[i] * 2 > maxVal) {
//            return -1; // 不满足条件，返回 -1
//        }
//    }
//
//    return maxIndex;
//}
//
//int main() {
//    int nums[] = { 3, 6, 1, 0 };
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//
//    int result = dominantIndex(nums, numsSize);
//    if (result != -1) {
//        printf("The dominant index is: %d\n", result);
//    }
//    else {
//        printf("No dominant index found.\n");
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	qsort(nums1, nums1Size, sizeof(int), compare);
	qsort(nums2, nums2Size, sizeof(int), compare);

	int* result = (int*)malloc(sizeof(int) * nums1Size); // 最多可能有nums1Size个交集元素
	int resultSize = 0;

	int i = 0, j = 0;

	while (i < nums1Size && j < nums2Size) {
		if (nums1[i] < nums2[j]) {
			i++;
		}
		else if (nums1[i] > nums2[j]) {
			j++;
		}
		else {
			if (resultSize == 0 || nums1[i] != result[resultSize - 1]) {
				if (result == NULL)
				{

				}
				else
				{
					result[resultSize++] = nums1[i];
				}

			}
			i++;
			j++;
		}
	}

	*returnSize = resultSize;
	return result;
}

int main() {
	int nums1[] = { 1, 2, 2, 1 };
	int nums2[] = { 2, 2 };
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	int returnSize = 0;
	int* result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

	printf("Intersection: ");
	for (int i = 0; i < returnSize; ++i) {
		printf("%d ", result[i]);
	}
	printf("\n");

	free(result);

	return 0;
}

