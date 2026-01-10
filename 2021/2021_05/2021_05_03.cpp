//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a[6], i, t, j; 
//	for (i = 1; i <= 5; i++)
//		scanf_s("%d", &a[i]);
//	for (i = 1; i <= 4; i++)
//	{
//		for (j = i + 1; j <= 5; j++)
//		{
//			if (a[i] > a[j])
//			{
//				t = a[i]; a[i] = a[j]; a[j] = t;
//			}
//		}
//	}
//	for (i = 1; i <= 5; i++)
//		printf("%d ", a[i]);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a[10], i;
//	for (i = 0; i <= 9; i++) 
//		printf("%d ", a[i]);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//
//	int a, b;
//	char c;
//	scanf_s("%d", &a);
//	scanf_s("%c", &c, 1);
//	scanf_s("%d", &b);
//	if (c == '+')
//		printf("%d\n", a + b);
//	if (c == '-')
//		printf("%d\n", a - b);
//	if (c == '＊')
//		printf("%d\n", a * b);
//	if (c == '/')
//		printf("%d\n", a / b);
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr)
		{
			return head;
		}
		int len = 0;
		ListNode dummy;
		dummy.next = head;
		ListNode* tail = &dummy;
		while (tail->next != nullptr)
		{
			len++;
			tail = tail->next;
		}
		ListNode* prev = &dummy;
		ListNode* p = head;
		k = k % len;
		for (int i = 0; i < len - k; i++)
		{
			prev = p;
			p = p->next;
		}
		if (p != nullptr)
		{
			prev->next = tail->next;
			tail->next = head;
			head = p;
		}
		return head;
	}
};