#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	for (x = 1; x <= 9;x++)
	{
		if ((10 * x + 3) * 6528 == (30 + x) * 8256)
		{
			printf("Answer is %d.\n\n", x);
		}

	}
	system("pause");
	return 0;
}
