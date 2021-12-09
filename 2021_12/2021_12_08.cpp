#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	int len = strs.size();
	string result = "";
	if (len == 0)
		return result;
	int i = 0;
	while (strs[0][i] != '\0')
	{
		for (int j = 0;
			j < len - 1; ++j)
		{
			if (strs[j][i] != strs[j + 1][i])
				return result;
		}
		result += strs[0][i]; ++i;
	}
	return result;
}
int main()
{ // 定义字符数字 动态 
	vector<string> a;
	a.push_back("one");
	a.push_back("on");
	a.push_back("one");
	a.push_back("one");
	a.push_back("one"); // 输入数据
	cout << "最长公共前缀是：" << longestCommonPrefix(a) << endl;
	return 0;
}