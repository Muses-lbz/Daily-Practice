#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<long long> maximumEvenSplit(long long finalSum) {
		if (finalSum & 1)
			return {};
		vector<long long> res;
		for (int cur = 2; cur <= finalSum; cur += 2) {
			res.push_back(cur);
			finalSum -= cur;
		}
		if (finalSum != 0)//没有刚好排完则将余数与等差数列的最后一项合并
			res.back() += finalSum;
		return res;
	}

};

int main() {
	long long finalSum;
	cout << "Enter the final sum: ";
	cin >> finalSum;

	Solution solution;
	vector<long long> result = solution.maximumEvenSplit(finalSum);

	cout << "Maximum even split: ";
	for (long long num : result) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
