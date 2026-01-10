//#include <string.h> 
//#include <stdio.h> 
//#include <stdlib.h> 
//
//int main()
//{
//	char a[5][11], t[11];
//	int i, j;
//	for (i = 0; i <= 4; i++)
//	{
//		gets_s(a[i]);
//	}
//	for (i = 0; i <= 3; i++)
//	{
//		for (j = i + 1; j <= 4; j++)
//		{
//			if (strcmp(a[i], a[j]) > 0)
//			{
//				strcpy_s(t, a[i]);
//				strcpy_s(a[i], a[j]);
//				strcpy_s(a[j], t);
//			}
//		}
//	}
//	for (i = 0; i <= 4; i++)
//	{
//		puts(a[i]);
//	}
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double a, b, c;
	scanf_s("%lf %lf %lf", &a, &b, &c);
	char d[] = "Hello,World! This is my begining!";
	char e[] = " I am coming! My love!";
	/*double d = sqrt(a);
	printf("%lf", d);
	return 0;*/
	if ((sqrt(a) + sqrt(b)) == sqrt(c))
	{
		printf("%lf\t", (sqrt(a) + sqrt(b)));
		printf("%lf\t", sqrt(c));
		/*printf(" Hello,World! This is my begining!\n");*/
		/*printf("%s\n", d);*/
		puts(d);
		/*printf("\n");*/
	}
	else
	{
		printf("%lf\t", (sqrt(a) + sqrt(b)));
		printf("%lf\t", sqrt(c));
		/*printf(" I am coming! My love!\n");*/
		/*printf("%s\n", e);*/
		puts(e);
		/*printf("\n");*/
	}
	double f;
	scanf_s("%lf", &f);
	if (f == 521.1314)
	{
		printf("TRUE\n");
	}
	else
	{
		printf("FALSE\n");
	}
	system("pause");
	return 0;
}