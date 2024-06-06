#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0; // 记录总步数
        int sum = 0; // 记录已经遇到的黑色球数量

        // 遍历字符串
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                sum++; // 记录当前遇到的黑色球数量
            }
            else {
                ans += sum; // 遇到白色球时，将所有在它前面的黑色球数量加到总步数中
            }
        }
        return ans; // 返回将所有黑色球移到右侧所需的最小步数
    }
};

// 主函数用于测试
int main() {
    Solution solution;

    // 测试用例 1
    string s1 = "101";
    cout << "输入: " << s1 << endl;
    cout << "输出: " << solution.minimumSteps(s1) << endl; // 输出应为 1

    // 测试用例 2
    string s2 = "100";
    cout << "输入: " << s2 << endl;
    cout << "输出: " << solution.minimumSteps(s2) << endl; // 输出应为 2

    // 其他测试用例
    string s3 = "1100";
    cout << "输入: " << s3 << endl;
    cout << "输出: " << solution.minimumSteps(s3) << endl; // 输出应为 4

    string s4 = "111000";
    cout << "输入: " << s4 << endl;
    cout << "输出: " << solution.minimumSteps(s4) << endl; // 输出应为 9

    return 0;
}
