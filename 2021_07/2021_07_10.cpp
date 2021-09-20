#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[101] = { 0 }, t;
	int len, i, j;
	gets_s(a);
	len = strlen(a);
	for (i = 0; i <= len - 2; i++)
	{
		for (j = i + 1; j <= len - 1; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i]; a[i] = a[j]; a[j] = t;
			}
		}
	}
	puts(a);
	system("pause");
	return 0;
}
