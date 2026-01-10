//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	//开辟内存空间
//	if (p == NULL)//开辟失败
//	{
//		return -1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//		//输出为0 0 0 0 0 0 0 0 0 0
//	}
//	free(p);
//	//释放内存空间
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	//开辟内存空间
//	if (p == NULL)//开辟失败
//	{
//		return -1;
//	}
//	int* ch = (int*)realloc(p, 20 * sizeof(int));
//	if (ch != NULL)
//	{
//		p = ch;//开辟成功
//	}
//	else
//	{
//		return -1;//开辟失败
//	}
//	for (int i = 10; i < 20; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int j = 0; j < 20; j++)
//	{
//		printf("%d ", *(p + j));
//	}
//	free(p);
//	//释放内存空间
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p == NULL)
//	{
//		return -1;
//	}
//	for (int i = 0; i < 10; i++)//error
//	{
//		*(p + i) = i;//赋值
//	}
//	for (int j = 0; j < 10; j++)
//	{
//		printf("%d ", *(p + j));//打印
//	}
//	free(p);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0, t = 0, i;
	char s[50], s1[50];
	/*gets_s(s);*/
	scanf_s("%s", s, 50);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s1[t++] = s[i];
			sum++;
		}
	}
	s1[t] = '\0';
	printf("%s %d\n", s1, sum);
	system("pause");
	return 0;
}
