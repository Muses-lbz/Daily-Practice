#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 计算从1到x的所有数的二进制表示中"1"的总个数
    long long countOne(long long x) {
        long long res = 0; // 用于累加结果
        int sum = 0;       // 当前处理的"1"的个数

        // 从高位到低位处理x的二进制表示
        for (int i = 60; i >= 0; i--) {
            // 检查x的第i位是否为1
            if (1LL << i & x) {
                // 如果第i位为1，那么前面已经处理的位数中"1"的贡献需要累加到res中
                res += 1LL * sum * (1LL << i);
                sum += 1; // 处理当前位的"1"

                // 如果i大于0，则计算当前位1对低位的贡献
                if (i > 0) {
                    res += 1LL * i * (1LL << (i - 1));
                }
            }
        }
        res += sum; // 最终累加sum的值，作为全部"1"的总数
        return res;
    }

    // 计算从1到x的所有数的二进制表示中"1"的幂值贡献总和
    long long countPow(long long x) {
        long long res = 0; // 用于累加结果
        int sum = 0;       // 当前处理的"1"的位数的总和

        // 从高位到低位处理x的二进制表示
        for (int i = 60; i >= 0; i--) {
            // 检查x的第i位是否为1
            if (1LL << i & x) {
                // 累加已经处理过的"1"对总幂的贡献
                res += 1LL * sum * (1LL << i);
                sum += i; // 累加当前位的幂值

                // 如果i大于0，计算低位的贡献
                if (i > 0) {
                    res += 1LL * i * (i - 1) / 2 * (1LL << (i - 1));
                }
            }
        }
        res += sum; // 最终累加sum的值，作为全部幂值的总和
        return res;
    }

    // 快速幂计算 x^y % mod
    int pow_mod(long long x, long long y, int mod) {
        int res = 1;
        while (y) {
            // 如果当前位为1，累乘x并取模
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod; // 更新x为x^2
            y >>= 1;         // 右移y，处理下一位
        }
        return res;
    }

    // 使用二分查找寻找第一个使得 countOne(mid) >= x 的数
    long long mid_check(long long x) {
        long long l = 1, r = 1000000000000000LL;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (countOne(mid) >= x) {
                r = mid; // 如果 countOne(mid) 大于或等于 x，收缩右边界
            }
            else {
                l = mid + 1; // 否则，收缩左边界
            }
        }
        return r;
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            // 将查询的fromi和toi从0基调整为1基（因为内部计算是基于1开始的）
            queries[i][0]++;
            queries[i][1]++;

            // 使用二分查找确定区间内的左边界l和右边界r
            long long l = mid_check(queries[i][0]);
            long long r = mid_check(queries[i][1]);
            int mod = (int)queries[i][2];

            long long res = 1;
            long long pre = countOne(l - 1); // 计算l-1时"1"的总个数
            for (int j = 0; j < 60; j++) {
                if (1LL << j & l) { // 检查l的第j位是否为1
                    pre++;
                    // 如果pre在查询区间内，累乘当前位的贡献
                    if (pre >= queries[i][0] && pre <= queries[i][1]) {
                        res = res * (1LL << j) % mod;
                    }
                }
            }

            // 如果r > l，则继续处理r的情况
            if (r > l) {
                long long bac = countOne(r - 1); // 计算r-1时"1"的总个数
                for (int j = 0; j < 60; j++) {
                    if (1LL << j & r) { // 检查r的第j位是否为1
                        bac++;
                        // 如果bac在查询区间内，累乘当前位的贡献
                        if (bac >= queries[i][0] && bac <= queries[i][1]) {
                            res = res * (1LL << j) % mod;
                        }
                    }
                }
            }

            // 如果r和l之间有超过1的差距，处理这段区间内所有数字的贡献
            if (r - l > 1) {
                long long xs = countPow(r - 1) - countPow(l); // 计算这段区间的幂贡献总和
                res = res * pow_mod(2LL, xs, mod) % mod; // 通过快速幂计算总贡献并取模
            }
            ans.push_back(static_cast<int>(res)); // 将结果加入到答案中
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<long long>> queries = { {1, 3, 7}, {2, 5, 3}, {7, 7, 4} };

    // 调用 findProductsOfElements 函数并输出结果
    vector<int> result = sol.findProductsOfElements(queries);

    for (int r : result) {
        cout << r << endl;
    }

    return 0;
}
