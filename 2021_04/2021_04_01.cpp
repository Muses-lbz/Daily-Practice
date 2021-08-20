#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	char a[5][11], t[11];
	int i, j;
	for (i = 0; i <= 4; i++)
	{
		gets_s(a[i]);
	}
	for (i = 0; i <= 3; i++)
	{
		for (j = i + 1; j <= 4; j++)
		{
			if (strcmp(a[i], a[j]) > 0)
			{
				strcpy_s(t, a[i]);
				strcpy_s(a[i], a[j]);
				strcpy_s(a[j], t);
			}
		}
	}
	for (i = 0; i <= 4; i++)
	{
		puts(a[i]);
	}
	system("pause");
	return 0;
}

