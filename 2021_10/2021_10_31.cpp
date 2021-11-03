//#include <stdio.h>
//#include <stdlib.h>
//
//struct TreeNode
//{
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
//static void traverse(struct TreeNode* node, int* result, int* count)
//{
//    if (node == NULL)
//    {
//        return;
//    }
//    traverse(node->left, result, count);
//    result[*count] = node->val;
//    (*count)++;
//    traverse(node->right, result, count);
//}
//
//static int* inorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    if (root == NULL)
//    {
//        *returnSize = 0;
//        return NULL;
//    }
//    int count = 0;
//    int* result = (int*)malloc(5000 * sizeof(int));
//    traverse(root, result, &count);
//    *returnSize = count;
//    return result;
//}
//
//int main()
//{
//    int count = 0;
//    inorderTraversal(NULL, &count);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>  /* 内含字符串函数原型 */
//
//void fit(char*, unsigned int);
//
//int main()
//{
//	char mesg[] = "Things  should  be  as  simple  as  possible, " "  but  not  simpler.";
//	puts(mesg);
//	fit(mesg, 38);
//	puts(mesg);
//	puts("Let's  look  at  some  more  of the  string.");
//	puts(mesg + 39);
//	return  0;
//}
//
//void fit(char* string, unsigned int size)
//{
//	if (strlen(string) > size)
//		string[size] = '\0';
//}

//#include <stdio.h>
//#include <string.h>  /* strcat()函数的原型在该头文件中 */ 
//#define  SIZE  80
//
//char* s_gets(char* st, int n);
//
//int main()
//{
//	char flower[SIZE];
//	char  addon[] = "s smell  like  old  shoes.";
//	puts("What  is  your  favorite  flower ? ");
//	if (s_gets(flower, SIZE))
//	{
//		strcat_s(flower, addon);
//		puts(flower);
//		puts(addon);
//	}
//	else
//		puts("End  of  file  encountered!");
//	puts("bye");
//	return 0;
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
//	return ret_val;
//}

//#include <stdio.h> 
//#include <string.h> 
//#define  SIZE  30
//#define  BUGSIZE  13
//
//char* s_gets(char* st, int n);
//
//int main()
//{
//	char  flower[SIZE];
//	char  addon[] = "s smell  like  old  shoes.";
//	char  bug[BUGSIZE];
//	int available;
//	puts("What  is  your  favorite  flower?");
//	s_gets(flower, SIZE);
//	if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
//		strcat_s(flower, addon);
//	puts(flower);
//	puts("What  is your  favorite  bug ? ");
//	s_gets(bug, BUGSIZE);
//	available = BUGSIZE - strlen(bug) - 1;
//	strncat_s(bug, addon, available);
//	puts(bug);
//	return  0;
//}
//
//char* s_gets(char* st, int n)
//{
//	char* ret_val; int  i = 0;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (st[i] != '\n' && st[i] != '\0')
//			i++;
//		if (st[i] == '\n')
//			st[i] = '\0';
//		else while (getchar() != '\n')
//			continue;
//	}
//	return ret_val;
//}

//#include <stdio.h>
//#define  ANSWER  "Grant" 
//#define  SIZE  40
//
//char* s_gets(char* st, int n);
//
//int main()
//{
//	char t[SIZE];
//	puts("Who  is  buried  in Grant's  tomb?"); 
//	s_gets(t, SIZE);
//	while (t != ANSWER)
//	{
//		puts("No,  that's  wrong.  str again."); 
//		s_gets(t, SIZE);
//	}
//	puts("That's  right!"); 
//	return  0;
//}
//
//char* s_gets(char* st, int n)
//{
//	char* ret_val; int  i = 0;
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

//#include <stdio.h>
//#include <string.h>  // strcmp()函数的原型在该头文件中 
//#define  ANSWER  "Grant"
//#define  SIZE  40
//
//char* s_gets(char* st, int n);
//
//int main()
//{
//	char str[SIZE];
//	puts("Who  is  buried  in Grant's  tomb?");
//	s_gets(str, SIZE);
//	while (strcmp(str, ANSWER) != 0)
//	{
//		puts("No,  that's  wrong.  str again.");
//		s_gets(str, SIZE);
//	}
//	puts("That's  right!");
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

//#include <stdio.h> 
//#include <string.h> 
//
//int main()
//{
//	printf("strcmp(\"A\",  \"A\")  is  ");
//	printf("%d\n", strcmp("A", "A"));
//	printf("strcmp(\"A\",  \"B\")  is  ");
//	printf("%d\n", strcmp("A", "B"));
//	printf("strcmp(\"B\",  \"A\")  is  ");
//	printf("%d\n", strcmp("B", "A"));
//	printf("strcmp(\"C\",  \"A\")  is  ");
//	printf("%d\n", strcmp("C", "A"));
//	printf("strcmp(\"Z\",  \"a\")  is  ");
//	printf("%d\n", strcmp("Z", "a"));
//	printf("strcmp(\"apples\",  \"apple\")  is ");
//	printf("%d\n", strcmp("apples", "apple"));
//	return  0;
//}

#include <stdio.h>
#include <string.h>
#define  SIZE 80
#define  LIM  10
#define  STOP "quit"

char* s_gets(char* st, int n);

int main()
{
	char  input[LIM][SIZE];
	int  ct = 0;
	printf("Enter  up  to  %d lines  (type  quit  to  quit) :\n", LIM);
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP) != 0)
	{
		ct++;
	}
	printf("%d string s entere d\n", ct);
	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int  i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
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