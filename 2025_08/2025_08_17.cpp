#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>   // pair
#include <iomanip>   // 可选，用于格式控制

using namespace std;

class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;

    // 用于保存数字和表达式
    struct Node {
        double value;      // 数值
        string expr;       // 对应的表达式
    };

    // 判断是否能得到24，并返回表达式
    bool judgePoint24(vector<int>& nums, string& result) {
        vector<Node> l;
        for (int num : nums) {
            l.push_back({ (double)num, to_string(num) });
        }
        return solve(l, result);
    }

private:
    // 回溯求解
    bool solve(vector<Node>& l, string& result) {
        if (l.empty()) return false;

        // 只剩一个数，判断是否为24
        if (l.size() == 1) {
            if (fabs(l[0].value - TARGET) < EPSILON) {
                result = l[0].expr;
                return true;
            }
            else {
                return false;
            }
        }

        int size = (int)l.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    vector<Node> list2;
                    for (int k = 0; k < size; k++) {
                        if (k != i && k != j) list2.push_back(l[k]);
                    }

                    // 四种运算
                    vector<pair<double, string>> candidates;
                    candidates.push_back({ l[i].value + l[j].value,
                                          "(" + l[i].expr + "+" + l[j].expr + ")" });
                    candidates.push_back({ l[i].value - l[j].value,
                                          "(" + l[i].expr + "-" + l[j].expr + ")" });
                    candidates.push_back({ l[i].value * l[j].value,
                                          "(" + l[i].expr + "*" + l[j].expr + ")" });
                    if (fabs(l[j].value) > EPSILON) {
                        candidates.push_back({ l[i].value / l[j].value,
                                              "(" + l[i].expr + "/" + l[j].expr + ")" });
                    }

                    for (auto& c : candidates) {
                        list2.push_back({ c.first, c.second });
                        if (solve(list2, result)) return true;
                        list2.pop_back();
                    }
                }
            }
        }
        return false;
    }
};

// 主函数，测试样例
int main() {
    Solution solution;
    string expr;

    vector<int> cards1 = { 4, 1, 8, 7 };
    if (solution.judgePoint24(cards1, expr))
        cout << "[4,1,8,7] => true, 表达式: " << expr << endl;
    else
        cout << "[4,1,8,7] => false" << endl;

    vector<int> cards2 = { 1, 2, 1, 2 };
    if (solution.judgePoint24(cards2, expr))
        cout << "[1,2,1,2] => true, 表达式: " << expr << endl;
    else
        cout << "[1,2,1,2] => false" << endl;

    vector<int> cards3 = { 3, 3, 8, 8 };
    if (solution.judgePoint24(cards3, expr))
        cout << "[3,3,8,8] => true, 表达式: " << expr << endl;
    else
        cout << "[3,3,8,8] => false" << endl;

    return 0;
}
