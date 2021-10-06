//#include <stdio.h> 
//
//int  main(void)
//{
//	float  salary;
//	printf("\aEnter your desired monthly salary:");  /* 1 */
//	printf(" $_            \b\b\b\b\b\b\b");         /* 2 */
//	scanf_s("%f", &salary);
//	printf("\n\t$%.2f  a  month is  $%.2f  a  year.", salary, salary * 12.0);   /* 3 */
//	printf("\rGee!\n");  /* 4 */
//	return  0;
//}

//#include <stdio.h>
//
//int main(void)
//
//{
//	float num;
//	printf("Enter a floating-point value: ");
//	scanf_s("%f", &num);
//	printf("fixed-point notation: %f\n", num);
//	printf("exponential notation: %e\n", num);
//	printf("p notation: %a\n", num);
//	return 0;
//}

//#include <stdio.h> 
//
//int main(void)
//{
//	float mass_mol = 3.0e-23;    /* mass of water molecule in grams */
//	float mass_qt = 950;        /*mass of quart of water in grams */
//	float quarts;
//	float molecules;
//	printf("Enter the number of quarts of water: ");
//	scanf_s("%f", &quarts);
//	molecules = quarts * mass_qt / mass_mol;
//	printf("%f quarts of water contain %e molecules.\n", quarts, molecules);
//	return 0;
//}
//
//#include <stdio.h>
//#include <string.h>    // 提供 strlen()函数的原型
//#define DENSITY 62.4   // 人体密度（单位：磅/立方英尺）
//
//int main()
//{
//	double weight, volume;
//	int size, letters;
//	char name[40] = { 0 };      // name 是一个可容纳 40 个字符的数组
//	printf("Hi! What's your first name?\n");
//	gets_s(name);
//	printf("%s, what's your weight in pounds ? \n", name);
//	scanf_s("%lf", &weight); 
//	size = sizeof name; 
//	letters = strlen(name);
//	volume = weight / DENSITY;
//	printf("Well, %s, your volume  is % 2.2f  cubic   feet.\n", name, volume);
//	printf("Also, your  first  name  has % d   letters, \n", letters);
//	printf(" and we have % d bytes to store it.\n", size);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#define PRAISE "You are an extraordinary being."
//
//int main()
//{
//	char name[40];
//	printf("What's your name?\n");
//	gets_s(name);
//	printf("Hello, %s.%s\n", name, PRAISE);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>   
//#define PRAISE "You are an extraordinary being."
//
//int main(void)
//{
//	char  name[40] = { 0 };
//	printf("What's  your  name?  ");  
//	gets_s(name);
//	printf("Hello,  %s.%s\n",name, PRAISE);
//	printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof name); 
//	printf("The phrase of praise has % zd letters  ",strlen(PRAISE)); 
//	printf("and  occupies  %zd  memory cells.\n", sizeof PRAISE); 
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
//PS:CSDN的垃圾代码段 无法直接运行
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode dummy;
    struct ListNode* p, * q, * prev;
    prev = &dummy;
    dummy.next = head;
    p = q = head;
    while (p != NULL)
    {
        while (q != NULL && q->val == p->val)
        {
            q = q->next;
        }
        if (p->next == q)
        {
            prev = p;
        }
        else
        {
            prev->next = q;
        }
        p = q;
    }
    return dummy.next;
}
int main(int argc, char** argv)
{
    int i;
    struct ListNode* head = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* p;
    for (i = 0; i < argc - 1; i++)
    {
        p = (ListNode*)malloc(sizeof(*p));
        p->val = atoi(argv[i + 1]);
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            prev = head;
        }
        else
        {
            prev->next = p;
            prev = p;
        }
    }
    p = deleteDuplicates(head);
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return 0;
}