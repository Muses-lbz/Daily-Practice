#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> sameNumbers;

        // Step 1: 找到正面和背面数字相同的卡片的数字
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == backs[i]) {
                sameNumbers.insert(fronts[i]);
            }
        }

        int minNumber = INT_MAX;

        // Step 2: 从剩余的数字中找到最小的数字
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] != backs[i]) {
                if (sameNumbers.find(fronts[i]) == sameNumbers.end()) {
                    minNumber = min(minNumber, fronts[i]);
                }
                if (sameNumbers.find(backs[i]) == sameNumbers.end()) {
                    minNumber = min(minNumber, backs[i]);
                }
            }
        }

        // Step 3: 如果没有符合要求的数字，输出0，否则输出找到的最小数字
        return minNumber == INT_MAX ? 0 : minNumber;
    }
};

int main() {
    vector<int> fronts = { 1, 2, 4, 4, 7 };
    vector<int> backs = { 1, 3, 4, 1, 3 };

    Solution solution;
    int result = solution.flipgame(fronts, backs);

    cout << "最小的数字是：" << result << endl;

    return 0;
}
