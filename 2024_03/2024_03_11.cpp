#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        int n = (int)title.size();
        int l = 0, r = 0;   // 单词左右边界（左闭右开）
        while (r < n) {
            while (r < n && title[r] != ' ') {
                ++r;
            }
            // 对于每个单词按要求处理
            if (r - l > 2) {
                title[l] = toupper(title[l]); // 将首字母大写
            }
            ++l; // 移动到单词中的下一个字母
            while (l < r) {
                title[l] = tolower(title[l]); // 将其他字母变为小写
                ++l; // 移动到单词中的下一个字母
            }
            l = ++r; // 移动到下一个单词的左边界
        }
        return title;
    }
};

int main() {
    Solution sol;
    string title = "First leTTeR of EACH Word";
    cout << "Original title: " << title << endl;
    string capitalizedTitle = sol.capitalizeTitle(title);
    cout << "Capitalized title: " << capitalizedTitle << endl;

    return 0;
}
