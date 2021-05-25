//#include<stdio.h>
//
//int main()
//{
//	int a = 0, c = 0;
//	do 
//	{
//		--c;
//		a = a - 1;
//	} 
//	while (a > 0);
//	printf("%d", c);
//}

//#include<stdio.h>
//
//int func(int i, int j) 
//{
//	if (i <= 0 || j <= 0)
//		return 1;
//	return 2 * func(i - 3, j / 2);
//}
//
//int main()
//{
//	func(15, 20);
//	printf("%d", func(15, 20));
//	return 0;
//}

//#include <stdio.h>
//
//int fun(char s[])
//{
//    char* p = s;
//    while (*p != 0) p++;
//    return (p - s);
//}
//
//int main()
//{
//    printf("%d\n ", fun((char*)"OABCDEF"));
//}

//#include <stdio.h>
//
//int main()
//{
//    /*char a = '\82';*/
//    int i = 0;
//    i = ~i;
//    printf("%d\n", i);
//    /*printf("%c", a);*/
//}

//#include< stdio.h>
//
//char f(char x)
//{
//    return x * x + 'a';
//}
//int main() 
//{
//    char a, b = 0;
//    for (a = 0; a < 4; a += 1) 
//    {
//        b = f(a);
//        putchar(b);
//    }
//}

//#include<stdio.h>
//
//int main()
//{
//	int a, b, x, i; 
//	a = 3; 
//	b = 4; 
//	i = 3;  
//	x = a > b ? i++ : i--;
//	printf("%d", x);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char dog[] = "wang\0miao";
//	printf("%d\n", sizeof(dog));
//	printf("%d\n", strlen(dog));
//	return 0;
//}

//#include <stdio.h>
//
//int f(int a[], int n)
//{
//    if (n > 1)
//    {
//        int t;
//        t = f(a, n - 1);
//        return t > a[n - 1] ? t:a[n - 1];
//    }
//    else
//        return a[0];
//}
//
//int main()
//{
//    int a[ ] = { 8,2,9,1,3,6,4,7,5 };
//    printf("%d\n", f(a,9));
//}

//#include<stdio.h>
//
//int main()
//{
//	int x = 1; 
//	int y = ~x;
//	printf("%d", y);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int  a[] = { 1,2,3,4,5,6,7,8,9,0 }, * p;
//	for (p = a; p < a + 10; p++)
//		printf("%d,", *p);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int x = 1, y = 2, z = 3;
//	int a1 = x + y - z; int b1 = x * y / z;
//	int a2 = x - z + y; int b2 = x / z * y;
//	int c1 = x << y >> z; int d1 = x & y | z;
//	int c2 = x >> z << y; int d2 = x | z & y;
//	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", a1, a2, b1, b2, c1, c2, d1, d2);
//	return 0;
//}

#include <stdio.h> 

int main()
{
	char c;
	int v0 = 0, v1 = 0, v2 = 0;
	do {
		switch (c = getchar())
		{
		case 'a':case 'A ':
		case 'e':case 'E ':
		case 'i':case 'I ':
		case 'o':case 'O ':
		case 'u':case 'U ':v1 += 1;
		default:v0 += 1; v2 += 1;
		}
	} while (c != '\n');
	printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
	return 0;
}