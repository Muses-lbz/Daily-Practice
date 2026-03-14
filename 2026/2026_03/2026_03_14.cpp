#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));

        // 如果k超过总数
        if (k > total) return "";

        string ans = "";
        vector<char> letters = { 'a','b','c' };

        for (int i = 0; i < n; i++) {
            for (char c : letters) {

                // 不能和前一个相同
                if (!ans.empty() && ans.back() == c)
                    continue;

                int remain = n - i - 1;
                int count = 1 << remain;  // 2^remain

                if (k > count) {
                    // 跳过这一段
                    k -= count;
                }
                else {
                    // 选择这个字符
                    ans += c;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    cout << s.getHappyString(1, 3) << endl;  // c
    cout << s.getHappyString(1, 4) << endl;  // ""
}