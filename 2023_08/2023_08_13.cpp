//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int i = m - 1;  // Pointer for nums1
//        int j = n - 1;  // Pointer for nums2
//        int idx = m + n - 1;  // Pointer for merged array
//
//        while (i >= 0 && j >= 0) {
//            if (nums1[i] >= nums2[j]) {
//                nums1[idx] = nums1[i];
//                i--;
//            }
//            else {
//                nums1[idx] = nums2[j];
//                j--;
//            }
//            idx--;
//        }
//
//        // If there are remaining elements in nums2
//        while (j >= 0) {
//            nums1[idx] = nums2[j];
//            j--;
//            idx--;
//        }
//    }
//};
//
//int main() {
//    Solution solution;
//
//    vector<int> nums1 = { 8, 9, 9, 0, 0, 0 };
//    vector<int> nums2 = { 2, 5, 6 };
//    int m = 3;
//    int n = 3;
//
//    solution.merge(nums1, m, nums2, n);
//
//    cout << "Merged Array: ";
//    for (int num : nums1) {
//        cout << num << " ";
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int i = m - 1;  // nums1 的指针
//        int j = n - 1;  // nums2 的指针
//        int idx = m + n - 1;  // 合并后数组的指针
//
//        while (i >= 0 && j >= 0) {
//            if (nums1[i] >= nums2[j]) {
//                nums1[idx] = nums1[i];  // 把较大的元素放入合并后的数组
//                i--;  // 移动 nums1 指针
//            }
//            else {
//                nums1[idx] = nums2[j];  // 把较大的元素放入合并后的数组
//                j--;  // 移动 nums2 指针
//            }
//            idx--;  // 移动合并后数组的指针
//        }
//
//        // 如果 nums2 中还有剩余元素
//        while (j >= 0) {
//            nums1[idx] = nums2[j];  // 把剩余的 nums2 元素放入合并后的数组
//            j--;  // 移动 nums2 指针
//            idx--;  // 移动合并后数组的指针
//        }
//    }
//};
//
//int main() {
//    Solution solution;
//
//    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
//    vector<int> nums2 = { 8, 8, 8 };
//    int m = 3;
//    int n = 3;
//
//    solution.merge(nums1, m, nums2, n);
//
//    cout << "合并后的数组: ";
//    for (int num : nums1) {
//        cout << num << " ";
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//int x = 5, y = 7;
//
//int swap(int x, int y)
//{
//	int z;
//	z = x;
//	x = y;
//	y = z;
//	printf("%d,%d\n", x,y);
//	return x, y;
//}
//int main()
//{
//	int x = 3, y = 8; 
//	swap(x,y);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int* printNumbers(int n, int* returnSize) {
//    // 计算最大的 n 位数
//    int maxNumber = 1;
//    for (int i = 0; i < n; i++) {
//        maxNumber *= 10;
//    }
//    maxNumber--;
//
//    // 分配内存以保存整数列表
//    int* numbers = (int*)malloc(maxNumber * sizeof(int));
//    if (numbers == NULL) {
//        *returnSize = 0;
//        return NULL;  // 内存分配失败
//    }
//
//    // 填充整数列表
//    for (int i = 0; i < maxNumber; i++) {
//        numbers[i] = i + 1;
//    }
//
//    *returnSize = maxNumber;
//    return numbers;
//}
//
//int main() {
//    int n = 3;
//    int returnSize;
//
//    int* numbers = printNumbers(n, &returnSize);
//
//    if (numbers != NULL) {
//        printf("List of numbers from 1 to %d-digit maximum:\n", n);
//        for (int i = 0; i < returnSize; i++) {
//            printf("%d ", numbers[i]);
//        }
//        printf("\n");
//
//        free(numbers);  // 释放动态分配的内存
//    }
//    else {
//        printf("Memory allocation failed.\n");
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//// 判断是否为闰年
//int isLeapYear(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//
//// 计算日期是一年中的第几天
//int dayOfYear(int year, int month, int day) {
//    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//    // 考虑闰年的2月
//    if (isLeapYear(year)) {
//        daysInMonth[2] = 29;
//    }
//
//    int totalDays = 0;
//    for (int i = 1; i < month; i++) {
//        totalDays += daysInMonth[i];
//    }
//    totalDays += day;
//
//    return totalDays;
//}
//
//int main() {
//    int year, month, day;
//    printf("请输入年份、月份和日期（以空格分隔）：");
//    scanf_s("%d %d %d", &year, &month, &day);
//
//    int result = dayOfYear(year, month, day);
//    printf("该日期是一年中的第 %d 天。\n", result);
//
//    return 0;
//}

//#include<stdio.h>
//#include <string.h>
//
//int main()
//{
//	char s[] = "\\123456\123456\n";
//	printf("%s", s);
//	printf("%d\n", (int)strlen(s));
//	return 0;
//}

//#include <stdio.h>
//#define N 2
//#define M N + 1
//#define NUM (M + 1) * M / 2
//int main()
//{
//	printf("%d\n", NUM);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int f(int n)
//{
//    int i = 1;
//    if (n >= 5)
//        return n;
//    n = n + i;
//    i++;
//    return f(n);
//}
//
//int main()
//{
//    int n = 1;
//    //f(n);
//    printf("%d\n", f(n));
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//
//void nikoches_theorem(int m) {
//    int start = m * m - m + 1;  // 计算连续奇数序列的起始数
//
//    printf("%d", start);
//
//    for (int i = 1; i < m; i++) {
//        start += 2;
//        printf(" + %d", start);
//    }
//
//    printf("\n");
//}
//
//int main() {
//    int m;
//
//    while (scanf_s("%d", &m) != EOF) {
//        nikoches_theorem(m);
//    }
//    return 0;
//}

#include <stdio.h>

int main() {
    int n;

    while (scanf_s("%d", &n) != EOF) {
        int firstTerm = 2;  
        int commonDiff = 3;  
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += firstTerm + i * commonDiff;
        }

        printf("%d\n", sum);
    }

    return 0;
}
