//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int  i = 1, j = 1, k = 2; 
//	if ((j++ || k++) && i++) 
//		printf("%d,%d,%d\n", i, j, k);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define M(x,y,z) x*y+z

int main()
{
	int a = 1, b = 2, c = 3;
	printf("%d\n", M(a + b, b + c, c + a));
	system("pause");
	return 0;
}
