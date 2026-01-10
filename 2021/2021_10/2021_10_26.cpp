//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int a[100];
//    int i, nmb = 0;
//    for (i = 0; i < 100; i++)
//        a[i] = rand() % 1001;
//    for (i = 0; i < 100; i++)
//    {
//        if ((a[i] % 7 == 0) && (a[i] % 3 == 2))
//        {
//            printf("%3d\t", a[i]);
//            nmb++;
//        }
//    }
//    printf("\n");
//    if (nmb == 0)
//        printf("没有符合条件的数\n");
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int a[10];
//    int i, j, temp = 0;
//    int k, x = 0;
//    printf("输入10个数：\n");
//    for (i = 0; i < 10; i++)
//        scanf_s("%d", &a[i]);
//    for (i = 0; i < 9; i++)
//    {
//        k = i;
//        for (j = i + 1; j < 10; j++)
//            if (a[j] < a[i])
//                k = j;
//        temp = a[i];
//        a[i] = a[k];
//        a[k] = temp;
//    }
//    printf("排序后：\n");
//    for (i = 0; i < 10; i++)
//        printf("%d ", a[i]);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int h, w;
//    printf("请输入身高（厘米）和体重（公斤）");
//    scanf("%d %d", &h, &w);
//    int s = h - 110;
//    if ((w - s) > 5)
//        printf("过胖\n");
//    else if (s - w > 5)
//        printf("过瘦");
//    else
//        printf("标准\n");
//    return 0;
//}

//#include <stdio.h> 
//
//int main()
//{
//	int  zippo[4][2] = { {  2,  4  },  {  6,  8  },  {  1,  3  },{  5,  7  } };
//	printf("    zippo  =  %p,    zippo  +  1  =  %p\n", zippo, zippo + 1);
//	printf("zippo[0]  =  %p,  zippo[0]  +  1  =  %p\n", zippo[0], zippo[0] + 1);
//	printf("  *zippo =  %p, *zippo + 1 = %p\n", *zippo, *zippo + 1);
//	printf("zippo[0][0] = %d\n", zippo[0][0]);
//	printf(" * zippo[0] = %d\n", *zippo[0]);
//	printf(" * *zippo = %d\n", **zippo);
//	printf(" zippo[2][1] = %d\n", zippo[2][1]);
//	printf(" * (*(zippo + 2) + 1) = %d\n", *(*(zippo + 2) + 1));
//	return  0;
//}

//#include <stdio.h> 
//
//int main()
//{
//	int zippo[4][2] = { {  2,  4  },  {  6,  8  },  {  1,  3  },{  5,  7  } };
//	int(*pz)[2];//pz指向一个内含两个int类型的数组
//	pz = zippo;
//	printf("    pz  =  %p,    pz  +  1  =  %p\n", pz, pz + 1);
//	printf("pz[0]  =  %p,  pz[0] + 1 = % p\n", pz[0], pz[0] + 1);
//	printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);
//	printf("pz[0][0]  =  %d\n", pz[0][0]);
//	printf("* pz[0] = %d\n", *pz[0]);
//	printf(" * *pz = % d\n", **pz);
//	printf(" pz[2][1]  =  %d\n", pz[2][1]);
//	printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
//	return  0;
//}

//#include <stdio.h>
//#define  ROWS  3 
//#define  COLS  4 
//
//void sum_rows(int ar[][COLS], int  rows);
//void sum_cols(int[][COLS], int);// 省略形参名，没问题
//int sum2d(int(*ar)[COLS], int rows); // 另一种语法
//
//int  main()
//{
//	int junk[ROWS][COLS] = {
//		{  2,  4,  6,  8  },
//		{  3,  5,  7,  9  },
//		{  12,  10,  8,  6  }
//	};
//	sum_rows(junk, ROWS);
//	sum_cols(junk, ROWS);
//	printf("Sum  of all  elements  =  %d\n", sum2d(junk, ROWS));
//	return  0;
//}
//
//void sum_rows(int  ar[][COLS], int  rows)
//{
//	int r; int c; int tot;
//	for (r = 0; r < rows; r++)
//	{
//		tot = 0;
//		for (c = 0; c < COLS; c++)
//			tot += ar[r][c];
//		printf("row  %d:  sum  = %d\n", r, tot);
//	}
//}
//
//void  sum_cols(int  ar[][COLS], int rows)
//{
//	int r; int c; int tot;
//	for (c = 0; c < COLS; c++)
//	{
//		tot = 0;
//		for (r = 0; r < rows; r++)
//			tot += ar[r][c];
//		printf("col  %d:  sum = %d\n", c, tot);
//	}
//}
//
//int sum2d(int(*ar)[COLS], int rows)
//{
//	int  r; int  c; int  tot = 0;
//	for (r = 0; r < rows; r++)
//		for (c = 0; c < COLS; c++)
//			tot += ar[r][c];
//	return  tot;
//}

//#include <stdio.h>
//constexpr auto LEN1 = 7;
//constexpr auto LEN2 = 3;
//
//void copy_arr(int ar1[], const int ar2[], int n); 
//void show_arr(const int[], int);
//
//int main()
//{
//	int orig[LEN1] = { 1,2,3,4,5,6,7 };
//	int copy[LEN2];
//	show_arr(orig, LEN1);
//	copy_arr(copy, orig + 2, LEN2); 
//	show_arr(copy, LEN2);
//	return 0;
//}
//
//void copy_arr(int ar1[], const int ar2[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++) 
//		ar1[i] = ar2[i];
//}
//
//void show_arr(const int ar[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++) 
//		printf("%d ", ar[i]);
//	putchar('\n');
//}
//

#include <stdio.h>
constexpr auto ROWS = 3;
constexpr auto COLS = 5;

void times2(int ar[][COLS], int r);
void showarr2(int ar[][COLS], int r);

int main(void)
{
	int stuff[ROWS][COLS] = { {1,2,3,4,5}, {6,7,8,-2,10 }, { 11,12,13,14,15 } };
	showarr2(stuff, ROWS); putchar('\n');
	times2(stuff, ROWS);
	showarr2(stuff, ROWS);
	return 0;
}

void times2(int ar[][COLS], int r)
{
	int row, col;
	for (row = 0; row < r; row++)
		for (col = 0; col < COLS; col++)
			ar[row][col] *= 2;
}

void showarr2(int ar[][COLS], int r)
{
	int row, col;
	for (row = 0; row < r; row++)
	{
		for (col = 0; col < COLS; col++)
			printf("%d ", ar[row][col]);
		putchar('\n');
	}
}