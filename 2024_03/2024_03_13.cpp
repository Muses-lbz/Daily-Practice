#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        return string(cnt - 1, '1') + string(s.length() - cnt, '0') + '1';
    }
};

int main() {
    Solution sol;
    string s = "0110"; // 输入二进制字符串
    string result = sol.maximumOddBinaryNumber(s); // 调用函数得到结果
    // 输出结果
    cout << "输入字符串: " << s << endl;
    cout << "可以生成的最大奇数: " << result << endl;

    return 0;
}
