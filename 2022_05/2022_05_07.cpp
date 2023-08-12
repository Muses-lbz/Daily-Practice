//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int num = 0;
//    for (int i = 1; i < 101; i++)
//    {
//        if (i % 10 == 9 || i / 10 == 9)
//            num++;
//    }
//    printf("%d", num);
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    for (int i = 1; i < 10; i++)
//    {
//        for (int j = 1; j < 10; j++)
//        {
//            int m;
//            m = i * j;
//            printf("%d * %d = %d ", i, j, m);
//            if (j == 9)
//            {
//                printf("\n");
//            }
//        }
//    }
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() 
//{
//    int secretNumber, guess, attempts = 0;
//    srand(time(NULL));
//
//    secretNumber = rand() % 100 + 1;
//
//    printf("欢迎来到猜数字游戏！\n");
//    printf("我已经想好了一个1到100之间的数字，你猜猜是多少。\n");
//
//    do {
//        printf("请输入你的猜测：");
//        scanf_s("%d", &guess);
//        attempts++;
//
//        if (guess < secretNumber)
//        {
//            printf("猜的数字太小了！\n");
//        }
//        else if (guess > secretNumber) 
//        {
//            printf("猜的数字太大了！\n");
//        }
//        else 
//        {
//            printf("恭喜你猜对了！你用了 %d 次猜测。\n", attempts);
//            break;
//        }
//    } while (1);
//    system("pause");
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int target) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            return mid; 
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; 
        }
        else 
        {
            right = mid - 1; 
        }
    }
    return -1; 
}

int main() 
{
    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("请输入要查找的数字：");
    scanf_s("%d", &target);
    int index = binarySearch(arr, size, target);
    if (index != -1)
    {
        printf("数字 %d 在数组中的下标是 %d\n", target, index);
    }
    else 
    {
        printf("找不到数字 %d\n", target);
    }
    return 0;
}
