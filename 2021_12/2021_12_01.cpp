//#include <stdio.h>
//#define ARR_LEN 255 
//#define elemType int 
//
//void bubbleSort(elemType arr[], int len) 
//{
//    elemType temp;
//    int i, j;
//    for (i = 0; i < len - 1; i++)
//        for (j = 0; j < len - 1 - i; j++) {
//            if (arr[j] > arr[j + 1]) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//}
//
//int main() 
//{
//    elemType arr[ARR_LEN] = { 4286,3185,2895,3550,2745 };
//    int len = 5;
//    int i;
//    bubbleSort(arr, len);
//    for (i = 0; i < len; i++)
//        printf("%d\t", arr[i]);
//    putchar('\n');
//    return 0;
//}

//#include <iostream>
//#include<iomanip>
//#include <cmath>
//#include <complex>
//using namespace std;
//
//static const double e = 1e-12;
//
//bool operator == (complex<double> c1, complex<double> c2)
//{
//	return abs(c1 - c2) < e;
//}
//
//int main()
//{
//	complex<double> a, b, c;
//	complex<double> x1, x2;
//	cin >> a >> b >> c;
//	x1 = (-b + sqrt(b * b - a * c * 4.0)) / (a * 2.0);
//	x2 = (-b - sqrt(b * b - a * c * 4.0)) / (a * 2.0);
//	cout << setiosflags(ios::fixed);
//	cout.precision(6);
//	if (abs(x1.imag()) < e)
//	{
//		if (x1 == x2)
//		{
//			cout << "x1=x2=" << x1.real();
//		}
//		else
//		{
//			cout << "x1=" << x1.real() << ";x2=" << x1.real();
//		}
//	}
//	else
//	{
//		cout << "x1=" << x1.real() << "+" << x1.imag() << "i;"
//			<< "x2=" << x2.real() << "+" << x2.imag() << "i";
//	}
//	return 0;
//}

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main()
{
    char buf[MAX_SIZE] = { 0 };
    int i = 0, len = 0, index = 0;
    char maxbuf[12] = { 0 };
    char maxbuf2[12] = { 0 };
    int maxlen = 0;
    gets_s(buf);
    len = strlen(buf);
    maxbuf2[0] = buf[0];
    i = 1;
    index = 1;
    while (i < len)
    {
        if (buf[i] > buf[i - 1])
        {
            maxbuf2[index] = buf[i];
            index++;
        }
        else
        {
            if (index > maxlen)
            {
                maxlen = index;
                strcpy_s(maxbuf, maxbuf2);
                maxbuf[index] = '\0';
                maxbuf2[0] = buf[i];
                index = 1;
            }
            else
            {
                maxbuf2[0] = buf[i];
                index = 1;
            }
        }
        i++;
    }
    if (index > maxlen)
    {
        maxlen = index;
        strcpy_s(maxbuf, maxbuf2);
        maxbuf[index] = '\0';
    }
    printf("最大串长度:%d,字符串:%s\n", maxlen, maxbuf);
    return 0;
}