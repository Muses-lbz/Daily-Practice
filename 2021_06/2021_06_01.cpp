//#include<stdio.h>
//#include<stdlib.h>
//
//int length(char* s)
//{
//    int i = 0;
//    while (*s != '\0')
//    {
//        i++;
//        s++;
//    }
//    return i;
//}
//
//int main()
//{
//    int len;
//    char str[20];
//    printf("请输入字符串:\n");
//    scanf_s("%s", str, 20);
//    len = length(str);
//    printf("字符串有 %d 个字符。\n", len);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int sd[10];
//	for (int i = 0; i < sizeof(sd) / sizeof(sd[0]); i++)
//	{
//		scanf_s("%d", &sd[i]);
//	}
//	for (int i = 0; i < sizeof(sd) / sizeof(sd[0]); i++)
//	{
//		printf("%d\t", sd[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int* p1, * p2, * p, a, b;
//	scanf_s("%d %d", &a, &b);
//	p1 = &a; 
//	p2 = &b;
//	if (a < b)
//	{
//		p = p1; 
//		p1 = p2; 
//		p2 = p;
//	}
//	printf("max=%d,min=%d", *p1, *p2);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char row, space, letter, user_input;
//    printf("Enter a uppercase letter:");
//    scanf_s("%c", &user_input,1);
//    for (row = 'A'; user_input >= row; ++row) 
//    {
//        for (space = user_input - row; space >= 1; --space)
//        {
//            printf(" ");
//        }
//        for (letter = 'A'; row >= letter; letter++) 
//        {
//            printf("%c", letter);
//        }
//        for (letter = row - 1; letter >= 'A'; letter--)
//        {
//            printf("%c", letter);
//        }
//        printf("\n");
//    }
//    int b = getchar();
//    int c = getchar();
//    return 0;
//}

//#include <stdio.h>
//
//#define MAXLINE 1000
//
//int getline(char line[], int maxline);
//
//void copy(char to[], char from[]);
//
//int main()
//{
//    int len;
//    int max;
//    char line[MAXLINE];
//    char longest[MAXLINE];
//    max = 0;
//    while ((len = getline(line, MAXLINE)) > 1)
//    {
//        if (len > max)
//        {
//            max = len;
//            copy(longest, line);
//        }
//    }
//    if (max > 0)
//        printf("%s", longest);
//    int c = getchar();
//    int b = getchar();
//    return 0;
//}
//
//int getline(char s[], int lim)
//{
//    char c, i;
//    c = 0;
//    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//        s[i] = c;
//    if (c == '\n')
//    {
//        s[i] = c;
//        ++i;
//    }
//    s[i] = '\0';
//    return i;
//}
//
//void copy(char to[], char from[])
//{
//    int i;
//    i = 0;
//    while ((to[i] = from[i]) != '\0')
//        ++i;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int length(char* s);
    int len;
    char str[20];
    printf("请输入字符串:\n");
    scanf_s("%s", &str, sizeof(str));
    len = length(str);
    printf("字符串有 %d 个字符。", len);
}
//求字符串长度  
int length(char* s)
{
    int i = 0;
    while (*s != '\0')
    {
        i++;
        s++;
    }
    return i;
}
