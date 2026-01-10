#include <stdio.h> 
#include <stdlib.h>

#define False 0
#define True 1
#define N 100    //作业数量，资源数量的最大值均为为100 

int M; // 总进程数
int S; // 资源种类
int ALL_RESOURCE[N];	// 各种资源的数目总和
int list = 0;		//定义序列

int  Max[N][N] = { 0 };//各进程所需各类资源的最大需求
int  Available[N] = { 0 };//系统可用资源向量
char  name[N] = { 0 };//资源的名称，可以根据设计定义成一维数组或二维数组
int  Allocation[N][N] = { 0 };//各进程已分配资源
int  Need[N][N] = { 0 }; //各进程还需要资源
int  Request[N] = { 0 }; //进程的请求资源向量
int  temp[N] = { 0 };//存放安全序列
int  Work[N] = { 0 };//存放系统可提供使用资源，工作向量

void show();			//显示当前各进程的分配和需求信息
void fenpei(int k);		//分配资源
void shifang(int k);	//上一个进程结束释放所得资源后，系统重新获得的可利用资源
int safe();				//安全性算法
void bank();			// 银行家算法

//主函数
int main()
{
	int i = 0, j = 0, p;

	printf("-------------------- 银 行 家 算 法 模 拟 实 现 ------------------\n\n");
	printf("请输入进程数:");
	scanf_s("%d", &M);
	printf("请输入资源种类:");
	scanf_s("%d", &S);
	printf("请输入%d种资源名称:", S);
	for (i = 0; i < S; i++)
	{
		scanf_s("%s", &name[i], 1);
	}
	printf("请输入%d个各类资源总数:", S);
	for (i = 0; i < S; i++)
		scanf_s("%d", &ALL_RESOURCE[i]);

	//Max矩阵的输入
	printf("-----------------------------------------------------------------\n");
	printf("请输入%d*%d个各进程所需要的各类资源的最大数量:\n", M, S);
	for (i = 0; i < M; i++) {
		for (j = 0; j < S; j++) {
			do {
				scanf_s("%d", &Max[i][j]);
				if (Max[i][j] > ALL_RESOURCE[j])
					printf("占有资源超过了声明的该资源总数,请重新输入\n");
			} while (Max[i][j] > ALL_RESOURCE[j]);
		}
	}

	//Allocation矩阵的输入
	printf("-----------------------------------------------------------------\n");
	printf("请输入%d*%d个各进程已经分配的各类资源的数量:\n", M, S);	//各进程已经分配的各类资源的数量
	for (i = 0; i < M; i++) {
		for (j = 0; j < S; j++) {
			do {
				scanf_s("%d", &Allocation[i][j]);
				if (Allocation[i][j] > Max[i][j])
					printf("已分配的资源超过了声明的最大资源,请重新输入\n");
			} while (Allocation[i][j] > Max[i][j]);
		}
	}

	// 初始化资源数量
	for (j = 0; j < S; j++) {
		p = ALL_RESOURCE[j];//资源数目的总和
		for (i = 0; i < M; i++) {
			p = p - Allocation[i][j];// 减去已经被占据的资源
			Available[j] = p;
			if (Available[j] < 0)
				Available[j] = 0;
		}
	}

	//三个矩阵之间存在的关系，求出Need矩阵
	for (i = 0; i < M; i++)
		for (j = 0; j < S; j++)
			Need[i][j] = Max[i][j] - Allocation[i][j];
	show();
	bank();
	system("pause");
	return 0;
}

