//#include <stdio.h>
//#include <stdlib.h>
//
//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* partition(struct ListNode* head, int x)
//{
//    struct ListNode dummy;
//    struct ListNode* prev1 = &dummy, * pivot;
//    dummy.next = head;
//    for (pivot = head; pivot != NULL; pivot = pivot->next)
//    {
//        if (pivot->val >= x)
//        {
//            break;
//        }
//        prev1 = pivot;
//    }
//    struct ListNode* p = pivot->next;
//    struct ListNode* prev2 = pivot;
//    while (p != NULL)
//    {
//        if (p->val < x)
//        {
//            prev2->next = p->next;
//            p->next = prev1->next;
//            prev1->next = p;
//            prev1 = p;
//            p = prev2->next;
//        }
//        else
//        {
//            prev2 = p;
//            p = p->next;
//        }
//    }
//    return dummy.next;
//}
//int main(int argc, char** argv)
//{
//    if (argc < 2)
//    {
//        fprintf(stderr, "Usage: ./test target n1 n2 n3...\n");
//        exit(-1);
//    }
//    int i, target = atoi(argv[1]);
//    struct ListNode* head = NULL;
//    struct ListNode* prev = NULL;
//    struct ListNode* p;
//    for (i = 0; i < argc - 2; i++)
//    {
//        p = (ListNode*)malloc(sizeof(*p));
//        p->val = atoi(argv[i + 2]);
//        p->next = NULL;
//        if (head == NULL)
//        {
//            head = p;
//            prev = head;
//        }
//        else
//        {
//            prev->next = p;
//            prev = p;
//        }
//    }
//    p = partition(head, target);
//    while (p != NULL)
//    {
//        printf("%d ", p->val);
//        p = p->next;
//    }
//    printf("\n");
//    return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h>
//
//int main(int argc, char* argv[])
//{
//	int  i, times;
//	if (argc < 2 || (times = atoi(argv[1])) < 1)
//		printf("Usage:  %s  positive-number\n", argv[0]);
//	else
//		for (i = 0; i < times; i++) 
//			puts("Hello,  good  looking!");
//	return  0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int m, n, k;
//    for (m = 1; m <= 1000; m++)
//    {
//        k = m;
//        n = 0;
//        while (k > 0)
//        {
//            n = n * 10 + (k % 10);
//            k = k / 10;
//        }
//        if (m == n) printf("%d ", m);
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void search1() 
//{
//    int i, t = 0;
//    for (i = 10000; i <= 99999; i++)
//    {
//        if (i % 3 == 0 && i % 10 == 6)
//            t++;
//    }
//    cout << t;
//}
//int main()
//{
//    search1();
//    return 0;
//}

//#include <stdio.h> 
//
//int main()
//{
//	int x = 30;              // 原始的x
//	printf("x  in  outer  block:  %d  at  %p\n", x, &x);
//	{
//		int x = 77;        // 新的 x，隐藏了原始的x
//		printf("x  in  inner  block:  %d  at  %p\n", x, &x);
//	} 
//	printf("x  in  outer  block:  %d  at  %p\n", x, &x);
//	while (x++ < 33)        // 原始的x
//	{
//		int x = 100;        // 新的x，隐藏了原始的x
//		x++;
//		printf("x  in  while  loop:  %d  at  %p\n", x, &x);
//	}
//	printf("x  in  outer  block:  %d  at  %p\n", x, &x);
//	return  0;
//}

//#include <stdio.h>
//
//void  trystat(void);
//
//int  main()
//{
//	int  count;
//	for (count = 1; count <= 3; count++)
//	{
//		printf("Here  comes  iteration  %d:\n", count);
//		trystat();
//	}
//	return  0;
//}
//
//void trystat(void)
//{
//	int  fade = 1;
//	static  int  stay = 1;
//	printf("fade  =  %d and  stay  =  %d\n", fade--, stay--);
//}

#include <stdio.h> 

int units = 0; /* 外部变量  */
void  critic(void);

int main()
{
	extern int units;  /* 可选的重复声明*/
	printf("How  many  pounds  to  a  firkin  of  butter ? \n");
	scanf_s("%d", &units);
	while (units != 56)
		critic();
	printf("You  must  have  looked  it  up!\n");
	return  0;
}

void critic(void)
{
	/* 删除了可选的重复声明 */
	printf("No  luck,  my  friend.  Try  again.\n");
	scanf_s("%d", &units);
}