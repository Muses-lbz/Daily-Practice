#include <iostream>
#include <vector>

class Solution {
public:
    int giveGem(std::vector<int>& gem, std::vector<std::vector<int>>& operations) {
        int n = gem.size();

        for (const std::vector<int>& op : operations) {
            int giver = op[0];
            int receiver = op[1];
            int amount = gem[giver] / 2;

            gem[giver] -= amount;
            gem[receiver] += amount;
        }

        int maxGem = gem[0];
        int minGem = gem[0];

        for (int i = 1; i < n; ++i) {
            if (gem[i] > maxGem) {
                maxGem = gem[i];
            }
            if (gem[i] < minGem) {
                minGem = gem[i];
            }
        }

        return maxGem - minGem;
    }
};

int main() {
    // 输入数据
    std::vector<int> gem = { 3, 1, 2 };
    std::vector<std::vector<int>> operations = { {0, 2}, {2, 1}, {2, 0} };

    // 创建解决方案对象
    Solution solution;

    // 调用函数计算宝石差值
    int difference = solution.giveGem(gem, operations);

    // 输出结果
    std::cout << "拥有最多宝石的勇者和拥有最少宝石的勇者宝石数量之差是: " << difference << std::endl;

    return 0;
}
