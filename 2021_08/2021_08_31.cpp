#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;
	a = 1;
	while (a <= 100)
	{
		if (a % 3 == 0 && a % 5 != 0) printf("%d ", a);
		a = a + 1;
	}
	printf("\n\n");
	system("pause");
	return 0;
}
