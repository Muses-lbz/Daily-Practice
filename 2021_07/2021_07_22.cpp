#include <iostream>
#include <string>
using namespace std;

string a[105];
int b[105], c[105];

int qiujishu(string x)
{
	int jishu = 0;
	for (int i = 0; x.c_str()[i]; i++)
	{
		if ((x.c_str()[i] - '0') % 2 == 1) jishu++;
	}
	return jishu;
}
int qiuoushu(string x)
{
	int oushu = 0;
	for (int i = 0; x.c_str()[i]; i++)
	{
		if ((x.c_str()[i] - '0') % 2 == 0) oushu++;
	}
	return oushu;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = qiujishu(a[i]);
		c[i] = qiuoushu(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << b[i] << " " << c[i] << endl;
	}
	return 0;
}
