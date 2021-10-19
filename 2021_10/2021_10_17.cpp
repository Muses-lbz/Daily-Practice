//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//
//int main()
//{
//	char str[50];
//	srand((unsigned int)time(NULL));
//	int seed = rand() % 2;
//	if (seed == 0)
//	{
//		char str[50] = { "不要和愚蠢的人发生争执！" };
//	}
//	if (str == "不要和愚蠢的人发生争执！")
//	{
//		printf("你是聪明的！\n\n");
//	}
//	else
//	{
//		printf("你是愚笨的！\n\n");
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#define SEC_PER_MIN 60 // 1 分钟 60 秒
//
//int main()
//{
//	int  sec, min, left;
//	printf("Convert  seconds  to  minutes and  seconds!\n");
//	printf("Enter  the  number  of  seconds(<= 0  to  quit) :\n");
//	scanf_s("%d", &sec);  // 读取秒数 
//	while (sec > 0)
//	{
//		min = sec / SEC_PER_MIN;    // 截断分钟数 
//		left = sec % SEC_PER_MIN;   // 剩下的秒数 
//		printf("%d  seconds  is % d minutes, % d  seconds.\n", sec, min, left);
//		printf("Enter  next  value  (<=0  to  quit):\n"); 
//		scanf_s("%d", &sec);
//	}
//	printf("Done!\n");
//	return  0;
//}

//#include <stdio.h> 
//
//int main()
//{
//	int ultra = 0, super = 0;
//	while (super < 5)
//	{
//		super++;
//		++ultra;
//		printf("super  =  %d,  ultra  =  %d  \n", super, ultra);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int  a = 1, b = 1;
//	int  a_post, pre_b;
//	a_post = a++;  // 后缀递增 
//	pre_b = ++b;  // 前缀递增 
//	printf("a   a_post    b    pre_b  \n"); 
//	printf("%1d  %5d  %5d  %5d\n",  a,  a_post,  b, pre_b);
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
//	int a = 1, b, c, d = 1;
//	b = 2 * ++a;
//	c = 2 * d++;
//	printf("%d %d %d %d", a, b, c, d);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h> 
//#define  MAX  100 
//
//int main()
//{
//	int  count = MAX + 1;
//	while (--count > 0)
//	{
//		printf("%d  bottles  of  spring  water  on  the  wall, " "%d  bottles  of  spring  water!\n", count, count);
//		printf("Take  one  down  and  pass  it  around,\n");
//		printf("%d  bottles  of  spring  water!\n\n", count - 1);
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x, y, m, n, nextnum, example;
	x = 2;
	y = 2;
	m = 3;
	n = 3;
	nextnum = (y + n++) * 6;
	example = (x+ ++m) * 6;
	printf("%d %d", nextnum, example);
	printf("\n");
	system("pause");
	return 0;
}
