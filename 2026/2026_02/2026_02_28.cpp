#include <iostream>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = (int)(1e9 + 7);
        long long ans = 0;
        int bitLength = 0;  // 当前二进制位数

        for (int i = 1; i <= n; i++) {
            // 如果 i 是 2 的幂，则位数增加
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }

            // 左移 bitLength 位，相当于拼接
            ans = ((ans << bitLength) + i) % MOD;
        }

        return static_cast<int>(ans);
    }
};

int main() {
    Solution sol;
    int n = 12;
    cout << sol.concatenatedBinary(n) << endl;  // 输出 505379714
    return 0;
}