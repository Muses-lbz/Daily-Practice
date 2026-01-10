//#include <stdio.h>
////int i;
//void prt()
//{
//	int i;
//	for (i = 5; i < 8; i++)
//		printf("%c", '*');
//	printf("\t");
//}
//int main()
//{
//	int i;
//	for (i = 5; i <= 8; i++)
//	{
//		prt();
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int a = 3;
//    printf("%d\n", (a += a -= a * a));
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int n, num, negativeCount = 0;
//    int positiveSum = 0, positiveCount = 0;
//
//    scanf_s("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &num);
//
//        if (num < 0) {
//            negativeCount++;
//        }
//        else if (num > 0) {
//            positiveSum += num;
//            positiveCount++;
//        }
//    }
//
//    if (positiveCount > 0) {
//        double average = (double)positiveSum / positiveCount;
//        printf("%d %.1lf\n", negativeCount, average);
//    }
//    else {
//        printf("%d 0.0\n", negativeCount);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
//    int left = 0;
//    int right = rotateArrayLen - 1;
//
//    while (left < right) {
//        int mid = left + (right - left) / 2;
//
//        if (rotateArray[mid] > rotateArray[right]) {
//            left = mid + 1;
//        }
//        else if (rotateArray[mid] < rotateArray[right]) {
//            right = mid;
//        }
//        else {
//            right--;
//        }
//    }
//
//    return rotateArray[left];
//}
//
//int main() {
//    int n;
//    scanf_s("%d", &n);
//
//    int* rotateArray = (int*)malloc(n * sizeof(int));
//
//    if (rotateArray == NULL) {
//        return NULL;
//    }
//    for (int i = 0; i < n; i++) {
//        scanf_s("%d", &rotateArray[i]);
//    }
//
//    int result = minNumberInRotateArray(rotateArray, n);
//    printf("%d\n", result);
//
//    free(rotateArray);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int m, n;
//	printf("Enter m,n;");
//	scanf_s("%d%d", &m, &n);
//	while (m != n) //1
//	{
//		while (m > n) m = m - n; //2
//		while (n > m) n = n - m; //3
//	}
//	printf("m=%d\n", m);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//	do
//	{
//		switch (c = getchar())
//		{
//		case'a':case'A':
//			break;
//		case'e':case'E':
//			break;
//		case'i':case'I':
//		case'o':case'O':
//		case'u':case'U':
//			v1 += 1;
//		default:
//			v0 += 1;
//			v2 += 1;
//		}
//	} while (c != '\n');
//	printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//    int* result = (int*)malloc(2 * sizeof(int));
//    *returnSize = 2;
//
//    int* count = (int*)calloc(numsSize + 1, sizeof(int));
//
//    for (int i = 0; i < numsSize; i++) {
//        count[nums[i]]++;
//    }
//
//    for (int i = 1; i <= numsSize; i++) {
//        if (count[i] == 2) {
//            result[0] = i;  // 找到重复出现的整数
//        }
//        if (count[i] == 0) {
//            result[1] = i;  // 找到丢失的整数
//        }
//    }
//
//    free(count);
//    return result;
//}
//
//int main() {
//    int nums[] = { 1, 2, 2, 4 };
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    int returnSize;
//
//    int* result = findErrorNums(nums, numsSize, &returnSize);
//
//    printf("重复出现的整数：%d，丢失的整数：%d\n", result[0], result[1]);
//
//    free(result);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//// 函数用于查找重复出现的整数和丢失的整数
//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//    // 创建一个数组来存储结果，包含重复整数和丢失整数
//    int* result = (int*)malloc(2 * sizeof(int));
//    *returnSize = 2; // 设置返回的数组大小为2
//
//    // 创建一个计数数组，用于统计每个数字出现的次数
//    int* count = (int*)calloc(numsSize + 1, sizeof(int));
//
//    // 统计每个数字出现的次数
//    for (int i = 0; i < numsSize; i++) {
//        count[nums[i]]++;
//    }
//
//    // 遍历计数数组，找到重复出现的整数和丢失的整数
//    for (int i = 1; i <= numsSize; i++) {
//        if (count[i] == 2) {
//            result[0] = i;  // 找到重复出现的整数
//        }
//        if (count[i] == 0) {
//            result[1] = i;  // 找到丢失的整数
//        }
//    }
//
//    // 释放动态分配的内存
//    free(count);
//
//    // 返回包含结果的数组
//    return result;
//}
//
//int main() {
//    int nums[] = { 1, 2, 2, 4 };
//    int numsSize = sizeof(nums) / sizeof(nums[0]);
//    int returnSize;
//
//    // 调用函数获取结果数组
//    int* result = findErrorNums(nums, numsSize, &returnSize);
//
//    // 输出结果数组中的值
//    printf("重复出现的整数：%d，丢失的整数：%d\n", result[0], result[1]);
//
//    // 释放动态分配的内存
//    free(result);
//
//    return 0;
//}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// 函数用于判断密码是否合法
bool isValidPassword(const char* password) {
    int length = (int)strlen(password);
    if (length < 8) {
        return false; // 密码长度不足8位，不合法
    }

    if (isdigit(password[0])) {
        return false; // 密码以数字开头，不合法
    }

    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpperCase = true;
        }
        else if (islower(password[i])) {
            hasLowerCase = true;
        }
        else if (isdigit(password[i])) {
            hasDigit = true;
        }
    }

    return hasUpperCase && hasLowerCase && hasDigit; // 同时包含两种字符类型，合法
}

int main() {
    int n;
    scanf_s("%d", &n);

    char password[101];
    for (int i = 0; i < n; i++) {
        scanf_s("%s", password, 101);
        if (isValidPassword(password)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
