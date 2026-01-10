//#include <stdio.h>
//
//int main()
//{
//	int len, i, judge = 0;
//	scanf_s("%d", &len);
//	char a[10 + 1];
//	scanf_s("%s", a, 10);
//	if (len % 2 == 0)
//	{
//		for (i = 0; i < (len / 2); i++)
//			if (a[i] != a[(len / 2) + i])
//			{
//				judge = 1;
//				break;
//			}
//		if (judge == 1)
//			printf("No");
//		else 
//		{
//			printf("Yes");
//		}
//	}
//	else
//		printf("No");
//	printf("\n");
//	return 0;
//}

//#include <iostream>
//#include <cmath>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//#define eps 10e-10
//#define N 15
//int a[N];
//bool vis[N];
//
//void dfs(int x) 
//{
//    if (x == 1 || x == 2 || x == 3) 
//    {
//        dfs(x + 1);
//        return;
//    }
//    if (x > 12)
//    {
//        int t[6];
//        t[0] = a[1] + a[3] + a[6] + a[8];
//        t[1] = a[1] + a[4] + a[7] + a[11];
//        t[2] = a[2] + a[3] + a[4] + a[5];
//        t[3] = a[2] + a[6] + a[9] + a[12];
//        t[4] = a[8] + a[9] + a[10] + a[11];
//        t[5] = a[12] + a[10] + a[7] + a[5];
//        for (int i = 1; i < 6; ++i)
//        {
//            if (t[i] != t[i - 1])return;
//        }
//        for (int i = 1; i <= 12; i++) cout << a[i] << " ";
//        return;
//    }
//    for (int i = 1; i < 13; ++i)
//    {
//        if (!vis[i]) 
//        {
//            vis[i] = 1;
//            a[x] = i;
//            dfs(x + 1);
//            vis[i] = 0;
//        }
//    }
//}
//
//int main() 
//{
//    memset(vis, 0, sizeof(vis));
//    cin >> a[1];
//    vis[a[1]] = 1;
//    cin >> a[2];
//    vis[a[2]] = 1;
//    cin >> a[3];
//    vis[a[3]] = 1;
//    dfs(1);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//    int n, i, z[26], max, xia;
//    char c[1050] = { 0 }, ch;
//    scanf_s("%d", &n);
//    while (n > 0)
//    {
//        n--;
//        scanf_s("%s", c,1000);
//        for (i = 0; i < 26; i++)
//            z[i] = 0;
//        xia = strlen(c);
//        
//        for (i = 0; i < xia; i++)
//        {
//            if ((int)c[i] <= 97)
//            {
//                printf("error!");
//            }
//            else
//            {
//                z[c[i] - 'a']++;
//            }
//        }
//        max = z[0]; xia = 0;
//        for (i = 1; i <= 25; i++)
//            if (z[i] > max) 
//            {
//                max = z[i];
//                xia = i;
//            }
//        ch = 'a' + xia;
//        printf("%c %d\n", ch, max);
//    }
//    system("pause");
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	printf("\n");
	system("pause");
	return 0;
}
