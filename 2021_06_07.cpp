//#include <stdio.h>
//
//int n, d[100];
//bool v[100];
//
//int main() 
//{
//    scanf_s("%d", &n);
//    for (int i = 0; i < n; ++i) 
//    {
//        scanf_s("%d", d + i);
//        v[i] = false;
//    }
//    int cnt = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        if (!v[i])
//        {
//            for (int j = i; !v[j]; j = d[j]) 
//            {
//                v[j] = true;
//            }
//            ++cnt;
//        }
//    }
//    printf("%d\n", cnt);
//    return 0;
//}
////输入：10 7 1 4 3 2 5 9 8 0 6

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void Guess_num(void)
//{
//	int n;
//	char begin;
//	int count = 1;
//	srand((unsigned int)time(NULL));
//	int m = (rand() % 100) + 1;
//	puts("游戏开始，请输入数字:");
//	while (1)
//	{
//		scanf_s("%d", &n);
//		if (n == m)
//		{
//			printf("猜中了，使用了 %d 次！\n", count);
//			if (count == 1)
//			{
//				printf("你是神级人物了！膜拜\n");
//				int a = getchar();
//				printf("你已经达到最高级别，还需要玩吗？Y/N \n");
//				scanf_s("%c", &begin, 1);
//				if (begin == 'Y' || begin == 'y')      //重复玩的一个嵌套循环
//				{
//					Guess_num();
//				}
//				else
//				{
//					printf("谢谢，再见!\n");
//				}
//			}
//			else if (count <= 5)
//			{
//				printf("你是王级人物了！非常赞\n");
//				int b = getchar();
//				printf("需要挑战最高级别不？Y/N \n");
//				scanf_s("%c", &begin, 1);
//				if (begin == 'Y' || begin == 'y')
//				{
//					Guess_num();
//				}
//				else
//				{
//					printf("谢谢，再见!\n");
//				}
//			}
//			else if (count <= 10)
//			{
//				printf("你是大师级人物了！狂赞\n");
//				int c = getchar();
//				printf("需要挑战最高级别不？Y/N \n");
//				scanf_s("%c", &begin, 1);
//				if (begin == 'Y' || begin == 'y')
//				{
//					Guess_num();
//				}
//				else
//				{
//					printf("谢谢，再见!\n");
//				}
//			}
//			else if (count <= 15)
//			{
//				printf("你是钻石级人物了！怒赞\n");
//				int d = getchar();
//				printf("需要挑战最高级别不？Y/N \n");
//				scanf_s("%c", &begin, 1);
//				if (begin == 'Y' || begin == 'y')
//				{
//					Guess_num();
//				}
//				else
//				{
//					printf("谢谢，再见!\n");
//				}
//			}
//			else
//			{
//				int e = getchar();
//				printf("你的技术还有待提高哦！重玩？ Y/N\n");
//				scanf_s("%c", &begin, 1);
//				if (begin == 'Y' || begin == 'y')
//				{
//					Guess_num();
//				}
//				else
//				{
//					printf("谢谢，再见!\n");
//				}
//			}
//			break;
//		}
//		else if (n < m)
//		{
//			puts("太小了!");
//			puts("重新输入:");
//		}
//		else
//		{
//			puts("太大了!");
//			puts("重新输入:");
//		}
//		count++;//计数器
//
//
//	}
//}
//
//
//int main(void)
//{
//
//	Guess_num();
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void print(int value)
//{
//	int x;
//	while (1)
//	{
//		scanf_s("%d", &x);
//		if (x > value)
//		{
//			printf("It is bigger than target value.\n");
//		}
//		else if (x < value)
//		{
//			printf("It is smaller than target value.\n");
//		}
//		else
//		{
//			printf("You are win!\n");
//			break;
//		}
//	}
//
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int value = rand() % 100;
//	/*printf("%d\n", value);*/
//	print(value);
//	system("pause");
//	return 0;
//}

