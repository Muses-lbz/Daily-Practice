#include <stdio.h>
#include <stdlib.h>

int main()
{
	int flag;
	//定义整型变量flag用来记录是否为素数，1代表是，0代表不是
	int n;
	int i;
	for (n = 10; n < 1000; n++)
	{
		for (i = 2; i < n; i++)
		{
			flag = 1;                        //flag默认为1
			if (n % i == 0)
			{
				flag = 0;                    //如果不符合素数要求，则把flag置为0
				break;                       //并跳出循环
			}
		}
		if (flag == 1)                        //判断是否是素数
		{
			if (n / 100 == 0)                //判断是否是两位数
			{
				if (n / 10 == n % 10)        //判断十位和各位是否相同
				{
					printf("%4d", n);
				}
			}
			else
			{
				if (n / 100 == n % 10)       //判断百位和个位是否相同
				{
					printf("%4d", n);
				}
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}


