#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int minCount = 0;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] % 2 == 0) {
                minCount += coins[i] / 2; // 如果硬币数量为偶数，每次拿2枚
            }
            else {
                minCount += (coins[i] + 1) / 2; // 如果硬币数量为奇数，拿1枚后剩下的是偶数，每次拿2枚
            }
        }
        return minCount;
    }
};

int main() {
    Solution solution;
    vector<int> coins = { 4, 2, 1 };
    int result = solution.minCount(coins);
    std::cout << "最少需要拿的次数为: " << result << std::endl;
    return 0;
}
