#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 用于 sort()
using namespace std;

/**
 * 题目要求：
 * 不断删除相邻且互为字母异位词（anagram）的单词。
 * 最后返回删除后的结果数组。
 *
 * 示例：
 * 输入: ["abba","baba","bbaa","cd","cd"]
 * 输出: ["abba","cd"]
 */

class Solution {
public:
    /**
     * @brief 判断两个字符串是否是字母异位词
     * 
     * 字母异位词定义：排序后结果相同的两个字符串。
     * 例如："ab" 和 "ba" 排序后都是 "ab"，所以是异位词。
     */
    bool isAnagram(const string &a, const string &b) {
        // 若长度不同，必不是异位词
        if (a.size() != b.size()) return false;

        // 拷贝一份字符串，进行排序
        string s1 = a, s2 = b;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        // 若排序后相等，则是异位词
        return s1 == s2;
    }

    /**
     * @brief 移除相邻异位词的核心函数
     * 
     * 算法思路：
     * 使用一个结果数组 res，当遍历到下一个单词时：
     *   - 如果 res 为空，直接加入。
     *   - 如果当前单词与 res 的最后一个单词是异位词，则跳过（删除当前单词）。
     *   - 否则加入 res。
     * 
     * 这样最终 res 中不会有相邻的异位词。
     */
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res; // 用于存储最终结果

        for (auto &w : words) {
            // 如果当前单词不是上一个单词的异位词，则加入结果
            if (res.empty() || !isAnagram(res.back(), w)) {
                res.push_back(w);
            }
            // 否则（是异位词），跳过当前单词，相当于“删除”
        }
        return res;
    }
};

int main() {
    Solution sol;

    // 示例 1
    vector<string> words1 = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> result1 = sol.removeAnagrams(words1);

    cout << "示例 1 结果：" << endl;
    cout << "输入：[\"abba\", \"baba\", \"bbaa\", \"cd\", \"cd\"]" << endl;
    cout << "输出：[";
    for (int i = 0; i < (int)result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i != result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // 示例 2
    vector<string> words2 = {"a", "b", "c", "d", "e"};
    vector<string> result2 = sol.removeAnagrams(words2);

    cout << "示例 2 结果：" << endl;
    cout << "输入：[\"a\", \"b\", \"c\", \"d\", \"e\"]" << endl;
    cout << "输出：[";
    for (int i = 0; i < (int)result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i != result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
