//#include <stdio.h>
//
//int main()
//{
//    char c, c2;
//    printf("输入:");
//    c = getchar();
//    int m = 0, n = 0;
//    if (c >= 'A' && c <= 'z')
//    {
//        m = c - 'A' + 1;
//        if (m < 23)
//        {
//            c2 = c + 4;
//            n = m + 4;
//        }
//    }
//    if (n > 0)
//        printf("%c在第%d个位置,其后面第四个字母是%c\n", c, m, c2);
//    else
//        printf("%c在第%d个位置,其后面没有第四个字母\n", c, m);
//    return 0;
//}

//#include<stdio.h>
//#include <stdlib.h>
//#include<math.h>
////计算sin(x) = x - x ^ 3 / 3!+ x ^ 5 / 5!- X ^ 7 / 7!+ ......, 直到最后一项的绝对值小于10 - 7时停止计算。
////其中 - 2Π <= x <= 2Π， ^ 表示次方，如x ^ 3表示x的3次方。
////输入：
////一个实数x， - 2Π <= x <= 2Π
////输出：
////sin(x)的值
//double Sin(double);
//double nResult(double, double);
//
//int main()
//{
//	double x = 0;
//	scanf_s("%lf", &x);
//	printf("sin(%lf)=%lf\n", x, sin(x));
//	system("pause");
//	return 0;
//}
//
//double Sin(double x)
//{
//	int i = 0;
//	double result = 0, n = 0;
//	while (fabs(n = nResult(x, (double)2 * ++i - 1)) > 0e-7)
//		result += (i % 2 == 1) ? n : -n;
//	return result;
//}
//
//double nResult(double x, double n)
//{
//	return n == 1 ? x : nResult(x, n - 1) * x / n;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* simplifyPath(char* path)
{
	int len = strlen(path);
	if (len == 0)
	{
		return path;
	}
	char* p = path;
	int* indexes = (int*)malloc(len * sizeof(int));
	int depth = 0;
	int name_start = 1;
	while (*p != '\0')
	{
		if (*p == '/')
		{
			if (p > path && *(p - 1) != '/' && *(p - 1) != '.')
			{
				name_start = 1;
			}
		}
		else if (*p == '.')
		{
			if (*(p + 1) == '\0' || *(p + 1) == '/')
			{
				p += 1;
			}
			else if (*(p + 1) == '.' && (*(p + 2) == '\0' || *(p + 2) == '/'))
			{
				if (depth > 0)
				{
					depth--;
					name_start = 1;
				}
				p += 2;
			}
			else
			{
				indexes[depth++] = p - path;
				while (*p != '/' && *p != '\0')
				{
					p++;
				}
			}
			if (*p == '\0')
			{
				break;
			}
		}
		else
		{
			if (name_start && depth >= 0)
			{
				indexes[depth++] = p - path;
				name_start = 0;
			}
		}
		p++;
	}
	int i;
	char* result = (char*)malloc(len + 1);
	char* q = result;
	if (q != NULL)
	{
		if (depth <= 0)
		{
			*q++ = '/';
		}
		else
		{
			for (i = 0; i < depth; i++)
			{
				p = path + indexes[i];
				*q++ = '/';
				while (*p != '/')
				{
					*q++ = *p++;
				}
			}
		}
		*q = '\0';
	}
	return result;
}
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./test path\n");
		exit(-1);
	}
	printf("%s\n", simplifyPath(argv[1]));
	return 0;
}