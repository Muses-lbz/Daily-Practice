//操作系统课程设计银行家算法模板-1源代码

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define TRUE 1         //定义 TRUE =1

#define FALSE 0        //定义 FLASE=0

void bank(vector<int>, vector<vector<int> >, vector<vector<int> >, int, int);                             //声明bank（应行家算法）

int  safe(vector<int> Available, vector<vector<int> > Need, vector<vector<int> > Allocation, int n, int m);//声明safe（）安全性算法

void init();

/*************************************主函数main()**************************************************************/

int main()

{
	init();

	int safe(vector<int> Available, vector<vector<int> > Need, vector<vector<int> > Allocation, int n, int m);

	return 0;

}

/**************************************初始化函数init()*********************************************************/

void init()

{
	int m;  //m资源类数

	int n;  //进程数

	cout << "输入资源类数:";

	cin >> m;

	cout << endl;

	vector<int>  Available(m); //动态申请数组Available可用资源向量

	cout << "输入各类资源总数:" << endl;

	FILE* fp;

	fopen_s(&fp, "E:\\C++ documents\\Available.txt", "r+");

	cout << "从Available.txt文件中读入数据，并输出" << endl;

	if (fp)
	{
		for (int i = 0; i < m; i++)

		{
			fscanf_s(fp, "%d", &Available[i]);

			cout << Available[i] << '\t';

		}

		fclose(fp);
	}

	cout << "\n输入进程数" << endl;

	cin >> n;

	vector<vector<int> >  Max(n, vector<int>(m));

	fopen_s(&fp, "E:\\C++ documents\\Max.txt", "r+");

	cout << "从Max.txt文件中读入数据，并输出" << endl;

	if (fp)
	{
		for (int i = 0; i < n; i++)

		{
			for (int j = 0; j < m; j++)

			{
				fscanf_s(fp, "%d", &Max[i][j]);

				cout << Max[i][j] << "  ";

			}

			cout << endl;

		}

		fclose(fp);
	}
	cout << "输入已分配的Allocation" << endl;

	vector<vector<int> >  Allocation(n, vector<int>(m));

	vector<vector<int> >  Need(n, vector<int>(m));



	fopen_s(&fp, "E:\\C++ documents\\Allocation.txt", "r+");

	cout << "Allocation.txt从文件中读入数据，并输出" << endl;

	if (fp)
	{


		for (int i = 0; i < n; i++)

		{
			for (int j = 0; j < m; j++)

			{
				fscanf_s(fp, "%d", &Allocation[i][j]);

				Need[i][j] = Max[i][j] - Allocation[i][j];               //在初始化Max时，同时初始化Need数组

				Available[j] = Available[j] - Allocation[i][j];         //在初始化Max时，同时修改Available数组

				cout << Allocation[i][j] << ' ';

			}

			cout << endl;

		}

		fclose(fp);
	}

	int safe(vector<int> Available, vector<vector<int> > Need, vector<vector<int> > Allocation, int n, int m);

	cout << "此状态安全!" << endl;

	bank(Available, Need, Allocation, n, m);//调用银行家算法bank()函数

}



/**************************************银行家算法bank()函数*********************************************************/

void bank(vector<int> Available, vector<vector<int> > Need, vector<vector<int> > Allocation, int n, int m)

{
	vector<int> Request(m);

	int all = 0;

	//定义变量all，如果all==0，表示进程已经运行完，如果all>=1，表示还有进程没有运行完

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			all += Need[i][j];

	if (0 == all)

	{
		cout << "所有进程已经运行完，结束" << endl;

		exit(0);

	}

	int jc;//任选一个进程

	char again;

	all = 0;//重新初始化all，

	while (1)

	{
		while (all == 0)

		{
			all = 0;

			//如果all==0，表示进程已经运行完，如果all>=1，表示还有进程没有运行完

			//循环直至all>0,即找到一个未运行完的进程

			cout << "任选一个进程作为当前进程0--" << n - 1 << endl;

			cin >> jc;

			for (int j = 0; j < m; j++)

			{
				all += Need[jc][j];

			}

			if (0 == all)

			{
				cout << "此进程已经运行，重新输入" << endl;

			}

		}

		cout << "输入该进程的请求向量" << endl;

		for (int i = 0; i < m; i++)

		{
			cin >> Request[i];

			while (Request[i] > Need[jc][i] || Request[i] > Available[i])

			{
				cout << "请求向量无法满足" << endl;

				break;

			}

		}

		//系统试探着把资源分配给该进程///

		for (int i = 0; i < m; i++)

		{
			Available[i] = Available[i] - Request[i];

			Allocation[jc][i] = Allocation[jc][i] + Request[i];

			Need[jc][i] = Need[jc][i] - Request[i];

		}

		int bb = 0;

		bb = safe(Available, Need, Allocation, n, m);//调用安全性算法，判断此次资源分配后，系统是否处安全状态

		if (1 == bb)

		{
			cout << "系统成功分配资源" << endl;

		}

		else

		{
			cout << "系统未能成分配资源,收回预分配资源" << endl;

			for (int i = 0; i < m; i++)

			{
				Available[i] = Available[i] + Request[i];

				Allocation[jc][i] = Allocation[jc][i] - Request[i];

				Need[jc][i] = Need[jc][i] + Request[i];

			}

		}

		cout << "您还想再次请求分配吗?是请按y/Y,否请按其它键" << endl;

		cin >> again;

		if (again == 'y' || again == 'Y')

		{
			all = 0;

			continue;

		}

		break;

	}

}

/**************************************安全性算法safe()函数*********************************************************/

int safe(vector<int> Available, vector<vector<int> > Need, vector<vector<int> > Allocation, int n, int m)

{
	vector<int> Work(m), Finish(n);//申请工作向量work，finish

	Work = Available;

	vector<int> count(n);         //记录安全序列

	int len = -1;                   //记录安全序列的进程个数，如果len==n，即表示所有的finish【i】=true，处于安全状态

	for (int i = 0; i < m; i++)
	{
		Finish[i] = FALSE;
	}

	for (int i = 0; i < n; i++)

	{
		int needed = 1;

		for (int j = 0; j < m; j++)

		{
			if (Need[i][j] <= Work[j])

			{
				needed = needed * TRUE;

			}

			else needed = needed * FALSE;

		}

		if ((Finish[i] == FALSE) && needed == 1)

		{
			for (int j = 0; j < m; j++)

			{
				Work[j] = Work[j] + Allocation[i][j];

			}

			Finish[i] = TRUE;

			len = len + 1;

			count[len] = i;

			i = -1;

		}

	}

	if (len == n - 1)

	{
		cout << "系统是安全的" << endl;

		cout << "安全序列" << endl;

		for (int i = 0; i <= len; i++)

		{
			cout << count[i];

			if (i != len)

			{
				cout << "-->";

			}

		}

		cout << endl;

		return TRUE;

	}

	else

	{
		cout << "系统是不安全的" << endl;

		return FALSE;
	}
}