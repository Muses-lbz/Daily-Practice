#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x)
{
	if (x < 0)
		printf("False\n");
	else
	{
		char r[11];
		int n = snprintf(r, 11, "%d", x);
		int i;
		for (i = 0; i < n / 2; i++)
		{
			if (r[i] != r[n - i - 1])
				printf("False\n");
			else
				printf("True\n");
		}
	}
	return 0;
}

int main()
{
	int x;
	scanf_s("%d", &x);
	isPalindrome(x);
	system("pause");
	return 0;
}
