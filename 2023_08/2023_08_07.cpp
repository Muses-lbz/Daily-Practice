#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;           // 指向字符串开头的指针
        int right = s.size() - 1; // 指向字符串末尾的指针

        while (left < right) {
            // 交换两个指针指向的字符
            swap(s[left], s[right]);
            // 移动指针
            left++;
            right--;
        }
    }
};

int main() {
    Solution solution;
    vector<char> s = { 'h', 'e', 'l', 'l', 'o' };

    solution.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