//显示当前各进程的分配和需求信息
void show() {
	int i, j;
	printf("*******************************************************************\n");
	printf("各种资源的总数量:\n");
	for (j = 0; j < S; j++)
		printf(" %d", ALL_RESOURCE[j]);
	printf("\n");

	printf("-----------------------------------------------------------------\n");
	printf("[Max]各进程最大资源需求数量:\n");
	for (i = 65; i < 65 + S; i++)
		printf("          %c", i);
	printf("\n");
	for (i = 0; i < M; i++) {
		printf("  P%d    ", i);
		for (j = 0; j < S; j++)
			printf("   %d      ", Max[i][j]);
		printf("\n");
	}

	printf("-----------------------------------------------------------------\n");
	//各种资源的总数量减去已分配后剩余的资源量，求出Available矩阵  
	printf("[Available]目前各种资源可利用的数量为:\n");
	for (j = 0; j < S; j++)
		printf(" %d", Available[j]);
	printf("\n");

	printf("-----------------------------------------------------------------\n");
	printf("[Need]各进程还需要的资源数量:\n");
	for (i = 65; i < 65 + S; i++)
		printf("          %c", i);
	printf("\n");
	for (i = 0; i < M; i++) {
		printf("  P%d    ", i);
		for (j = 0; j < S; j++)
			printf("   %d      ", Need[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("-----------------------------------------------------------------\n");
	printf("[Allocation]各进程已经得到的资源量: \n");
	for (i = 65; i < 65 + S; i++)
		printf("          %c", i);
	printf("\n");
	for (i = 0; i < M; i++) {
		printf("  P%d    ", i);
		for (j = 0; j < S; j++)
			printf("   %d      ", Allocation[i][j]);
		printf("\n");
	}
	printf("\n");
}




//分配资源
void fenpei(int k) {
	int j;
	//系统试探着把资源分配给进程Pi,并修改下面的数据结构fenpei
	for (j = 0; j < S; j++) {
		Available[j] = Available[j] - Request[j];
		Allocation[k][j] = Allocation[k][j] + Request[j];
		Need[k][j] = Need[k][j] - Request[j];
	}
}

//上一个进程结束释放所得资源后，系统重新获得的可利用资源
void shifang(int k) {
	int j;
	for (j = 0; j < S; j++) {
		Available[j] = Available[j] + Request[j];
		Allocation[k][j] = Allocation[k][j] - Request[j];
		Need[k][j] = Need[k][j] + Request[j];
	}
}

/*安全性算法，设置两个向量Work和Finish.
Work：存放系统可提供使用资源，工作向量
Finish：表示系统是否有足够的资源分配给进程。
*/
int safe() {
	int Work[N], Finish[N];	  //设置两个向量Work和Finish.
	int i, j, m;
	for (j = 0; j < S; j++)
		Work[j] = Available[j]; //在执行安全算法之前，初始化
	for (i = 0; i < M; i++)
		Finish[i] = False;	  //系统初始化，将各进程的初始完成状态设置为False
	for (i = 0; i < M; i++) {
		for (j = 0; j < S; j++) {
			for (m = 0; m < M; m++) {
				if (Finish[m] == False && Need[m][j] <= Work[j]) {
					Work[j] = Work[j] + Allocation[m][j];
					Finish[m] = True; //当有足够的资源分配给进程时，设置为true
					temp[list] = m;		//记录安全进程序列
					list++;
				}
			}
		}
	}
	for (i = 0; i < M; i++) {
		if (Finish[i] == False) {
			printf("\n");
			printf("经安全性算法检查，此时系统处于不安全状态! 本次分配不成功!!!\n");
			printf("\n");
			return 1;
		}
		else {
			printf("\n");
			printf("经安全性算法检查，此时系统安全，分配成功。\n");
			printf("此时系统的安全序列是：\n");
			for (i = 1; i < list; i++) {
				printf("P%d  ", temp[i]);//打印安全序列
			}
			printf("\n");
			return 0;
		}
	}
	return 1;
}

// 银行家算法
void bank() {
	int i = 0, j = 0;
	char flag = 'Y';
	while (flag == 'Y' || flag == 'y') {
		i = -1;
		while (i < 0 || i >= M) {
			printf("-----------------------------------------------------------------\n");
			printf("请输入申请资源的进程号:\n"); //进程Pi发出请求
			scanf_s("%d", &i);
			if (i < 0 || i >= M)
				printf("对不起，输入的进程号不存在，请重新输入!\n");
		}
		printf(" 请输入进程P%d申请各类资源的数量:\n", i);
		for (j = 0; j < S; j++) {
			printf("资源%d: ", j);
			scanf_s("%d", &Request[j]);
			if (Request[j] > Need[i][j]) {
				printf("进程P%d申请的资源数大于进程P%d还需要%c类资源的数量!\n", i, i, 65 + j);
				printf("若继续执行系统将处于不安全状态【不合法】!\n");
				flag = 'S';
			}
			else if (Request[j] > Available[j]) {
				printf("进程P%d申请的资源数大于进程P%d可用%c类资源的数量!\n", i, i, 65 + j);
				printf("若继续执行系统将处于不安全状态【资源不足】!\n");
				flag = 'S';
			}
			else {

			}
		}
		if (flag == 'Y' || flag == 'y') {
			fenpei(i);	// 调用fenpei(i)函数，改变资源数
			temp[list] = i;
			list++;
			// 若系统安全
			if (safe()) {
				shifang(i); // 调用shifang(i)函数，恢复资源数
				show();		// 输出资源分配情况
			}
			else			// 若系统不安全，输出资源分配情况
				show();
		}
		else			//执行flag=S||flag=n
			printf("\n");
		printf(" 是否继续银行家算法演示？按'Y'或'y'继续,按'N'或'n'退出演示: \n");
		flag = getchar();
	}
}