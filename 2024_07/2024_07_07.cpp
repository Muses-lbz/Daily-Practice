#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = (int)s.length();

        // 计算两个字符之间的最小距离
        auto min_distance = [](char a, char b) {
            return min(abs(a - b), 26 - abs(a - b));
            };

        for (int i = 0; i < n && k > 0; ++i) {
            // 计算当前字符与 'a' 之间的最小距离
            int dist = min_distance(s[i], 'a');
            if (dist <= k) {
                // 如果距离小于等于 k，则将字符转换为 'a'，并减少 k
                k -= dist;
                s[i] = 'a';
            }
            else {
                // 如果不能完全转换为 'a'，则在剩余的 k 内，调整当前字符，使其字典序最小
                if (s[i] >= 'a' + k) {
                    s[i] = s[i] - k;
                }
                else {
                    s[i] = s[i] + k;
                }
                k = 0;  // k 已经用完
            }
        }

        return s;
    }
};

int main() {
    Solution solution;
    cout << solution.getSmallestString("zbbz", 3) << endl; // 输出: "aaaz"
    cout << solution.getSmallestString("xaxcd", 4) << endl; // 输出: "aawcd"
    cout << solution.getSmallestString("lol", 0) << endl; // 输出: "lol"
    return 0;
}
