//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main()
//{
//	int a, b, sum = 6;
//	srand((unsigned)time(NULL));
//	a = rand() % 100;
//	while (1)
//	{
//		sum--;
//		scanf_s("%d", &b);
//		if (b > a)
//			printf("大了，请继续\n");
//		if (b < a)
//			printf("小了，请继续\n");
//		if (b == a)
//		{
//			printf("恭喜你答对了\n");
//			break;
//		}
//		if (sum == 0)
//		{
//			printf("LOSE!");
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void main() 
//{
//	srand((unsigned)time(NULL));
//	printf("%d", rand() % 20000000);
//	printf("\n");
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a[5], i;
//	for (i = 0; i <= 4; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//	for (i = 4; i >= 0; i--)
//	{
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int h, a[10], i, sum; for (i = 0; i <= 9; i++)
//		scanf_s("%d", &a[i]);
//	scanf_s("%d", &h); sum = 0;
//	for (i = 0; i <= 9; i++)
//	{
//		if (a[i] <= h + 30)
//			sum++;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//
//	int a[10], i, t; 
//	for (i = 0; i <= 9; i++)
//		a[i] = 0; //初始化每个小房间为0
//	for (i = 1; i <= 5; i++)
//	{
//		scanf_s("%d", &t); //依次读入5个数
//		a[t]=1;         //把对应的小房间改为1
//	}
//	for (i = 0; i <= 9; i++)
//		if (a[i] == 0)     //输出没有出现过的数
//			printf("%d ", i);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[10], i, j, t; 
	for (i = 0; i <= 9; i++)
		a[i] = 0; // 初始化为0
	for (i = 1; i <= 5; i++)  // 循环读入5个数
	{
		scanf_s("%d", &t); // 把每一个数读到变量t中
		a[t]++;          // t所对应小房子中的值增加1
	}
	for (i = 0; i <= 9; i++)    // 依次判断0～9这个10个小房子
		for (j = 1; j <= a[i]; j++)   //出现了几次就打印几次
			printf("%d ", i);
	system("pause");
	return 0;
}
