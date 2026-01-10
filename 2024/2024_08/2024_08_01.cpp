#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class MagicDictionary {
private:
    unordered_set<string> word_set;  // 用于存储字典中的单词

public:
    MagicDictionary() {}

    /**
     * 构建字典的方法
     * @param dictionary: 包含单词的字符串数组
     */
    void buildDict(vector<string> dictionary) {
        word_set.clear();  // 清空已有的字典
        for (const auto& word : dictionary) {
            word_set.insert(word);  // 将每个单词插入到集合中
        }
    }

    /**
     * 搜索单词的方法
     * @param searchWord: 要检查的单词
     * @return 如果能通过修改一个字母将searchWord变为字典中的某个单词，则返回 true，否则返回 false
     */
    bool search(string searchWord) {
        // 遍历 searchWord 中的每个字符
        for (int i = 0; i < searchWord.size(); ++i) {
            char original_char = searchWord[i];  // 保存原始字符

            // 尝试将该字符替换为其他 25 个字母中的一个
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == original_char) continue;  // 跳过相同字符

                searchWord[i] = c;  // 替换字符

                // 检查替换后的单词是否在字典中
                if (word_set.count(searchWord)) {
                    return true;  // 找到符合条件的单词，返回 true
                }
            }

            searchWord[i] = original_char;  // 恢复原始字符
        }

        // 如果所有替换都没有找到匹配的单词，返回 false
        return false;
    }
};

int main() {
    // 创建 MagicDictionary 对象
    MagicDictionary magicDictionary;

    // 构建字典
    magicDictionary.buildDict({ "hello", "leetcode" });

    // 测试搜索功能
    cout << (magicDictionary.search("hello") ? "true" : "false") << endl; // 应该返回 false
    cout << (magicDictionary.search("hhllo") ? "true" : "false") << endl; // 应该返回 true
    cout << (magicDictionary.search("hell") ? "true" : "false") << endl;  // 应该返回 false
    cout << (magicDictionary.search("leetcoded") ? "true" : "false") << endl; // 应该返回 false

    return 0;
}
