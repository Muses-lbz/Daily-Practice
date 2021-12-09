//#include <stdio.h>
//
//int isprime(int x)
//{
//	if (x == 0 || x == 1) return 0;
//	for (int i = 2; i <= x / 2; i++)
//		if (!(x % i)) return 0;
//	return 1;
//}
//int isallprime(int x)
//{
//	do
//	{
//		if (!isprime(x)) return 0;
//		x /= 10;
//	} while (x > 0);
//	return 1;
//}
//
//int main()
//{
//	for (int i = 111; i <= 1000; i++)
//		if (isallprime(i))
//			printf("%d\n", i);
//	return 0;
//}

#include <iostream>
#include<iomanip>
#include <cmath>
#include <complex>
using namespace std;
static const double e = 1e-12;
bool operator == (complex<double> c1, complex<double> c2) { return abs(c1 - c2) < e; }
int main()
{
    complex<double> a, b, c;
    complex<double> x1, x2;
    cin >> a >> b >> c;
    x1 = (-b + sqrt(b * b - a * c * 4.0)) / (a * 2.0);
    x2 = (-b - sqrt(b * b - a * c * 4.0)) / (a * 2.0);
    cout << setiosflags(ios::fixed);
    cout.precision(6);
    if (abs(x1.imag()) < e)
    {
        if (x1 == x2) {
            cout << "x1=x2=" << x1.real();
        }
        else {
            cout << "x1=" << x1.real() << ";x2=" << x1.real();
        }
    }
    else {
        cout << "x1=" << x1.real() << "+" << x1.imag() << "i;"
            << "x2=" << x2.real() << "+" << x2.imag() << "i";
    }
    return 0;
}