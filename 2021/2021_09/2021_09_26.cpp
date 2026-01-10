//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int  x = 100;
//	printf("dec=%d; octal=%o; hex=%x\n", x, x, x);
//	printf("dec=%d; octal=%#o; hex=%#x\n", x, x, x);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	unsigned int un = 3000000000; /* int 为 32 位和 short 为 16 位的系统 */  
//	short  end = 200;  long  big = 65537;  long  long verybig = 12345678908642;
//	printf("un = %u and not %d\n", un,un);        
//	printf("end = %hd and %d\n", end,end);       
//	printf("big = %ld and not %hd\n", big,big);         
//	printf("verybig = %I64d and not %lld\n",verybig,verybig);
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char  ch; 
//	printf("Please  enter  a  character:"); 
//	scanf_s("%c", &ch, 1);  /* 用户输入字符 */
//	printf("The code  for% c  is% d.\n",  ch,  ch); 
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <inttypes.h> // 支持可移植类型
//
//int main()
//{
//	int32_t me32;    // me32 是一个 32 位有符号整型变量 
//	me32 = 45933945;
//	printf("First,  assume  int32_t  is  int:  ");
//	printf("me32 = % d\n", me32);
//	printf("Next, let's not make any assumptions.\n");
//	printf("Instead, use a \"macro\" from inttypes.h:  ");
//	printf("me32 = %" PRId32 "\n", me32);
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int oneNum(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt++;
        x = x & (x - 1);
    }
    return cnt;
}

int cmp(const void* a, const void* b)
{
    int al, bl;
    int ret;
    al = *(int*)a;
    bl = *(int*)b;
    ret = oneNum(al) - oneNum(bl);
    return  ret ? ret : al - bl;
}

int main()
{
    int s[] = { 1,2,3,5,6,7,8 }, i;
    int len = sizeof(s) / sizeof(*s);
    qsort(s, len, 4, cmp);
    for (i = 0; i < len; i++)
    {
        printf("%d\n", s[i]);
    }
    system("pause");
    return 0;
}