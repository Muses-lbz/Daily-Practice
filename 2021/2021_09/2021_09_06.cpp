//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int  a;
//	scanf_s("%d", &a);
//	if (a % 7 == 0 || a % 10 == 7)
//		printf("yes\n");
//	else
//		printf("no\n");
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a, b, c, t;
//	scanf_s("%d %d %d", &a, &b, &c);
//	if (a < b) { t = a; a = b; b = t; }
//	if (a < c) { t = a; a = c; c = t; }
//	if (b < c) { t = b; b = c; c = t; }
//	printf("%d %d %d\n", a, b, c);
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
//	if (a % 2 == 1)
//	{
//		printf("%d ", a + 1);
//		printf("%d ", a + 2);
//		printf("%d\n", a + 3);
//	}
//	else
//	{
//		printf("%d ", a - 1);
//		printf("%d ", a - 2);
//		printf("%d\n", a - 3);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	system("color  0a");
//	while (1 > 0)
//	{
//		printf("0 1");
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
//	a = 1;
//	while (a <= 100)
//	{
//		if (a % 3 == 0 && a % 5 != 0) printf("%d ", a);
//		a = a + 1;
//	}
//	printf("\n\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a = 1, i = 1;
	while (i < 10)
	{
		a = a * i;
		i++;
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}
