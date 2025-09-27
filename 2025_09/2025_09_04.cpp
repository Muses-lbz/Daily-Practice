#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // 把版本号拆分为数字数组
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);

        int n = (int)max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int num1 = i < v1.size() ? v1[i] : 0; // 不足时补 0
            int num2 = i < v2.size() ? v2[i] : 0;
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }

private:
    // 工具函数：把字符串按 '.' 切割并转为整数
    vector<int> split(const string& s) {
        vector<int> res;
        int n = (int)s.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '.') {
                res.push_back(num);
                num = 0;
            }
            else {
                num = num * 10 + (s[i] - '0'); // 转数字，自动忽略前导零
            }
        }
        res.push_back(num); // 最后一个数字
        return res;
    }
};

// 测试
int main() {
    Solution sol;
    cout << sol.compareVersion("1.2", "1.10") << endl;     // -1
    cout << sol.compareVersion("1.01", "1.001") << endl;   // 0
    cout << sol.compareVersion("1.0", "1.0.0.0") << endl;  // 0
    cout << sol.compareVersion("1.0.5", "1.0.3") << endl;  // 1
    return 0;
}
