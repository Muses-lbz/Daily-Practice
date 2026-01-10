#include <iostream>

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sumOfDigits = 0;
        int temp = x;

        // 计算各个位上的数字之和
        while (temp > 0) {
            sumOfDigits += temp % 10;
            temp /= 10;
        }

        // 检查 x 是否能被 sumOfDigits 整除
        if (x % sumOfDigits == 0) {
            return sumOfDigits;
        }
        else {
            return -1;
        }
    }
};


int main() {
    Solution solution;
    int result = solution.sumOfTheDigitsOfHarshadNumber(18);
    std::cout << "Result: " << result << std::endl;  // 应输出 9
    return 0;
}
