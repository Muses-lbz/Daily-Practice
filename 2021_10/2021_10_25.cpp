//#include <stdio.h>
//#include <stdlib.h>
//
//void larger_of(double* p1, double* p2);
//
//int main(void)
//{
//	double x, y;
//	printf("Enter two numbers (q to quit): ");
//	while (scanf_s("%lf %lf", &x, &y) == 2)
//	{
//		larger_of(&x, &y);
//		printf("The modified values are %f and %f.\n", x, y);
//		printf("Next two values (q to quit): ");
//	}
//	printf("Bye!\n");
//	system("pause");
//	return 0;
//}
//
//void larger_of(double* p1, double* p2)
//{
//	*p1 = *p2 = *p1 > *p2 ? *p1 : *p2;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void to_base_n(int x, int base);
//
//int main()
//{
//	int number; int b;
//	int count;
//	printf("Enter an integer (q to quit):\n");
//	while (scanf_s("%d", &number) == 1)
//	{
//		printf("Enter number base (2-10): ");
//		while ((count = scanf_s("%d", &b)) == 1 && (b < 2 || b > 10))
//		{
//			printf("base should be in the range 2-10: ");
//		}
//		if (count != 1)
//			break;
//		printf("Base %d equivalent: ", b);
//		to_base_n(number, b);
//		putchar('\n');
//		printf("Enter an integer (q to quit):\n");
//	}
//	printf("Done.\n");
//	system("pause");
//	return 0;
//}
//
//void to_base_n(int x, int base)   /* recursive function */
//{
//	int r;
//	r = x % base;
//	if (x > base)
//		to_base_n(x / base, base);
//	putchar('0' + r);
//	return;
//}

//#include <stdio.h> 
//#define  SIZE  4 
//
//int main()
//{
//	short  dates[SIZE];
//	short* pti;
//	short  index;
//	double bills[SIZE];
//	double* ptf;
//	pti = dates;  // 把数组地址赋给指针
//	ptf = bills;
//	printf("%23s  %15s\n", "short", "double");
//	for (index = 0; index < SIZE; index++)
//		printf("pointers  +  %d:  %10p  %10p\n", index, pti + index, ptf + index);
//	return  0;
//}

//#include <stdio.h>  
//#define SIZE  10          
//
//int sum(int ar[], int  n);
//
//int main()
//{
//	int  marbles[SIZE] = { 20,  10,  5,  39,  4,  16,  19,  26, 31,  20 };
//	long  answer;
//	answer = sum(marbles, SIZE);
//	printf("The  total  number  of  marbles  is  %ld.\n", answer);
//	printf("The  size  of  marbles  is % zd  bytes.\n", sizeof  marbles);
//	return  0;
//}
//
//int sum(int ar[], int n)     // 这个数组的大小是？
//{
//	int  i;
//	int  total = 0;
//	for (i = 0; i < n; i++)
//		total += ar[i];
//	printf("The  size  of  ar  is  %zd  bytes.\n", sizeof  ar);
//	return  total;
//}

//#include <stdio.h>
//#define  SIZE  10
//
//int sump(int* start, int* end);
//
//int main(void)
//{
//	int marbles[SIZE] = { 20,  10,  5,  39,  4,  16,  19,  26, 31,  20 }; 
//	long  answer; 
//	answer = sump(marbles, marbles + SIZE);  
//	printf("The  total  number  of  marbles  is  %ld.\n", answer); 
//	return  0;
//}
//
//int sump(int* start, int* end)/* 使用指针算法 */
//{
//	int  total = 0; 
//	while (start < end)
//	{
//		total += *start;  // 把数组元素的值加起来
//		start++;            // 让指针指向下一个元素
//	}
//	return  total;
//}

//#include <stdio.h>
//
//int data[2] = { 100,  200 };
//
//int moredata[2] = { 300,  400 };
//
//int main()
//{
//	int* p1, * p2, * p3;
//	p1 = p2 = data;
//	p3 = moredata;
//	printf("  *p1 = %d,   *p2 = %d, * p3 = % d\n", *p1, *p2, *p3);
//	printf(" * p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
//	printf(" * p1 = %d, *p2 = %d,*p3 = %d\n", *p1, *p2, *p3);
//	return  0;
//}

#include <stdio.h> 
#include <stdlib.h>

int main()
{
	int  urn[5] = { 100,  200,  300,  400, 500 };
	int* ptr1, * ptr2, * ptr3;
	ptr1 = urn;            // 把一个地址赋给指针 
	ptr2 = &urn[2];        // 把一个地址赋给指针
	// 解引用指针，以及获得指针的地址
	printf("pointer  value,  dereferenced  pointer,  pointer  address:\n");
	printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr3 = ptr1 + 4;// 指针加法
	printf("\nadding  an  int  to  a  pointer:\n");
	printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));

	ptr1++;// 递增指针
	printf("\nvalues  after  ptr1++:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = % p\n", ptr1, *ptr1, &ptr1);

	ptr2--;// 递减指针
	printf("\nvalues  after  --ptr2:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = % p\n", ptr2, *ptr2, &ptr2);

	--ptr1;// 恢复为初始值 
	++ptr2;// 恢复为初始值 
	printf("\nPointers  reset  to  original  values:\n");
	printf("ptr1  =  %p,  ptr2  =  %p\n", ptr1, ptr2);

	// 一个指针减去另一个指针
	printf("\nsubtracting  one  pointer  from  another:\n");
	printf("ptr2  =  %p,  ptr1  =  %p,  ptr2 - ptr1 = % td\n", ptr2, ptr1, ptr2 - ptr1);

	// 一个指针减去一个整数
	printf("\nsubtracting  an  int  from  a  pointer:\n");
	printf("ptr3  =  %p,  ptr3  -  2  =  %p\n", ptr3, ptr3 - 2);
	system("pause");
	return  0;
}
