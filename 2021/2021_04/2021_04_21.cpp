#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,x,y,z;
	for (m = 100; m <= 999; m++)
	{
		x = m / 100;
		y = m / 10 % 10;
		z = m % 100 % 10;
		if (m == x * x * x + y * y * y + z * z * z)
		{
			printf("%d\n", m);
			continue;
		}
	}
	system("pause");
	return 0;
}
