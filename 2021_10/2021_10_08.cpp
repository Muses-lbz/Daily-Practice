//#include <stdio.h>
//
//int main()
//{
//	unsigned width, precision;
//	int number = 256;
//	double   weight = 242.5;
//	printf("Enter   a   field width:\n");
//	scanf_s("%d", &width);
//	printf("The number  is  :%*d:\n", width, number);
//	printf("Now enter a width and a precision:\n");
//	scanf_s("%d", &width);
//	scanf_s("%d", &precision);
//	printf("Weight  =  %*.*f\n", width, precision, weight);
//	printf("Done!\n");
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int    n;   
//	printf("Please    enter    three integers:\n"); 
//	scanf_s("%*d  %*d  %d", &n);
//	printf("The      last      integer was %d\n", n); 
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char fname[40]; char lname[40];
//	printf("Enter your first name: ");
//	scanf_s("%s", fname, 40);
//	printf("Enter your last name: ");
//	scanf_s("%s", lname, 40);
//	printf("%s, %s\n", lname, fname);
//	printf("\n");
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	char* p, str[80];
	p = str;
	gets_s(str);
	while (*p)
		if (*p >= 'A' && *p <= 'Z')
		{
			a++; p++;
		}
		else if (*p >= 'a' && *p <= 'z')
		{
			b++; p++;
		}
		else if (*p == ' ')
		{
			c++; p++;
		}
		else if (*p >= '0' && *p <= '9')
		{
			d++; p++;
		}
		else
		{
			e++; p++;
		}
	printf("大写字母：%d 小写字母：%d 空格：%d 数字：%d 其他：%d\n", a, b, c, d, e);
	system("pause");
	return 0;
}
