#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        // 定义元音集合
        string vowels = "aeiouAEIOU";
        auto isVowel = [&](char c) {
            return vowels.find(c) != string::npos;
            };

        // 计数数组：ASCII 范围 128 足够
        vector<int> freq(128, 0);

        // 统计元音出现次数
        for (char c : s) {
            if (isVowel(c)) {
                freq[(int)c]++;
            }
        }

        // 替换字符串中的元音
        string t = s;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                // 找到下一个按 ASCII 顺序的元音
                for (int ascii = 0; ascii < 128; ascii++) {
                    if (freq[ascii] > 0) {
                        t[i] = (char)ascii;
                        freq[ascii]--;
                        break;
                    }
                }
            }
        }
        return t;
    }
};

// 测试
int main() {
    Solution sol;
    cout << sol.sortVowels("lEetcOde") << endl;   // 输出: lEOtcede
    cout << sol.sortVowels("lYmpH") << endl;      // 输出: lYmpH
    cout << sol.sortVowels("AaEeIiOoUu") << endl; // 输出: AaEeIiOoUu
    cout << sol.sortVowels("UoIeAa") << endl;     // 输出: AIeOuu
    return 0;
}
