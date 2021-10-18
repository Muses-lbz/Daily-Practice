//#include <stdio.h>
//#include <stdlib.h>
//#define SQUARES 64             // 棋盘中的方格数
//
//int  main()
//{
//	const double CROP = 2E16;  // 世界小麦年产谷粒数
//	double  current, total;
//	int  count = 1;
//	printf("square grains total ");
//	printf("fraction of  \n");
//	printf("added grains ");
//	printf("world total\n");
//	total = current = 1.0;    /* 从 1 颗谷粒开始  */
//	printf("%4d  %13.2e  %12.2e  %12.2e\n", count, current, total, total / CROP);
//	while (count < SQUARES)
//	{
//		count = count + 1;
//		current = 2.0 * current;  /* 下一个方格谷粒翻倍 */
//		total = total + current;  /* 更新总数*/
//		printf("%4d  %13.2e  %12.2e  %12.2e\n", count, current, total, total / CROP);
//	}
//	printf("That's  all.\n");
//	system("pause");
//	return  0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int  top, score;
//	top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
//	printf("top  =  %d,  score  =  %d\n", top, score);
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int  n = 0; 
	size_t  intsize;
	intsize = sizeof(int);
	printf("n  =  %d,  n  has  %zd  bytes;  all  ints  have  %zd bytes.\n",n, sizeof  n, intsize);
	printf("\n");
	system("pause");
	return 0;
}
