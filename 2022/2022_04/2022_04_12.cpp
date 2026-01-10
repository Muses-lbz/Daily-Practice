//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int s[3];
//	for (int i = 0; i < 3; i++)
//		scanf_s("%d", &s[i]);
//	int max = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		if (max < s[i])
//			max = s[i];
//	}
//	printf("%d\n",max);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	int cnt = 0, count = 0;
	do {
		scanf_s("%c", &c, 1);
		if (cnt == 0 && c == ' ')
			continue;
		if (cnt == 0 && c == '.')
			break;
		if (c == ' ')
		{
			if (count == 0)
				printf("%d", cnt);
			else
				printf(" %d", cnt);
			cnt = 0;
			count++;
			continue;
		}
		if (c == '.')
		{
			if (count == 0)
				printf("%d", cnt);
			else
				printf(" %d", cnt);
			break;
		}
		cnt++;
	} while (c != '.');
	return 0;
}