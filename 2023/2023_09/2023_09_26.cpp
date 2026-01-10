#include <iostream>

class Solution {
public:
    int passThePillow(int n, int time) {
        // 一个周期的长度
        int cycle = 2 * (n - 1);
        // 计算余数
        int remainder = time % cycle;

        // 如果余数小于等于 n - 1，则枕头在正向传递方向
        if (remainder <= n - 1) {
            return remainder + 1;
        }
        else {
            // 否则，枕头在反向传递方向
            return 2 * n - remainder - 1;
        }
    }
};

int main() {
    int n = 4;
    int time = 5;

    Solution solution;
    int result = solution.passThePillow(n, time);

    std::cout << "在 " << time << " 秒后，拿着枕头的人的编号是：" << result << std::endl;

    return 0;
}
