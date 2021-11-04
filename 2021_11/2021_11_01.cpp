//#include  <stdio.h> 
//#include  <string.h> 
//#define  LISTSIZE  6 
//
//int  main()
//{
//	const char* list[LISTSIZE] = { "astronomy",  "astounding", "astrophysics",  "ostracize", "asterism",  "astrophobia" };
//	int  count = 0;
//	int  i;
//	for (i = 0; i < LISTSIZE; i++)
//		if (strncmp(list[i], "astro", 5) == 0)
//		{
//			printf("Found:  %s\n", list[i]);
//			count++;
//		}
//	printf("The  list  contained  %d  words beginning" "  with  astro.\n", count);
//	return  0;
//}

//#include <stdio.h>
//#include <string.h>  // strcpy()的原型在该头文件中 
//#define  SIZE  40
//#define  LIM  5
//
//char* s_gets(char* st, int n);
//
//int main()
//{
//	char  qwords[LIM][SIZE];
//	char  temp[SIZE];
//	int  i = 0;
//	printf("Enter  %d  words  beginning  with  q:\n", LIM);
//	while (i < LIM && s_gets(temp, SIZE))
//	{
//		if (temp[0] != 'q')
//			printf("%s  doesn't begin  with  q!\n", temp);
//		else
//		{
//			strcpy_s(qwords[i], temp);
//			i++;
//		}
//	}
//	puts("Here are  the  words  accepted:");
//	for (i = 0; i < LIM; i++)
//		puts(qwords[i]);
//	return  0;
//}
//
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	int  i = 0;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (st[i] != '\n' && st[i] != '\0')
//			i++;
//		if (st[i] == '\n') st[i] = '\0'; else while (getchar() != '\n') continue;
//	} return  ret_val;
//}

//#include <stdio.h>
//#include <string.h>  /* 提供 strncpy()的函数原型*/ 
//#define  SIZE  40
//#define  TARGSIZE  7
//#define  LIM  5
//
//char* s_gets(char* st, int n);
//
//int  main()
//{
//	char  qwords[LIM][TARGSIZE];
//	char  temp[SIZE];
//	int i = 0;
//	printf("Enter  %d  words  beginning  with q : \n", LIM);
//	while (i < LIM && s_gets(temp, SIZE))
//	{
//		if (temp[0] != 'q')
//			printf("%s  doesn't begin  with  q!\n", temp);
//		else
//		{
//			strncpy_s(qwords[i], temp, TARGSIZE - 1);
//			qwords[i][TARGSIZE - 1] = '\0';
//			i++;
//		}
//	}
//	puts("Here  are  the  words accepted:");
//	for (i = 0; i < LIM; i++)
//		puts(qwords[i]);
//	return  0;
//}
//
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	int  i = 0;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (st[i] != '\n' && st[i] != '\0')
//			i++;
//		if (st[i] == '\n')
//			st[i] = '\0';
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return  ret_val;
//}

#include <stdio.h> 
#define  MAX  20

char* s_gets(char* st, int n);

int main()
{
	char first[MAX];      
	char last[MAX]; 
	char formal[2 * MAX + 10]; 
	double  prize; 
	puts("Enter your  first  name:");  
	s_gets(first, MAX);     
	puts("Enter  your  last name : ");  
	s_gets(last,  MAX);
	puts("Enter  your  prize money : "); 
	scanf_s("%lf",  &prize); 
	sprintf_s(formal, "%s,  %-19s: $ % 6.2f\n",  last,  first,  prize); 
	puts(formal); 
	return  0;
}

char* s_gets(char* st, int n)
{
	char* ret_val; 
	int  i = 0;
	ret_val = fgets(st, n, stdin); 
	if(ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n') 
			st[i] = '\0';
		else
			while (getchar() != '\n') 
				continue;
	}
	return  ret_val;
}