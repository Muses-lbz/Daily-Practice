#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int x, y, sum;
	srand((unsigned int)time(NULL));
	x = rand() % 10;
	y = rand() % 35;
	sum = x + y;
	printf("sun=%d", sum);
	printf("\n");
	system("pause");
	return 0;
}

//PS：做你所想 爱你所爱
