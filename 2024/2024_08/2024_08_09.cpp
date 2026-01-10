#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    // 计算排列差
    int findPermutationDifference(string s, string t) {
        int n = (int)s.size();  // 假设 s 和 t 长度相同
        int diff = 0;

        // 创建一个字符到索引的映射，用于快速查找字符位置
        unordered_map<char, int> positionMap;

        // 记录每个字符在 s 中的位置
        for (int i = 0; i < n; ++i) {
            positionMap[s[i]] = i;
        }

        // 计算排列差
        for (int i = 0; i < n; ++i) {
            diff += abs(i - positionMap[t[i]]);
        }

        return diff;
    }
};

int main() {
    Solution solution;

    // 示例输入
    string s = "abc";
    string t = "bac";

    // 计算排列差
    int result = solution.findPermutationDifference(s, t);

    // 输出结果
    cout << "排列差: " << result << endl;

    return 0;
}
