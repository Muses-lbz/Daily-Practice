//#include <stdio.h> 
//#include <string.h>
//#define SIZE  81      /* 限制字符串长度，包括 \0 */
//#define LIM   20      /* 可读入的最多行数 */ 
//#define HALT  ""      /* 空字符串停止输入 */
//
//void stsrt(char* strings[], int num);  /* 字符串排序函数 */
//char* s_gets(char* st, int n);
//
//int main()
//{
//	char input[LIM][SIZE];     /* 储存输入的数组 */
//	char* ptstr[LIM];          /* 内含指针变量的数组 */
//	int ct = 0;                /* 输入计数 */
//	int k;                     /* 输出计数 */
//	printf("Input  up  to  %d  lines,  and  I  will  sort  them.\n", LIM);
//	printf("To  stop, press  the  Enter  key  at  a  line's start.\n");
//	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
//	{
//		ptstr[ct] = input[ct];  /* 设置指针指向字符串 */
//		ct++;
//	}
//	stsrt(ptstr, ct);          /* 字符串排序函数 */
//	puts("\nHere's  the  sorted  list:\n");
//	for (k = 0; k < ct; k++)
//		puts(ptstr[k]); /* 排序后的指针 */
//	return  0;
//}
//
//void stsrt(char* strings[], int num)  /* 字符串-指针-排序函数 */
//{
//	char* temp;
//	int top, seek;
//	for (top = 0; top < num - 1; top++)
//		for (seek = top + 1; seek < num; seek++)
//			if (strcmp(strings[top], strings[seek]) > 0)
//			{
//				temp = strings[top];
//				strings[top] = strings[seek];
//				strings[seek] = temp;
//			}
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

//#include <iostream>
//using namespace std;
//
//int diff(char ch1, char ch2)
//{
//    if (ch1 > ch2)
//        return ch1 - ch2; 
//    else 
//        return ch2 - ch1;
//}
//int main()
//{
//    char a, b;
//    while (1)
//    {
//        cout << "请输入两个小写：";
//        cin >> a >> b;
//        if (a > 'z' || a < 'a' || b > 'z' || b < 'a') break;
//        cout << "文字" << a << "和文字" << b << "的差异是" << diff(a, b) << "。\n";
//    }
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void JosePhus(int n, int m, int start);
//
//int main()
//{
//	int n, m, start;
//	cout << "请输入n,m,start:\n";
//	while (std::cin >> n >> m >> start)
//	{
//		JosePhus(n, m, start);
//		cout << "请输入n,m,start:\n";
//	}
//	return 0;
//}
//
//void JosePhus(int n, int m, int start)
//{
//	int i, * arr = new int[n];
//	int count = 1;
//	for (i = 0; i < n; i++)
//		arr[i] = i + 1;
//	int sum = n;
//	while (count < n)
//	{
//		start--;
//		int index = (start + m - 1) % sum;
//		for (i = index; i < sum - 1; i++)
//			arr[i] = arr[i + 1];
//		start = index + 1;
//		sum--;
//		count++;
//	}
//	cout << arr[0] << "\n";
//}

//#include<stdio.h>
//
//int main()
//{
//    int a[8], s = 0;
//    printf("----------商家商品销售统计----------\n");
//    printf("\n");
//    printf("请输入商品6个月的销售量：");
//    for (int i = 0; i < 6; i++)
//    {
//        scanf_s("%d", &a[i]);
//        s += a[i];
//    }
//    printf("\n\t\t\t商品销量表\t\t\t\n");
//    printf("——————————————————————————————————————————————\n");
//    for (int i = 1; i <= 8; i++)
//    {
//        if (i <= 6)
//            printf("    %d月份 ", i);
//        else if (i == 7)
//            printf("    总销售 ");
//        else
//            printf("    平均销售 \n");
//    }
//    for (int i = 0; i < 8; i++)
//    {
//        if (i < 6)
//            printf("     %d  |", a[i]);
//        else if (i == 6)
//        {
//            a[i] = s;
//            printf("     %d   |", a[i]);
//        }
//        else
//        {
//            a[i] = s / 6;
//            printf("     %d   |", a[i]);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h> 
//#define  LIMIT  81 
//
//void ToUpper(char*);
//int PunctCount(const char*);
//
//int main()
//{
//	char line[LIMIT];
//	char* find;
//	puts("Please  enter a  line:");
//	fgets(line, LIMIT, stdin);
//	find = strchr(line, '\n'); // 查找换行符
//	if (find)                  // 如果地址不是 NULL，
//		*find = '\0';          // 用空字符替换
//	ToUpper(line); puts(line);
//	printf("That  line  has  %d  punctuation  characters.\n", PunctCount(line));
//	return 0;
//}
//
//void ToUpper(char* str)
//{
//	while (*str)
//	{
//		*str = toupper(*str); str++;
//	}
//}
//
//int PunctCount(const char* str)
//{
//	int  ct = 0;
//	while (*str)
//	{
//		if (ispunct(*str))
//			ct++;
//		str++;
//	}
//	return  ct;
//}

#include <stdio.h>

int main(int argc, char* argv[])
{
	int  count;
	printf("The  command  line  has  %d  arguments:\n", argc - 1);
	for (count = 1; count < argc; count++)
		printf("%d:  %s\n", count, argv[count]);
	printf("\n");
	return  0;
}