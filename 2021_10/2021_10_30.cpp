//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//	char a[100] = { 0 };
//	unsigned int i;
//	int zyy = 1;
//	int fyy = 1;
//	printf("请输入字符串:");
//	gets_s(a);
//	for (i = 1; i < strlen(a); i++)
//	{
//		if (a[i] < a[i - 1])
//		{
//			zyy = 0;
//			break;
//		}
//	}
//	for (i = 1; i < strlen(a); i++)
//	{
//		if (a[i] > a[i - 1])
//		{
//			fyy = 0;
//			break;
//		}
//	}
//	if (zyy && !fyy)
//	{
//		printf("Positive elegance\n");
//	}
//	else if (!zyy && fyy)
//	{
//		printf("Negative elegance\n");
//	}
//	else
//	{
//		printf("Non elegance\n");
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//string StrCon(const string& a, const string& b)
//{
//    string c;
//    int n = a.size(), m = b.size();
//    if (0 == n)    
//        return a;
//    if (0 == m) 
//        return b;
//    int i, j;
//    for (i = 0, j = 0; i < n && j < m; ++i, ++j)
//    {
//        c += a[i];
//        c += b[i];
//    }
//    while (i < n)
//    {
//        c += a[i++];
//    }
//    while (j < m)
//    {
//        c += b[j++];
//    }
//    return c;
//}
//
//int main()
//{
//    string s = "day", t = "time";
//    cout << StrCon(s, t) << endl;
//    system("pause");
//    return 0;
//}

//#include <stdio.h> 
//#define  STLEN  81 
//
//int main()
//{
//	char words[STLEN] = { 0 };
//	puts("Enter  a  string,  please.");
//	gets_s(words);  // 典型用法 
//	printf("Your  string  twice:\n");
//	printf("%s\n", words); 
//	puts(words);
//	puts("Done.");
//	return  0;
//}

//#include <stdio.h> 
//#define  STLEN  14 
//
//int main()
//{
//	char  words[STLEN] = { 0 };
//	puts("Enter  a  string, please.");
//	fgets(words, STLEN, stdin);
//	printf("Your  string  twice(puts(), then  fputs()) :\n");
//	puts(words);
//	fputs(words, stdout);
//	puts("Enter  another  string, please.");
//	fgets(words, STLEN, stdin);
//	printf("Your string  twice(puts(),  then  fputs()) :\n");
//	puts(words);
//	fputs(words, stdout);
//	puts("Done.");
//	return  0;
//}

//#include <stdio.h> 
//#define  STLEN  10 
//
//int main()
//{
//	char  words[STLEN] = { 0 };
//
//	int  i;
//	puts("Enter  strings  (empty  line  to  quit) :");
//	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
//	{
//		i = 0;
//		while (words[i] != '\n' && words[i] != '\0')
//			i++;
//		if (words[i] == '\n') 
//			words[i] = '\0';
//		else  // 如果 word[i] == '\0'则执行这部分代码
//			while (getchar() != '\n')
//				continue;
//		puts(words);
//	}
//	puts("done");
//	return  0;
//}

//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	int  i = 0;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)  // 即，ret_val != NULL
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

//#include <stdio.h>
//#define  DEF  "I  am  a  #defined  string." 
//
//int main()
//{
//	char  str1[80] = "An array  was  initialized  to  me.";
//	const char* str2 = "A pointer was initialized to me.";
//	puts("I'm an  argument  to  puts().");
//	puts(DEF);
//	puts(str1);
//	puts(str2);
//	puts(&str1[5]);
//	puts(str2 + 4);
//	return  0;
//}

//#include <stdio.h> 
//
//int main()
//{
//	char  side_a[] = "Side  A";
//	char  dont[] = { 'W',  'O',  'W',  '!','\0' };
//	char  side_b[] = "Side  B";
//	puts(dont); /* dont 不是一个字符串 */
//	return  0;
//}

#include <stdio.h> 

void put1(const char*);
int  put2(const char*);

int main()
{
	put1("If  I'd  as much  money");
	put1(" as  I  could spend,\n");
	printf("I count  %d  characters.\n", put2("I never  would  cry   old  chairs  to mend."));
	return  0;
}

void put1(const char* string)
{
	while (*string)  /* 与 *string != '\0' 相同 */
		putchar(*string++);
}

int put2(const char* string)
{
	int  count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');
	return(count);
}