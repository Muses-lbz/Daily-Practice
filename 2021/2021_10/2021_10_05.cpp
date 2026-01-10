//#include <stdio.h>
//#include <limits.h>  // 整型限制 
//#include <float.h>    // 浮点型限制 
//
//int main()
//{
//	printf("Some    number    limits    for    this    system:\n");
//	printf("Biggest  int:  %d\n", INT_MAX);
//	printf("Smallest long long: %lld\n", LLONG_MIN);
//	printf("One byte = %d bits   on   this   system.\n", CHAR_BIT);
//	printf("Largest double: % e\n", DBL_MAX);
//	printf("Smallest   normal float: % e\n", FLT_MIN);
//	printf("float  precision = % d digits\n", FLT_DIG);
//	printf("float   epsilon = % e\n", FLT_EPSILON);
//	return 0;
//}

//#include <stdio.h>
//#define PAGES 959
//
//int main(void)
//{
//	printf("*%d*\n", PAGES);
//	printf("*%2d*\n", PAGES);
//	printf("*%10d*\n", PAGES);
//	printf("*%-10d*\n", PAGES);
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	const double RENT = 3852.99;  // const 变量 
//	printf("*%f*\n", RENT);
//	printf("*%e*\n", RENT);
//	printf("*%4.2f*\n", RENT);
//	printf("*%3.1f*\n", RENT);
//	printf("*%10.3f*\n", RENT);
//	printf("*%10.3E*\n", RENT);
//	printf("*%+4.2f*\n", RENT);
//	printf("*%010.2f*\n", RENT);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	printf("%x %X %#x\n", 31, 31, 31);
//	printf("**%d**%d**%d**\n", 42, 42, -42);
//	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
//	return 0;
//}

//#include <stdio.h>
//#define BLURB "Authentic imitation!"
//
//int main(void)
//{
//	printf("[%2s]\n", BLURB);
//	printf("[%24s]\n", BLURB);
//	printf("[%24.5s]\n", BLURB);
//	printf("[%-24.5s]\n", BLURB);
//	return 0;
//}

//#include <stdio.h>
//
//int main(void)
//{
//	int bph2o = 212;
//	int rv; 
//	rv = printf("%d F is water's boiling point.\n", bph2o); 
//	printf("The printf() function printed % d characters.\n", rv);
//	return 0;
//}

#include <stdio.h>

int main(void)
{
	printf("Here's  one  way  to  print  a  "); 
	printf("long   string.\n");   
	printf("Here's another way to print a \ long string.\n"); 
	printf("Here's the newest way to print a " "long   string.\n");  
	return 0;
}

