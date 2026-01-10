//#include <stdlib.h>
//#include <stdio.h>
//
//int main()
//{
//    int id;
//    int a[3] = { 1,2,3 };
//    int au = 0;
//    while (1)
//    {
//        printf("1.剪刀,2.石头,3.布,0.退出\n");
//        scanf_s("%d", &id);
//        if (id == 0)
//            break;
//        au = a[rand() % 3];
//        if (au == 1)
//        {
//            printf("机器：剪刀\t");
//            if (id == 1)
//                printf("玩家:剪刀\t平局\n");
//            else if (id == 2)
//                printf("玩家:石头\t玩家赢\n");
//            else
//                printf("玩家:布\t机器赢\n");
//        }
//        else if (au == 2)
//        {
//            printf("机器：石头\t");
//            if (id == 1)
//                printf("玩家:剪刀\t机器赢\n");
//            else if (id == 2)
//                printf("玩家:石头\t平局\n");
//            else
//                printf("玩家:布\t玩家赢\n");
//        }
//        else
//        {
//            printf("机器：布\t");
//            if (id == 1)
//                printf("玩家:剪刀\t玩家赢\n");
//            else if (id == 2)
//                printf("玩家:石头\t机器赢\n");
//            else
//                printf("玩家:布\t平局\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int isp(int n)
//{
//    int i;
//    if (n < 2)
//        return 0;
//    for (i = 2; i * i <= n; ++i)
//    {
//        if (n % i == 0)
//            return 0;
//    }
//    return 1;
//}
//
//int main()
//{
//    int i = 17;
//    while (i <= 100)
//    {
//        if (isp(i))
//            printf("%d  ", i);
//        i += 10;
//    }
//    printf("\n");
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int pla;
	srand((unsigned int)time(NULL));
	while (1)
	{
		printf("1.剪刀,2.石头,3.布,0.退出\n");
		printf("请输入你的选择：");
		scanf_s("%d", &pla);
		int com = rand() % 3;
		if (pla != 1 && pla != 2 && pla != 3 && pla != 0)
		{
			printf("错误!请输入1、2、3或者0\n");
		}
		else if (pla == 0)
		{
			printf("欢迎下次再来！");
			break;
		}
		else if (pla == 1)
		{
			printf("玩家：剪刀\t");
			if (com == 0)
			{
				printf("机器：剪刀\t");
				printf("平局\n");
			}
			else if (com == 1)
			{
				printf("机器：石头\t");
				printf("机器赢\n");
			}
			else
			{
				printf("机器：布\t");
				printf("玩家赢\n");
			}
		}
		else if (pla == 2)
		{
			printf("玩家：石头\t");
			if (com == 0)
			{
				printf("机器：剪刀\t");
				printf("玩家赢\n");
			}
			else if (com == 1)
			{
				printf("机器：石头\t");
				printf("平局\n");
			}
			else
			{
				printf("机器：布\t");
				printf("机器赢\n");
			}
		}
		else if (pla == 3)
		{
			printf("玩家：布\t");
			if (com == 0)
			{
				printf("机器：剪刀\t");
				printf("机器赢\n");
			}
			else if (com == 1)
			{
				printf("机器：石头\t");
				printf("玩家赢\n");
			}
			else
			{
				printf("机器：布\t");
				printf("平局\n");
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
