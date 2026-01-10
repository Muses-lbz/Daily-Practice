#include <stdio.h>
#include <stdlib.h>

int main()
{

	int a, b;
	char c;
	scanf_s("%d", &a);
	scanf_s("%c", &c, 1);
	scanf_s("%d", &b);
	if (c == '+')
		printf("%d\n", a + b);
	if (c == '-')
		printf("%d\n", a - b);
	if (c == '＊')
		printf("%d\n", a * b);
	if (c == '/')
		printf("%d\n", a / b);
	system("pause");
	return 0;
}
