//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int number;
//	scanf_s("%d", &number);
//	while ((scanf_s("%d", &number)) == 1)
//	{
//		if (number > 6)
//			if (number < 12)
//				printf("You're    close!\n");
//			else
//				printf("Sorry, you lose a turn!\n");
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h> 
//
//int main()
//{
//	unsigned long num;	// 待测试的数 
//	unsigned long div;	// 可能的约数 
//	bool isPrime;		// 素数标记
//	printf("Please enter an integer for analysis; ");
//	printf("Enter q to quit.\n");
//	while (scanf_s("%lu", &num) == 1)
//	{
//		for (div = 2, isPrime = true; (div * div) <= num; div++)
//		{
//			if (num % div == 0)
//			{
//				if ((div * div) != num)
//					printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
//				else
//					printf("%lu is divisible by %lu.\n", num, div);
//				isPrime = false;  //该数不是素数
//			}
//		}
//		if (isPrime)
//			printf("%lu   is   prime.\n", num);
//		printf("Please enter another integer for  analysis; ");
//		printf("Enter q to quit.\n");
//	}
//	printf("Bye.\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>       // 为isspace()函数提供原型 
//#include <stdbool.h>     // 为bool、true、false 提供定义
//
//constexpr auto STOP = '|';
//
//int main()
//{
//	char c;               // 读入字符 
//	char prev;            // 读入的前一个字符
//	long n_chars = 0L;    // 字符数 
//	int n_lines = 0;      // 行数 
//	int n_words = 0;      // 单词数 
//	int p_lines = 0;      //不完整的行数 
//	bool inword = false;  // 如果 c 在单词中，inword 等于true
//	printf("Enter text to be analyzed (| to terminate):\n");
//	prev = '\n';           // 用于识别完整的行
//	while ((c = getchar()) != STOP)
//	{
//		n_chars++;        // 统计字符
//		if (c == '\n')
//			n_lines++;    // 统计行
//		if (!isspace(c) && !inword)
//		{
//			inword = true;// 开始一个新的单词 
//			n_words++;    // 统计单词
//		}
//		if (isspace(c) && inword)
//			inword = false;    // 打到单词的末尾 
//		prev = c;          // 保存字符的值
//	}
//	if (prev != '\n') p_lines = 1; printf("characters = %ld, words  =  %d,  lines  =  %d,  ", n_chars, n_words, n_lines);
//	printf("partial lines = %d\n", p_lines);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#define COVERAGE 350      // 每罐油漆可刷的面积（单位：平方英尺）
//
//int main()
//{
//	int sq_feet;
//	int cans;
//	printf("Enter number of square feet to be painted:\n");
//	while (scanf_s("%d", &sq_feet) == 1)
//	{
//		cans = sq_feet / COVERAGE;
//		cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
//		printf("You need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");
//		printf("Enter next value (q to quit):\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	float length, width;
//	printf("Enter the length of the rectangle : \n");
//	while (scanf_s("%f", &length) == 1)
//	{
//		printf("Length = %0.2f:\n", length);
//		printf("Enter its width:\n");
//		if (scanf_s("%f", &width) != 1)
//			break;
//		printf("Width = % 0.2f:\n", width);
//		printf("Area = % 0.2f:\n", (double)length * width);
//		printf("Enter the length of the rectangle : \n");
//	}
//	printf("Done.\n");
//	system("pause");
//	return 0;
//}
//

//#include <stdio.h>
//#include <ctype.h> 
//
//int main()
//{
//	char ch;
//	printf("Give me a letter of the alphabet, and I will give  ");
//	printf("an  animal  name\nbeginning  with  that letter.\n");
//	printf("Please type in a letter; type # to end my act.\n");
//	while ((ch = getchar()) != '#')
//	{
//		if ('\n' == ch)
//			continue;
//		if (islower(ch))    /* 只接受小写字母*/
//			switch (ch)
//			{
//			case 'a': printf("argali, a wild sheep of Asia\n");
//				break;
//			case 'b': printf("babirusa, a wild pig of Malay\n");
//				break;
//			case 'c': printf("coati, racoonlike mammal\n");
//				break;
//			case 'd': printf("desman, aquatic, molelike critter\n");
//				break;
//			case 'e': printf("echidna, the spiny anteater\n");
//				break;
//			case 'f': printf("fisher, brownish marten\n");
//				break;
//			/*default: printf("That's a stumper!\n");*/
//			}	/* switch 结束        */
//		else printf("I recognize only lowercase letters.\n");
//		while (getchar() != '\n')
//			continue;    /* 跳过输入行的剩余部分  */
//		printf("Please type another letter or a #.\n");
//	}/* while 循环结束 */
//	printf("Bye!\n");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
//举例如下：一个数组{915,941,960,976,992,1015,1034,1050,1073,1089,1115,1131,1150,1166,1182,1208,1227};
//目标值假设是1000，最接近元素为992，下标为4.
int main()
{
    int min = (1 << 30) - 1;//<<为位运算中的左移，a<<b表示a向左移动b位,移动后在末尾最低位补0
    /*printf("%d", sizeof(int));*/
    int idx = 0;
    int arr[] = { 915,941,960,976,992,1015,1034,1050,1073,1089,1115,1131,1150,1166,1182,1208,1227 };
    int n = 1000;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        int diff = arr[i] - n;
        if (diff < 0) diff = -diff;
        if (diff < min)
        {
            min = diff;
            idx = i;
        }
    }
    printf("最接近的是%d 下标是%d.\n", arr[idx], idx);
    system("pause");
    return 0;
}