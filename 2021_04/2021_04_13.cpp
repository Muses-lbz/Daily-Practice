#include <stdio.h>
#include <stdlib.h>

int main()
{
	int  a;
	scanf_s("%d", &a);
	if (a % 7 == 0 || a % 10 == 7)
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
