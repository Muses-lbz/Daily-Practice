#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 判断一个数是否为质数的函数
    bool isPrime(int num) {
        if (num <= 1) return false; // 小于等于1的数不是质数
        if (num == 2 || num == 3) return true; // 2和3是质数
        if (num % 2 == 0 || num % 3 == 0) return false; // 能被2或3整除的数不是质数
        // 检查是否能被小于等于sqrt(num)的其他数整除
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true; // 如果没有发现因子，说明这个数是质数
    }

    // 返回数组中质数下标的最大距离
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> primeIndices; // 存储质数的下标
        for (int i = 0; i < nums.size(); ++i) {
            if (isPrime(nums[i])) {
                primeIndices.push_back(i); // 将质数的下标加入列表
            }
        }

        if (primeIndices.size() < 2) {
            return 0; // 如果质数少于两个，返回0
        }

        // 计算最大下标和最小下标之间的差值
        //int maxDistance = *max_element(primeIndices.begin(), primeIndices.end()) - *min_element(primeIndices.begin(), primeIndices.end());

         // 计算最大下标和最小下标之间的差值
        int minIndex = primeIndices[0];
        int maxIndex = primeIndices[0];
        for (int i = 1; i < primeIndices.size(); ++i) {
            if (primeIndices[i] < minIndex) {
                minIndex = primeIndices[i];
            }
            if (primeIndices[i] > maxIndex) {
                maxIndex = primeIndices[i];
            }
        }
        int maxDistance = maxIndex - minIndex;

        return maxDistance;
    }
};

// 主函数用于测试
int main() {
    Solution solution;
    vector<int> nums = { 4, 2, 9, 5, 3 }; // 示例输入
    int result = solution.maximumPrimeDifference(nums);
    cout << "最大距离: " << result << endl; // 输出结果
    return 0;
}
