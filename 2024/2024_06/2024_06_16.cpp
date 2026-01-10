#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) {
            return -1;
        }
        else {
            return (int)max(a.length(), b.length());
        }
    }
};

int main() {
    Solution solution;
    string a, b;

    // 从标准输入读取字符串a和b
    //cout << "Enter the first string: ";
    //cin >> a;
    //cout << "Enter the second string: ";
    //cin >> b;

    a = { "aaa" };
    b = { "bbb" };

    // 计算并输出最长特殊序列的长度
    int result = solution.findLUSlength(a, b);
    cout << "The length of the longest uncommon subsequence is: " << result << endl;

    return 0;
}
