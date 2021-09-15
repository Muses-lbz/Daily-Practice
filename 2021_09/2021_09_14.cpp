//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//
//int main()
//{
//	system("cls");
//	printf("3");
//	Sleep(1000);
//	system("cls");
//	printf("2");
//	Sleep(1000);
//	system("cls");
//	printf("1");
//	Sleep(1000);
//	system("cls");
//	printf("0");
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//
//int main()
//{
//	int a = 60;
//	system("color 0a");
//	while (a >= 0)
//	{
//		system("cls");
//		printf("%d", a);
//		Sleep(1000);
//		a = a - 1;
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//
//	int a = 1;
//	while (a <= 15)
//	{
//		printf("＊");
//		if (a % 5 == 0)
//			printf("\n"); 
//		a = a + 1;
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a = 1;
//	while (a <= 3)
//	{
//		int b = 1;
//		while (b <= 5)
//		{
//			printf("＊");
//			b = b + 1;
//		}
//		printf("\n");
//		a = a + 1;
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a = 1;
//	while (a <= 5)
//	{
//		int b = 1;
//		while (b <= a)
//		{
//			printf("*");
//			b = b + 1;
//		}
//		printf("\n");
//		a = a + 1;
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//
//int main()
//{
//
//	system("cls");
//	printf("H"); 
//	Sleep(1000); 
//	system("cls");
//	printf(" H");
//	Sleep(1000);
//	system("cls");
//	printf("  H\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//
//int main()
//{
//	int a;
//	a = 0;
//	while (a <= 2)
//	{
//		system("cls");
//		int b = 1;
//		while (b <= a)
//		{
//			printf(" ");
//			b = b + 1;
//		}
//		printf("H");
//		Sleep(1000);
//		a = a + 1;
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a = 1;
//	while (a <= 2)
//	{
//		int b = 1;
//		while (b <= 3)
//		{
//			printf("ok ");
//			b = b + 1;
//		}
//		a = a + 1;
//	}
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 1;
	while (i <= 10)
	{
		int j = 1;
		while (j <= i)
		{
			printf("OK ");
			j = j + 1;
		}
		i = i + 1;
	}
	system("pause");
	return 0;
}
