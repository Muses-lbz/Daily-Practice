#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = static_cast<unsigned int>(carry) << 1;
        }
        return a;
    }
};

int main() {
    Solution solution;
    int num1 = -5;
    int num2 = -7;
    int result = solution.getSum(num1, num2);
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result << std::endl;
    return 0;
}
