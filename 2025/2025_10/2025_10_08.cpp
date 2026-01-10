#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 优化思路：
 * -----------------------------
 * 判断两个字符串是否为字母异位词时，
 * 不再使用 sort() 排序（O(k log k)），
 * 而是统计 26 个字母的出现次数（O(k)）。
 * 若计数数组相同，则说明是异位词。
 */

class Solution {
public:
    /**
     * @brief 判断两个字符串是否是字母异位词（使用字母频次数组）
     *
     * 思路：
     * 1. 定义长度为 26 的计数数组 cnt。
     * 2. 遍历第一个字符串，对应字母计数 +1；
     *    遍历第二个字符串，对应字母计数 -1。
     * 3. 若最后计数全为 0，则为异位词。
     */
    bool isAnagram(const string& a, const string& b) {
        if (a.size() != b.size()) return false; // 长度不同，直接返回 false
        int cnt[26] = { 0 }; // 统计 a 和 b 中每个字母的出现次数

        for (char c : a) cnt[c - 'a']++;
        for (char c : b) cnt[c - 'a']--;

        // 若所有计数都为 0，则为异位词
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) return false;
        }
        return true;
    }

    /**
     * @brief 移除相邻异位词的核心函数
     *
     * 逻辑：
     * 遍历单词列表 words，用一个结果数组 res 来保存“干净”的结果。
     * 若当前单词与 res 最后一个单词是异位词，则跳过；
     * 否则将当前单词加入结果中。
     */
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        for (auto& w : words) {
            if (res.empty() || !isAnagram(res.back(), w)) {
                res.push_back(w); // 当前单词与上一个不是异位词 -> 加入结果
            }
            // 否则跳过当前单词（即删除）
        }
        return res;
    }
};

int main() {
    Solution sol;

    // 示例 1
    vector<string> words1 = { "abba", "baba", "bbaa", "cd", "cd" };
    vector<string> result1 = sol.removeAnagrams(words1);

    cout << "示例 1：" << endl;
    cout << "输入: [\"abba\", \"baba\", \"bbaa\", \"cd\", \"cd\"]" << endl;
    cout << "输出: [";
    for (int i = 0; i < (int)result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i != result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // 示例 2
    vector<string> words2 = { "a", "b", "c", "d", "e" };
    vector<string> result2 = sol.removeAnagrams(words2);

    cout << "示例 2：" << endl;
    cout << "输入: [\"a\", \"b\", \"c\", \"d\", \"e\"]" << endl;
    cout << "输出: [";
    for (int i = 0; i < (int)result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i != result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
