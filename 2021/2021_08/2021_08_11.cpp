//#include <stdio.h>
//#include <stdlib.h>
//
//int X()
//{
//	printf("蔺");
//	return 0;
//}
//
//int Y()
//{
//	printf("兵");
//	return 0;
//}
//
//int Z()
//{
//	printf("姿");
//	return 0;
//}
//
//int main()
//{
//	X();
//	Y();
//	Z();
//	printf("\n");
//	Y();
//	Z();
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int h, a[10], i, sum;
	for (i = 0; i <= 9; i++)
	{
		scanf_s("%d", &a[i]);
	}

	scanf_s("%d", &h); 
	sum = 0;
	for (i = 0; i <= 9; i++)
	{
		if (a[i] <= h + 30) 
			sum++;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
