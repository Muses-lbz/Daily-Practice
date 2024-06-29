//#include <iostream>
//#include <string>
//
//class Solution {
//public:
//    // 返回执行一次操作后可以获得的字典序最小的字符串
//    std::string smallestString(std::string s) {
//        int n = (int)s.size();
//        int start = -1;
//
//        // 找到第一个不为 'a' 的字符
//        for (int i = 0; i < n; ++i) {
//            if (s[i] != 'a') {
//                start = i;
//                break;
//            }
//        }
//
//        // 如果字符串全是 'a'
//        if (start == -1) {
//            s[n - 1] = 'z'; // 将最后一个 'a' 替换为 'z'
//            return s;
//        }
//
//        // 从第一个不为 'a' 的字符开始，找到连续的非 'a' 子字符串
//        for (int i = start; i < n; ++i) {
//            if (s[i] == 'a') break; // 遇到 'a' 则停止
//            s[i] = s[i] - 1; // 替换为前一个字符
//        }
//
//        return s;
//    }
//};
//
//int main() {
//    Solution solution;
//
//    std::string s1 = "cbabc";
//    std::string s2 = "acbbc";
//
//    std::cout << "输入: " << s1 << " 输出: " << solution.smallestString(s1) << std::endl;
//    std::cout << "输入: " << s2 << " 输出: " << solution.smallestString(s2) << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        // 从字符串末尾开始，逐个检查是否为 '0'
        while (!num.empty() && num.back() == '0') {
            num.pop_back(); // 如果是 '0'，就删除最后一个字符
        }
        return num; // 返回去掉尾随零后的字符串
    }
};

int main() {
    Solution solution;

    string num1 = "51230100";
    string result1 = solution.removeTrailingZeros(num1);
    cout << "输入: " << num1 << " 输出: " << result1 << endl; // 输出: 512301

    string num2 = "123";
    string result2 = solution.removeTrailingZeros(num2);
    cout << "输入: " << num2 << " 输出: " << result2 << endl; // 输出: 123

    string num3 = "0000";
    string result3 = solution.removeTrailingZeros(num3);
    cout << "输入: " << num3 << " 输出: " << result3 << endl; // 输出: (空字符串)

    return 0;
}
