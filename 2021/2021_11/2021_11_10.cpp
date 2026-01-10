// 先来先服务调度算法（操作系统）

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/************************************************************************/
/* 先来先服务（FCFS）                                                   */
/************************************************************************/
// 定义先来先服务结构体、参数

struct fcfs 
{
	// 进程名称
	char name[10];
	// 到达时间
	float daodatime;
	// 服务时间
	float fuwutime;
	// 开始时间
	float kaishitime;
	// 完成时间
	float wanchengtime;
	// 周转时间
	float zhouzhuangtime;
	// 带权周转时间
	float daiquantime;
};


// 构造一个输入进程信息的函数，定义结构体指针并初始化
void input(fcfs* p, int N)
{
	int i;
	for (i = 0; i <= N - 1; i++)
	{
		printf("输入第%d个进程的名字、到达时间、服务时间(例如：1 2 1)：\n", i + 1);
		// 把输入信息保存到结构体指针所对应的内存中
		scanf_s("%s", p[i].name, 10);
		scanf_s("%f", &p[i].daodatime);
		scanf_s("%f", &p[i].fuwutime);
		p[i].kaishitime = 0;
		p[i].wanchengtime = 0;
		p[i].zhouzhuangtime = 0;
		p[i].daiquantime = 0;
	}
}

// 构造一个输出函数
void print(fcfs* p, int N)
{
	int k;

	printf("\n进程的相关信息如下：\n");
	printf("\n进程名字\t到达时间\t服务时间\t开始时间\t完成时间\t周转时间\t带权周转时间\n");
	for (k = 0; k < N; k++)
	{
		printf("%3s\t\t%-.2f\t\t%-.2f\t\t%-.2f\t\t%-.2f\t\t%-.2f\t\t%-.2f\n", p[k].name, p[k].daodatime, p[k].fuwutime,
			p[k].kaishitime, p[k].wanchengtime, p[k].zhouzhuangtime, p[k].daiquantime);
	}

	printf("执行顺序：\n");
	printf("%s", p[0].name);
	for (k = 1; k < N; k++)
	{
		printf("-->%s", p[k].name);
	}
}

// 根据进程到达时间进行排序，从小到大
void sort(fcfs* p, int N)
{
	int i, j;
	for (i = 1; i < N; i++)
	{
		fcfs t = p[i];
		for (j = i - 1; j >= 0 && t.daodatime < p[j].daodatime; j--)
			p[j + 1] = p[j];
		p[j + 1] = t;
	}
}

// 核心运行阶段
void run(fcfs* p, int N)
{
	int k;
	for (k = 0; k < N; k++)
	{
		// 第一个进程到达
		if (k == 0)
		{
			p[k].kaishitime = p[k].daodatime;
			p[k].wanchengtime = p[k].daodatime + p[k].fuwutime;
		}
		else
		{
			p[k].kaishitime = p[k - 1].wanchengtime;
			p[k].wanchengtime = p[k].kaishitime + p[k].fuwutime;
		}
	}
	// 计算周转时间和带权周转时间
	for (k = 0; k < N; k++)
	{
		// 周转时间 = 完成时间 - 到达时间
		p[k].zhouzhuangtime = p[k].wanchengtime - p[k].daodatime;
		// 带权周转时间 = 周转时间/服务时间
		p[k].daiquantime = p[k].zhouzhuangtime / p[k].fuwutime;
	}
}

// 定义先来先服务函数
void FCFS_MAIN()
{
	int N;
	printf("请输入进程的数量:");
	scanf_s("%d", &N);
	printf("\n");

	fcfs* p = new fcfs[N];

	// 输入
	input(p, N);
	// 根据到达时间从小到大排序
	sort(p, N);
	// 运行
	run(p, N);
	// 输出
	print(p, N);

	delete[] p;
}

int main()
{
	FCFS_MAIN();
	system("pause");
	return 0;
}