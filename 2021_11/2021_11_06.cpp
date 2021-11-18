//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	long long n;
//	int count = 0;
//	printf("输入一个整数: ");
//	scanf_s("%lld", &n);
//	while (n <= 0)
//	{
//		printf("错误！\n请重新输入一个数字：");
//		scanf_s("%lld", &n);
//	}
//	while (n > 0)
//	{
//		n /= 10;
//		++count;
//	}
//	printf("数字是 %d 位数。\n", count);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//static int numDecodings(char* s)
//{
//    int len = strlen(s);
//    if (len == 0)
//    {
//        return 0;
//    }
//    int a = 1;
//    int b = s[0] == '0' ? 0 : a;
//    int c = b;
//    for (int i = 2; i <= len; i++)
//    {
//        c = s[i - 1] == '0' ? 0 : b;
//        int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
//        if (num >= 10 && num <= 26)
//        {
//            c += a;
//        }
//        a = b;
//        b = c;
//    }
//    return c;
//}
//int main(int argc, char** argv)
//{
//    if (argc != 2)
//    {
//        fprintf(stderr, "Usage: ./test number\n");
//        exit(-1);
//    }
//    printf("%d\n", numDecodings(argv[1]));
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//static int removeDuplicates(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//    {
//        return 0;
//    }
//    int i;
//    int len = 0;
//    int count = 1;
//    for (i = 1; i < numsSize; i++)
//    {
//        if (nums[len] == nums[i])
//        {
//            if (count < 2)
//            {
//                count++;
//                nums[++len] = nums[i];
//            }
//        }
//        else
//        {
//            count = 1;
//            nums[++len] = nums[i];
//        }
//    }
//    return len + 1;
//}
//int main(int argc, char** argv)
//{
//    int i, count = argc - 1;
//    int* nums = (int*)malloc(count * sizeof(int));
//    for (i = 0; i < count; i++)
//    {
//        nums[i] = atoi(argv[i + 1]);
//    }
//    count = removeDuplicates(nums, count);
//    for (i = 0; i < count; i++)
//    {
//        printf("%d ", nums[i]);
//    }
//    printf("\n");
//}

#include <stdio.h>
#include <stdlib.h>

int imin(int, int);

int main()
{
	int  evil1, evil2;
	printf("Enter a pair of integers (q to quit):\n");
	while (scanf_s("%d %d", &evil1, &evil2) == 2)
	{
		printf("The lesser of %d and %d is %d.\n", evil1, evil2, imin(evil1, evil2));
		printf("Enter a pair of integers (q to quit):\n");
	}
	printf("Bye.\n");
	system("pause");
	return 0;
}

int  imin(int n, int m)
{
	int min;
	if (n < m)
		min = n;
	else
		min = m;
	return  min;
}