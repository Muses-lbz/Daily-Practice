#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, k, count = 1;
	long long c;
	cin >> n;
	while (n--)
	{
		cin >> k >> c;
		int num = k;
		long long sum = k;
		for (long long i = 2; i <= c; i = sum / k + 1)
		{
			int t = num;
			num += (double)ceil((k * i - sum) * 1.0 / i);
			sum += i * ((double)num - t);
		}
		cout << "Case #" << count++ << ": " << num << endl;
	}
	return 0;
}
