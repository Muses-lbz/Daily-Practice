// 非抢占式最短作业优先调度算法（操作系统）

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

struct PCB
{
	// 进程名
	string name;
	// 到达时间
	int arrivetime = 0;
	// 运行时间
	int runtime = 0;
	// 仍需运行时间
	int resttime = 0;
	// 开始时间
	int starttime = 0;
	// 完成时间
	int endtime = 0;
	// 运行次数
	int runcount = 0;
	// 周转时间
	int zhouzhuangtime = 0;
	// 带权周转时间（周转时间/运行时间)
	double weightzhouzhuangtime = 0;
	// 优先级（静态）
	int priority = 0;

	PCB* next = NULL;
};

// 进程数
int num_process;
// 记录所有进程的总时间
int totaltime;
// 记录所有进程的总带权周转时间
double weighttotaltime;

PCB* createPCB()
{
	int i;
	// 定义队首、队尾
	PCB* head, * rear;
	// 初始化
	head = rear = NULL;
	// 临时指针变量
	PCB* p;

	cout << "请输入进程数量：";
	cin >> num_process;

	for (i = 0; i < num_process; i++)
	{
		// 初始化一个空间给进程
		p = new PCB;

		cout << "请依次输入第" << i + 1 << "个进程的信息（进程名、优先级、到达时间、运行时间）：" << endl;
		cin >> p->name >> p->priority >> p->arrivetime >> p->runtime;
		p->resttime = p->runtime;
		p->runcount = 1;
		totaltime += p->runtime;
		p->starttime = 0;
		p->endtime = 0;
		p->zhouzhuangtime = 0;
		p->weightzhouzhuangtime = 0;
		p->next = NULL;

		// 存入链表中
		if (rear == NULL)
		{
			head = p;
			rear = p;
		}
		else
		{
			rear->next = p;
			rear = p;
		}

	}
	return head;
}

// 链表插入排序
PCB* insertSort(PCB* head)
{
	/*
		1、先在原链表中以第一个节点为一个有序链表，其余节点为待定节点；
		2、从待定节点中取节点，插入到有序链表中相应位置；
		3、实际上只有一条链表，在排序中，实际只增加了一个用于指向剩下需要排序节点的头指针。
	*/
	PCB* first;// 为原链表剩下用于直接插入排序的节点头指针
	PCB* t; // 临时指针变量：要插入的节点
	PCB* p = NULL; // 临时指针变量：要插入的位置
	PCB* q; // 临时指针变量：指向原链表

	first = head->next;
	head->next = NULL; // 只含有一个节点的链表的有序链表

	while (first != NULL) // 遍历剩下的无序链表
	{
		// 无序节点在有序链表中找插入位置p
		for (t = first, q = head; (q != NULL) && (q->arrivetime < t->arrivetime); p = q, q = q->next);

		// 无序链表中的节点离开，以便插入到有序链表中
		first = first->next;

		if (q == head)// 插入在第一个节点之前
		{
			head = t;
		}
		else// p是q的前驱
		{
			p->next = t;
		}
		t->next = q;// 完成插入动作
	}

	return head;
}

// 获取当前时间段内的进程数量
int getCurrentNumOfProcess(PCB* head, int time)
{

	int count = 0;
	PCB* t;// 临时指针变量，指向链表
	t = head;

	while (t != NULL && t->arrivetime <= time)
	{
		count++;
		t = t->next;
	}

	return count;
}

// 删除当前节点
PCB* deletePCB(PCB* head, PCB* t)
{
	PCB* p, * q;
	p = head;
	q = p->next;
	// 删除节点是头节点
	if (t == head)
	{
		head = head->next;
	}
	else
	{
		while (q != t)// 跳出循环之后q为该节点，p为前一节点
		{
			p = p->next;
			q = p->next;
		}
		if (t->next == NULL)// 删除节点是尾节点
			p->next = NULL;
		else
			p->next = q->next;
	}
	// 删除
	free(t);
	return head;
}

// 在头节点后的count个节点中选择优先数最大的返回
PCB* findMaxPriority(PCB* head, int count)
{
	int max;
	PCB* q, * f;
	q = head;
	max = q->priority;
	f = q;
	while (count > 0)
	{
		if (q->priority > max)
		{
			max = q->priority;
			f = q;
		}
		count--;
		q = q->next;
	}
	return f;

}

