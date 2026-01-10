//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution
//{
//public:
//	std::vector<int> twoSum(std::vector<int>& numbers, int target)
//	{
//		int left = 0;                 // 左指针
//		int right = numbers.size() - 1;  // 右指针
//
//		while (left < right)
//		{
//			int sum = numbers[left] + numbers[right];
//
//			if (sum == target)
//			{
//				return { left + 1, right + 1 };  // 下标从1开始，所以需要加1
//			}
//			else if (sum < target)
//			{
//				left++;  // 和小于目标数，移动左指针向右
//			}
//			else
//			{
//				right--;  // 和大于目标数，移动右指针向左
//			}
//		}
//
//		return {};  // 没有找到满足条件的两个数，返回空数组
//	}
//};
//
//int main()
//{
//	Solution solution;
//	std::vector<int> numbers = { 2, 7, 11, 15 };
//	int target = 9;
//
//	std::vector<int> result = solution.twoSum(numbers, target);
//
//	if (result.empty())
//	{
//		std::cout << "No two numbers found." << std::endl;
//	}
//	else
//	{
//		std::cout << "Indices of the two numbers: " << result[0] << ", " << result[1] << std::endl;
//	}
//
//	return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 定义函数，计算最大的偶数拆分
    vector<long long> maximumEvenSplit(long long finalSum) {
        // 如果目标和为奇数，则无法拆分成偶数的和，返回空数组
        if (finalSum & 1)
            return {};

        vector<long long> res;  // 存储拆分结果
        for (int cur = 2; cur <= finalSum; cur += 2) {
            res.push_back(cur);   // 将偶数加入结果数组
            finalSum -= cur;      // 减去已经加入的偶数
        }

        // 如果无法刚好拆分完毕，将余数与等差数列的最后一项合并
        if (finalSum != 0)
            res.back() += finalSum;

        return res;  // 返回拆分结果
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
