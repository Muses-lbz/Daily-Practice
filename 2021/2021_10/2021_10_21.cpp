//#include <stdio.h>   
//
//void display(char cr, int lines, int width);
//
//int main()
//{
//	int ch;	/* 待打印字符*/
//	int rows, cols;	/* 行数和列数*/
//	printf("Enter a  character  and  two  integers:\n");
//	while ((ch = getchar()) != '\n')
//	{
//		if (scanf_s("%d  %d", &rows, &cols) != 2)
//			break;
//		display(ch, rows, cols);
//		while (getchar() != '\n')
//			continue;
//		printf("Enter  another  character and two integers; \n");
//		printf("Enter  a  newline  to  quit.\n");
//	}
//	printf("Bye.\n");
//	return  0;
//}
//
//void display(char cr, int lines, int width)
//{
//	int row, col;
//	for (row = 1; row <= lines; row++)
//	{
//		for (col = 1; col <= width; col++)
//			putchar(cr);
//		putchar('\n');    /* 结束一行并开始新的一行 */
//	}
//}

//#include <stdio.h>
//
//int main()
//{
//    int ret, day, i = 1, sum = 1;
//    while (1)
//    {
//        printf("Input days:");
//        ret = scanf_s("%d", &day);
//        if ((ret != 1) || (day <= 0))
//        {
//            fflush(stdin);
//            continue;
//        }
//        break;
//    }
//    do
//    {
//        sum = (sum + 1) * 2;
//        i++;
//    } while (i < day);
//    printf("sum=%d\n", sum);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
//CSDN的垃圾代码 无法运行
/*设有n种不同面值的硬币，第i种硬币的币值是Vi(其中V1=1),重量是Wi,i=1,2，...n且现在购买某种总币值为y的商品，
需要用这些硬币付款，如果每种钱币使用的个数不限，那么如何选择付款的方法使得付出钱币的总重量最轻？
使用动态规划设计策略设计一个求解该问题的算法。假设问题的输入实例是：
V1=1， V2=4， V3=6， V4=8
W1=1， W2=2， W3=4， W4=6
Y=12
要求输出优化函数表和标记函数表、以及硬币支付方式。*/
void strcpy(int* a, int* b, int Y) 
{
    for (int i = 0; i <= Y; i++) 
        *(a + i) = *(b + i);
}

void solve()
{
    int n; 
    scanf_s("%d", &n);
    int *type, *weight, Y, i, j, k;
    type = (int*)malloc(n * sizeof(int));
    weight = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) 
        scanf_s("%d", &type[i]);
    for (i = 0; i < n; i++) 
        scanf_s("%d", &weight[i]);
    scanf_s("%d", &Y);
    int *Min, *Min_Path, *path;
    Min = (int*)malloc(Y * sizeof(int));
	Min_Path = (int*)malloc(Y * sizeof(int));
    path = (int*)malloc((n*(Y+1)) * sizeof(int));
    for (i = 0; i <= Y; i++)
        Min[i] = 9999;
    Min[0] = 0;
    printf("\n");
    for (j = 0; j < n; j++) 
    {
        for (i = type[j]; i <= Y; i++)
            if (Min[i] > Min[i - type[j]] + weight[j]) 
            {
                Min_Path[i] = type[j];
                Min[i] = Min[i - type[j]] + weight[j];
            }
        for (k = 1; k <= Y; k++) 
            printf("%-3d", Min[k]);
        printf("\n");
        strcpy(path[j], Min_Path, Y);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < Y; j++)
            printf("%-3d", path[i][j]);
        printf("\n");
    }
    int y = Y;
    printf("\n支付方式:");
    while (y) 
    {
        printf("%d ", Min_Path[y]);
        y -= Min_Path[y];
    }
    printf("\n总重量:%d\n", Min[Y]);
}

int main() 
{
    solve();
    return 1;
    system("pause");
}