/*
	输出a时间内的特定输出格式,当某一时间段内没有进程工作时，进程名称为0
	进程名称.进程工作时间，进程与进程间以|分隔
	输入：1 3 2 8
		  2 2 1 7
		  3 6 3 12
	输出：[0.1|2.1|1.1|3.12|1.7|2.6|0.172]
*/
void print(vector<PCB> vec_output, int a)
{
	for (unsigned int i = 0; i < vec_output.size(); i++)
	{
		cout << "******************************************" << endl;
		cout << "进程名：" << vec_output[i].name << endl;
		cout << "到达时间：" << vec_output[i].arrivetime << endl;
		cout << "开始运行时间: " << vec_output[i].starttime << endl;
		cout << "结束运行时间: " << vec_output[i].endtime << endl;
		cout << "此次运行时间：" << vec_output[i].endtime - vec_output[i].starttime << endl;
		cout << "******************************************" << endl;
		cout << endl;
		cout << endl;
	}
	// 输出周转时间信息,只有进程结束了才输出
	unsigned int i;
	for (i = 0; i < vec_output.size() - 1; i++)
	{
		bool flag = true;
		for (unsigned int j = i + 1; j < vec_output.size(); j++)
		{
			if (vec_output[j].name == vec_output[i].name)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "进程" << vec_output[i].name << "的周转时间为：" << vec_output[i].zhouzhuangtime << endl;
			cout << "进程" << vec_output[i].name << "的带权周转时间为: " << vec_output[i].weightzhouzhuangtime << endl;
			cout << endl;
			cout << endl;
		}
	}
	cout << "进程" << vec_output[i].name << "的周转时间为：" << vec_output[i].zhouzhuangtime << endl;
	cout << "进程" << vec_output[i].name << "的带权周转时间为: " << vec_output[i].weightzhouzhuangtime << endl;
	cout << endl;
	cout << endl;

	// 输出平均周转时间信息
	cout << "平均周转时间：" << totaltime / (double)num_process << endl;
	cout << "平均带权周转时间：" << weighttotaltime / (double)num_process << endl;
	cout << endl;
	cout << endl;


	cout << a << "个时间单位内的执行顺序为：" << endl;
	cout << "[";
	if (vec_output[0].starttime > 0)
	{
		cout << "0." << vec_output[0].starttime << "|";
	}
	if (vec_output[vec_output.size() - 1].endtime < a)
	{
		for (unsigned int i = 0; i < vec_output.size(); i++)
		{
			cout << vec_output[i].name << "." << vec_output[i].endtime - vec_output[i].starttime << "|";
			// 补全从开始到结束之间没有进程运行项
			if (i + 1 < vec_output.size() && vec_output[i].endtime != vec_output[i + 1].starttime)
			{
				cout << "0." << vec_output[i + 1].starttime - vec_output[i].endtime << "|";
			}
		}
		cout << "0." << a - vec_output[vec_output.size() - 1].endtime << "]" << endl;
	}
	else if (vec_output[vec_output.size() - 1].endtime == a)
	{
		for (unsigned int i = 0; i < vec_output.size() - 1; i++)
		{
			cout << vec_output[i].name << "." << vec_output[i].endtime - vec_output[i].starttime << "|";
			// 补全从开始到结束之间没有进程运行项
			if (i + 1 < vec_output.size() && vec_output[i].endtime != vec_output[i + 1].starttime)
			{
				cout << "0." << vec_output[i + 1].starttime - vec_output[i].endtime << "|";
			}
		}
		cout << vec_output[vec_output.size() - 1].name << "." << vec_output[vec_output.size() - 1].endtime - vec_output[vec_output.size() - 1].starttime << "]" << endl;
	}
	else
	{
		for (unsigned int i = 0; i < vec_output.size(); i++)
		{
			if (vec_output[i].endtime <= a)
			{
				cout << vec_output[i].name << "." << vec_output[i].endtime - vec_output[i].starttime << "|";
				// 补全从开始到结束之间没有进程运行项
				if (i + 1 < vec_output.size() && vec_output[i].endtime != vec_output[i + 1].starttime)
				{
					cout << "0." << vec_output[i + 1].starttime - vec_output[i].endtime << "|";
				}
			}
			else
			{
				cout << vec_output[i].name << "." << a - vec_output[i].starttime << "]" << endl;
				return;
			}
		}
	}
}

void PCB_MAIN(PCB* head)
{
	head = insertSort(head);
	int time = 0;// 模拟时间变量
	int count;// 当前时间内运行的进程数量
	PCB* q;

	vector<PCB> vec_out;//输出
	PCB temp;

	while (head != NULL)
	{
		count = getCurrentNumOfProcess(head, time);
		if (count == 0)
			time++;
		else
		{
			/************************************************************************/
			/* 非抢占式                                                             */
			/************************************************************************/
			q = findMaxPriority(head, count);
			q->starttime = time;
			q->endtime = q->starttime + q->runtime;
			q->zhouzhuangtime = q->endtime - q->arrivetime;
			q->weightzhouzhuangtime = q->zhouzhuangtime / (double)q->runtime;

			temp = *q;
			temp.next = NULL;

			vec_out.push_back(temp);

			time = q->endtime;
			// 删除该进程
			head = deletePCB(head, q);

		}
	}
	// 输出200时间单位内的执行顺序
	print(vec_out, 200);
}

int main()
{
	PCB* head = NULL;
	head = createPCB();
	PCB_MAIN(head);
	system("pause");
	return 0;
}