//#include <stdio.h>
//#include <stdlib.h>
////一个简易的菜单程序
//char get_choice(void);
//char get_first(void);
//int  get_int(void);
//void count(void);
//
//int  main()
//{
//	int  choice;
//	void  count(void);
//	while ((choice = get_choice()) != 'q')
//	{
//		switch (choice)
//		{
//		case  'a':   printf("Buy low,  sell  high.\n");
//			break;
//		case'b': putchar('\a');   /*  ANSI   */
//			break;
//		case  'c': count();
//			break;
//		default:printf("Program error!\n");
//			break;
//		}
//	}
//	printf("Bye.\n");
//	system("pause");
//	return  0;
//}
//
//void count(void)
//{
//	int  n, i;
//	printf("Count  how  far?  Enter  an integer:\n");
//	n = get_int();
//	for (i = 1; i <= n; i++)
//		printf("%d\n", i);
//	while (getchar() != '\n')
//		continue;
//}
//
//char get_choice(void)
//{
//	int ch;
//	printf(" Enter the letter of  your choice:\n");
//	printf(" a. advice b. bell\n");
//	printf(" c. count  q. quit\n");
//	ch = get_first();
//	while ((ch < 'a' || ch  >  'c') && ch != 'q')
//	{
//		printf("Please  respond  with  a,  b,  c,  or q.\n");
//		ch = get_first();
//	}
//	return  ch;
//}
//
//char get_first(void)
//{
//	int  ch;
//	ch = getchar();
//	while (getchar() != '\n')
//		continue;
//	return  ch;
//}
//
//int get_int(void)
//{
//	int  input;
//	char  ch;
//	while (scanf_s("%d", &input) != 1)
//	{
//		while ((ch = getchar()) != '\n')
//			putchar(ch);  //处理错误输出 
//		printf("  is  not  an  integer.\nPlease  enter an  ");
//		printf("integer  value,  such  as  25,  - 178, or 3:  ");
//	}
//	return input;
//}
//

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char a, b;
//	scanf_s("%c",&a,1);
//	b=getchar();
//	printf("%d %d", a, b);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#define  NAME  "GIGATHINK,  INC." 
//#define  ADDRESS  "101  Megabuck  Plaza" 
//#define  PLACE  "Megapolis,  CA  94904" 
//#define  WIDTH  40 
//
//void starbar(void);  /* 函数原型 */ 
//
//int main()
//{
//	starbar();
//	printf("%s\n", NAME);
//	printf("%s\n", ADDRESS); 
//	printf("%s\n", PLACE); 
//	starbar();      /* 使用函数 */
//	return  0;
//}
//
//void starbar(void)  /* 定义函数  */
//{
//	int count;
//	for (count = 1; count <= WIDTH; count++)
//		putchar('*');
//	putchar('\n');
//}

//#include  <stdio.h>
//#include <string.h>  /* 为 strlen()提供原型 */
//#define  NAME  "GIGATHINK,  INC."
//#define  ADDRESS  "101  Megabuck  Plaza"
//#define  PLACE  "Megapolis,  CA  94904" 
//#define  WIDTH  40
//#define  SPACE  '  '
//
//void  show_n_char(char  ch, int  num);
//
//int  main()
//{
//	int spaces;
//	show_n_char('*', WIDTH);  /* 用符号常量作为参数 */
//	putchar('\n');
//	show_n_char(SPACE, 12);  /* 用符号常量作为参数 */
//	printf("%s\n", NAME);
//	spaces = (WIDTH - strlen(ADDRESS)) / 2;  /* 计算要跳过多少个空格*/
//	show_n_char(SPACE, spaces);  /* 用一个变量作为参数*/
//	printf("%s\n", ADDRESS);
//	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
//	printf("%s\n", PLACE);  /* 用一个表达式作为参数*/
//	show_n_char('*', WIDTH); \
//		putchar('\n');
//	return  0;
//}
//void  show_n_char(char  ch, int  num)/* show_n_char()函数的定义 */
//{
//	int  count;
//	for (count = 1; count <= num; count++)
//		putchar(ch);
//}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static bool canJump(int* nums, int numsSize)
{
    int i, pos = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        if (pos < i || pos >= numsSize - 1)
        {
            break;
        }
        pos = max(i + nums[i], pos);
    }
    return pos >= numsSize - 1;
}

int main(int argc, char** argv)
{
    int i, count = argc - 1;
    int* nums = (int*)malloc(count * sizeof(int));
    for (i = 0; i < count; i++)
    {
        nums[i] = atoi(argv[i + 1]);
    }
    printf("%s\n", canJump(nums, count) ? "true" : "false");
    return 0;
}
