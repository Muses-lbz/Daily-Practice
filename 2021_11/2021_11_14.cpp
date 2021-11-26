// 时间片轮转调度算法（操作系统）

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

/************************************************************************/
/* 时间片轮转法（RR(Round Robin Method)）                               */
/************************************************************************/
// 定义时间片的结构体
struct RR
{
	// 进程名称
	char name[10];
	// 到达时间
	int daodatime;
	// 服务时间
	int fuwutime;
	// 剩余时间
	int shengyutime;
	// 所处状态
	char* state;

	struct RR* next;
};

// 根据到达时间从小到大排序
struct RR* input()
{
	int N, i;
	// 定义队首、队尾
	struct RR* head, * rear;
	// p是队尾指针，q是队首指针，t是执行时间
	struct RR* p, * q, * t;
	// 初始化队首和队尾为空
	head = rear = NULL;

	printf("请输入进程数目：");
	scanf_s("%d", &N);

	for (i = 0; i < N; i++)
	{
		// 初始化一个空间给进程
		p = (struct RR*)malloc(sizeof(struct RR));
		if (p == NULL)
		{
			printf("error!");
		}
		else
		{
			printf("请输入第%d个进程的名字、到达时间、服务时间(例如：1 2 1)：\n", i + 1);
			scanf_s("%s", p->name, 10);
			scanf_s("%d", &p->daodatime);
			scanf_s("%d", &p->fuwutime);
			p->shengyutime = p->fuwutime;
			p->state = (char*)"就绪";
			p->next = NULL;

			// 当输入结束时，把p的数据放到队首，以便下一步执行
			if (rear == NULL)
			{
				head = p;
				p->next = NULL;
				rear = p;
			}
			// 否则执行时间为空，队首变成q
			else
			{
				t = NULL;
				q = head;
				// 当q和q的到达时间小于p的到达时间时，把执行时间给q
				while (q && q->daodatime < p->daodatime)
				{
					t = q;
					q = q->next;
				}
				// 当q是队首时，则下一个队首变成p,以便每个进程都能够得到时间片
				if (q == head)
				{
					p->next = head;
					head = p;
				}
				// 当执行时间片到达队尾时（执行完成），返回给队首p
				else if (t == rear)
				{
					rear->next = p;
					p->next = NULL;
					rear = p;
				}
				// 否则给队首p占用执行时间，p执行完后到q
				else
				{
					t->next = p;
					p->next = q;
				}
			}
		}
	}
	// 返回队首
	return head;
}
// 输出
void run(struct RR* head)
{
	struct RR* p, * t, * r;
	int num;
	// 运行过程
	vector<string> vec_out;

	printf("请输入时间片：");
	scanf_s("%d", &num);

	// 当队首不为空时，把p给队首
	while (head != NULL)
	{
		r = p = head;
		// 把执行时间给队首
		while (p != NULL)
		{
			t = head;
			// p的剩余时间 = 剩余时间 - 时间片
			p->shengyutime = p->shengyutime - num;
			p->state = (char*)"运行";
			string s = p->name;
			vec_out.push_back(s);
			// 当p运行完，即剩余时间小于0时，仍然把它当做0处理
			if (p->shengyutime < 0)
				p->shengyutime = 0;

			printf("\n************程序开始运行*****************\n");
			printf("进程  到达时间 服务时间  剩余时间  当前状态\n");
			//时间不为空时，输出当前进程的信息，并把时间片交给下一个进程
			while (t != NULL)
			{
				printf("%2s%8d%8d%14d%10s\n", t->name, t->daodatime, t->fuwutime, t->shengyutime, t->state);
				t = t->next;
			}
			//按住回车键观看
			//getchar();
			//当队首的剩余时间为0时，先把队首改成p的下一个，然后释放内存，删除队首节点
			if (p->shengyutime == 0)
			{
				if (p == head)
				{
					head = p->next;
					free(p);
					p = head;
				}
				//否则返回执行，把队尾的下一个指针变成p的下一个指针，队尾的位置移动到队首
				else
				{
					r->next = p->next;
					p = r->next;
					r = p;
				}
			}
			//否则把队首的位置给队尾，把队首的状态显示为“就绪”状态
			else
			{
				r = p;
				p->state = (char*)"就绪";
				p = p->next;
			}
		}
	}
	printf("执行顺序：\n");
	printf("%s", vec_out[0].c_str());
	for (unsigned int i = 1; i < vec_out.size(); i++)
	{
		printf("-->%s", vec_out[i].c_str());
	}
}

void RR_MAIN()
{
	//定义时间片的队首结构体
	struct RR* head;
	// 队首执行的时间
	head = input();
	run(head);
}

int main()
{
	RR_MAIN();
	printf("\n");
	system("pause");
	return 0;
}