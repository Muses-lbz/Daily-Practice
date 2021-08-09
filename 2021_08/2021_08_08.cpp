#include <stdio.h>

int main()
{
	int u = 0;
	int v = 0;

	printf("Th%cs is %c te%cting program%c!!\n", 'i', 'a', 's', '!');
	
	scanf_s("ooo%dooo%dooo", &u, &v);
	//scanf语句，要严格地按照输入格式输入
	printf("u = %d, v = %d.\n", u, v);

	return 0;
}
