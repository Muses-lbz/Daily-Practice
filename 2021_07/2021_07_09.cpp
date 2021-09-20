#include <stdio.h>
#include <stdlib.h>

int main()
{

	char a[101], b[101];
	int x, y; 
	gets_s(a);
	scanf_s("%d", &x);
	while (getchar() != '\n');
	gets_s(b);
	scanf_s("%d", &y); 
	if (x > y)
	{
		printf("%s\n", a);
	}
	else
	{
		if (x < y)
		{
			printf("%s\n", b);
		}
		else
		{
			printf("%s和%s的分数相同\n", a, b);
		}
	}
	system("pause");
	return 0;
}
