//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int n;
//    printf("请输入大于 10 的数字：");
//    scanf_s("%d", &n);
//    int x[1000];
//    int i = 0;
//    int j = 0;
//    while (n != 0)
//    {
//        x[i] = n % 10;
//        n = n / 10;
//        i++;
//    }
//    int z = i;
//    printf("该数字为 %d 位数", z);
//    printf("\n逆序为：");
//    for (j = 0; j < z; j++)
//    {
//        printf("%d", x[j]);
//    }
//    printf("\n");
//    system("pause");
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	printf("Every time God closes a door, he opens a window.\n每次上帝关上一扇门，他就会打开一扇窗。\n");
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[] = "You need to make yourself indispensable.你需要让自己成为不可替代的人。";
	printf("%d\n", sizeof(str));
	system("pause");
	return 0;
}
