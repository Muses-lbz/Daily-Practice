//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int* a, n;
//	scanf_s("%d", &n);
//	a = (int*)malloc(sizeof(int) * n);
//	if (a == NULL)
//	{
//		printf("内存分配不成功！\n");
//	}
//	else
//	{
//		for (int i = 0; i <= n - 1; i++)
//		{
//			scanf_s("%d", a);
//		}
//	}
//	if (a != NULL)
//	{
//		for (int i = 0; i <= n - 1; i++)
//		{
//			printf("num:%d", *a);
//		}
//	}
//
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int x;
//	for (x = 1; x <= 9;x++)
//	{
//		if ((10 * x + 3) * 6528 == (30 + x) * 8256)
//		{
//			printf("Answer is %d.\n\n", x);
//		}
//
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	system("color f2");
//	printf("hi");
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h> 
//
//int main()
//{
//	int a, b, c;
//	a = 321;
//	b = 123;
//	c = b - a;
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	float a, b, c;
//	a = 1.2;
//	b = 1.5;
//	c = a * b;
//	printf("%.2f\n", c);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, b, c;
//	a = 10;
//	b = 5;
//	c = a - b;
//	printf("%d\n", c);
//	c = a + b;
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, b, c;
//	scanf_s("%d %d", &a, &b);
//	c = a + b;
//	printf("%d+%d=%d\n", a, b, c);
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h>
//
//int main()
//{
//	int a, b, c;
//	scanf_s("%d%d", &a, &b);
//	c = a + b;
//	printf("%d\n", c);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	float a;
//	double b;
//	a = 3.1415926535897932;
//	b = 3.1415926535897932;
//	printf("%.15f\n", a);
//	printf("%.15lf\n", b);
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h> 
//
//int main()
//{
//	char a;
//	scanf_s("%c", &a, 1);
//	printf("后面的一个字符是%c\n", a + 1);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, b, t;
//	scanf_s("%d%d", &a, &b);
//	t = a;
//	a = b;
//	b = t;
//	printf("%d %d\n", a, b);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, b;
//	scanf_s("%d%d", &a, &b);
//	a = b - a;
//	b = b - a; a = b + a;
//	printf("%d %d\n", a, b);
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h> 
//
//int main()
//{
//	int  a;
//	scanf_s("%d", &a);
//	if (a <= 100)
//	{
//		printf("yes\n");
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h> 
//
//int main()
//{
//	int  a;
//	scanf_s("%d", &a);
//	if (a % 7 == 0)
//	{
//		printf("yes\n");
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h> 
//
//int main()
//{
//	int  a;
//	scanf_s("%d", &a);
//	if (a % 10 == 7)
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a;
//	scanf_s("%d", &a);
//	if (a / 10 == 0 && a != 0)
//	{
//		printf("True\n");
//	}
//	else
//	{
//		printf("Error!\n");
//	}
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	scanf_s("%d%d", &a, &b);
	if (a == b)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	system("pause");
	return 0;
}

