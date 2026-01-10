#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 计算nums中的美丽下标对的总数
     * @param nums: 整数数组
     * @return 美丽下标对的总数
     */
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size(); // 数组长度
        int count = 0; // 美丽下标对计数

        // 遍历所有可能的下标对
        for (int i = 0; i < n; ++i) {
            int firstDigitI = getFirstDigit(nums[i]); // 获取nums[i]的第一个数字
            for (int j = i + 1; j < n; ++j) {
                int lastDigitJ = getLastDigit(nums[j]); // 获取nums[j]的最后一个数字
                if (gcd(firstDigitI, lastDigitJ) == 1) { // 检查是否互质
                    ++count; // 计数器增加
                }
            }
        }

        return count; // 返回美丽下标对的总数
    }

private:
    /**
     * 获取数字的第一个数字
     * @param num: 输入数字
     * @return 第一个数字
     */
    int getFirstDigit(int num) {
        while (num >= 10) {
            num /= 10; // 通过不断除以10，获取第一个数字
        }
        return num;
    }

    /**
     * 获取数字的最后一个数字
     * @param num: 输入数字
     * @return 最后一个数字
     */
    int getLastDigit(int num) {
        return num % 10; // 通过对10取模，获取最后一个数字
    }

    /**
     * 计算两个数字的最大公因数（GCD）
     * @param a: 第一个数字
     * @param b: 第二个数字
     * @return 最大公因数
     */
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    // 创建Solution对象
    Solution solution;

    // 示例1
    vector<int> nums1 = { 2, 5, 1, 4 };
    cout << "美丽下标对的总数 (示例1): " << solution.countBeautifulPairs(nums1) << endl; // 输出: 5

    // 示例2
    vector<int> nums2 = { 11, 21, 12 };
    cout << "美丽下标对的总数 (示例2): " << solution.countBeautifulPairs(nums2) << endl; // 输出: 2

    // 更多测试用例
    vector<int> nums3 = { 10, 23, 35, 47 };
    cout << "美丽下标对的总数 (更多测试): " << solution.countBeautifulPairs(nums3) << endl; // 示例输出

    return 0;
}
