//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	float  aboat = 32000.0; double  abet = 2.14e9; long  double  dip = 5.32e-5;
//	printf("%f  can be written % e\n",  aboat,  aboat);// 下一行要求编译器支持 C99 或其中的相关特性
//	printf("And  it's  %a  in  hexadecimal,  powers  of  2  notation\n", aboat);       
//	printf("%f  can  be  written % e\n",  abet, abet); 
//	printf("%Lf  can  be  written  %Le\n", dip,dip);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	float  a, b;
//	b = 2.0e20 + 1.0; a = b - 2.0e20; 
//	printf("%f  \n", a);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	/* C99 为类型大小提供%zd 转换说明 */
//	printf("Type  int  has  a  size  of  %zd  bytes.\n", sizeof(int)); 
//	printf("Type  char  has  a  size  of % zd  bytes.\n", sizeof(char)); 
//	printf("Type  long  has  a  size  of % zd  bytes.\n", sizeof(long));
//	printf("Type  long  long  has  a  size  of  %zd bytes.\n", sizeof(long  long));
//	printf("Type  double  has  a  size of  %zd  bytes.\n",sizeof(double));
//	printf("Type  long  double  has  a  size  of  %zd bytes.\n", sizeof(long  double)); 
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;

struct person
{
    char id[20];
    char name[20];
    int s1, s2, s3;
    int sum;
    double ave;
} p[100];

int main()
{
	int i;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].sum = 0;
		scanf_s("%s", p[i].id, n);
		scanf_s("%s", p[i].name, n);
		scanf_s("%d", &p[i].s1);
		scanf_s("%d", &p[i].s2);
		scanf_s("%d", &p[i].s3);
		p[i].sum += p[i].s1 + p[i].s2 + p[i].s3;
		p[i].ave = p[i].sum / 3.00;
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %s %d %d %d %.2f\n", p[i].id, p[i].name, p[i].s1, p[i].s2, p[i].s3, p[i].ave);
	}
	system("pause");
	return 0;
}
