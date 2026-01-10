#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char a[101] = { 0 }, b[101] = { 0 };
	gets_s(a);
	gets_s(b);
	if (strcmp(a, b) <= 0)
	{
		puts(a);
		puts(b);
	}
	else
	{
		puts(b);
		puts(a);
	}
	system("pause");
	return 0;
}
