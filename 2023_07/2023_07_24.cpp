#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // 使用一个unordered_set存储宝石的字符，便于快速查找
        unordered_set<char> jewelSet;
        for (char jewel : jewels) {
            jewelSet.insert(jewel);
        }

        int count = 0;
        // 遍历 stones，统计宝石的数量
        for (char stone : stones) {
            if (jewelSet.count(stone) > 0) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    string jewels = "aA";
    string stones = "aAAbbbb";

    Solution solution;
    int result = solution.numJewelsInStones(jewels, stones);

    cout << "Number of jewels in stones: " << result << endl;

    return 0;
}
