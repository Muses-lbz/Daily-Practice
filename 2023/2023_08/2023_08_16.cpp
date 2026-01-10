//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<int> circularGameLosers(int n, int k) {
//        int step = 1, cur = 0;
//        unordered_set<int> dict;
//        vector<int> res;
//
//        while (true) {
//            if (dict.count(cur)) {
//                break;
//            }
//            else {
//                dict.emplace(cur);
//                cur = (cur + step * k) % n;
//                step++;
//            }
//        }
//
//        for (int i = 0; i < n; i++) {
//            if (!dict.count(i)) {
//                res.emplace_back(i + 1);
//            }
//        }
//
//        return res;
//    }
//};
//
//int main() {
//    Solution solution;
//    int n = 5;
//    int k = 2;
//    vector<int> losers = solution.circularGameLosers(n, k);
//
//    cout << "Losers: ";
//    for (int loser : losers) {
//        cout << loser << " ";
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int step = 1, cur = 0;  // 初始化步数和当前持球朋友编号
        unordered_set<int> dict;  // 哈希集合，用于记录已接到球的朋友
        vector<int> res;  // 存放失败者的结果数组

        while (true) {
            if (dict.count(cur)) {
                break;  // 如果当前持球朋友已经接到过球，游戏结束
            }
            else {
                dict.emplace(cur);  // 标记当前持球朋友接到了球
                cur = (cur + step * k) % n;  // 计算下一个持球朋友的编号
                step++;  // 增加步数
            }
        }

        for (int i = 0; i < n; i++) {
            if (!dict.count(i)) {
                res.emplace_back(i + 1);  // 将未接到球的朋友编号加入结果数组
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    int n = 5;  // 参与游戏的朋友数量
    int k = 2;  // 每次传球的步数
    vector<int> losers = solution.circularGameLosers(n, k);  // 获取输家列表

    cout << "输家: ";
    for (int loser : losers) {
        cout << loser << " ";
    }

    return 0;
}
