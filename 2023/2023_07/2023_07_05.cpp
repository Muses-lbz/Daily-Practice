#include <iostream>
using namespace std;

class Solution
{
public:
	int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
	{
		// 如果 k 小于等于 numOnes，那么最大和的物品数量就是 k
		if (k <= numOnes)
		{
			return k;
		}
		// 如果 k 大于 numOnes 且小于等于 (numOnes + numZeros)，那么最大和的物品数量就是 numOnes
		else if (k > numOnes && k <= (numOnes + numZeros))
		{
			return numOnes;
		}
		// 否则，最大和的物品数量为 2 * numOnes - k + numZeros
		else
		{
			return 2 * numOnes - k + numZeros;
		}
	}
};

int main()
{
	Solution solution;
	int result = solution.kItemsWithMaximumSum(3, 2, 0, 2);
	cout << result << endl;
	system("pause");
	return 0;
}
