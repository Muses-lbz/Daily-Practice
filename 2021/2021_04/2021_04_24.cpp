#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int result[12] = { 0 };
	int gold;
	while (cin >> gold)
	{
		if (gold < 0)
		{
			break;
		}
		int code = gold / 10;
		if (code < 4)
		{
			result[3] ++;
		}
		else if (code == 10)
		{
			result[9] ++;
		}
		else
		{
			result[code] ++;
		}
	}
	string word[] = { "0~39", "40~49", "50~59","60~69","70~79", "80~89","90~100" };
	for (int i = 0; i < 7; i++)
	{
		cout << word[i] << " " << result[i + 3] << endl;
	}
	system("pause");
	return 0;
}
