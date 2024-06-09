//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    int maxCoins(vector<int>& nums) {
//        int n = (int)nums.size();
//        // 加上两端的虚拟气球
//        vector<int> balloons(n + 2, 1);
//        for (int i = 0; i < n; ++i) {
//            balloons[i + 1] = nums[i];
//        }
//
//        // dp数组，dp[i][j]表示戳破区间[i, j]的最大硬币数
//        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
//
//        // 区间长度从1到n
//        for (int len = 1; len <= n; ++len) {
//            for (int left = 1; left <= n - len + 1; ++left) {
//                int right = left + len - 1;
//                for (int k = left; k <= right; ++k) {
//                    dp[left][right] = max(dp[left][right],
//                        dp[left][k - 1] +
//                        balloons[left - 1] * balloons[k] * balloons[right + 1] +
//                        dp[k + 1][right]);
//                }
//            }
//        }
//
//        // 返回戳破所有气球的最大硬币数
//        return dp[1][n];
//    }
//};
//
//int main() {
//    // 示例输入
//    vector<int> nums = { 1, 5 };
//
//    // 创建Solution对象并调用maxCoins函数
//    Solution sol;
//    int result = sol.maxCoins(nums);
//
//    // 输出结果
//    cout << "戳破所有气球能获得的最大硬币数是: " << result << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//int main()
//{
//	std::vector<int> v;
//
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//
//	for (int i = 0; i < v.size(); ++i)
//	{
//		std::cout << v[i] << " ";
//	}
//	std::cout << std::endl;
//
//	for (auto it = v.begin(); it != v.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	for (int num : v)
//	{
//		std::cout << num << " ";
//	}
//	std::cout << std::endl;
//
//	v.pop_back();
//
//	for (auto it = v.begin(); it != v.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	v.clear();
//
//	for (auto it = v.begin(); it != v.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	//std::vector<int> vec = { 1,2,3,4,5 };

	/*vec.insert(vec.begin() + 2, 10);

	vec.insert(vec.begin() + 3, 3, 7);

	std::vector<int> anothervec = { 8,9 };
	vec.insert(vec.begin() + 5, anothervec.begin(), anothervec.end());

	for (int num : vec)
	{
		std::cout << num << " ";
	}*/

	/*vec.erase(vec.begin() + 2);
	for (int num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	vec.erase(vec.begin() + 1, vec.begin() + 4);
	for (int num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	vec.clear();
	for (int num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;*/

	/*auto it = std::find(vec.begin(), vec.end(), 3);
	if (it != vec.end())
	{
		std::cout << "Found at position:" << std::distance(vec.begin(), it) << std::endl;
	}
	else {
		std::cout << "Not found" << std::endl;
	}

	auto lb = std::lower_bound(vec.begin(), vec.end(), 3);
	std::cout << "Lower bound of 3 is at position:" << std::distance(vec.begin(), lb) << std::endl;*/

	std::vector<int> vec = { 5,3,4,2,1 };
	std::sort(vec.begin(), vec.end());


	std::vector<int>vec2 = { 5,3,3,4,2,1 };
	std::stable_sort(vec2.begin(), vec2.end());

	std::vector<int>vec3 = { 5,3,6,2,1,7,4};
	std::partial_sort(vec3.begin(), vec3.begin() + 4, vec3.end());

	for (int num : vec)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	for (int num : vec2)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	for (int num : vec3)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << std::endl;

	return 0;
}