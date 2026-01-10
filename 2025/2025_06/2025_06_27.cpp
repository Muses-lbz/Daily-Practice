#include <iostream>
#include <string>
using namespace std;

// 判断字符串是否是回文
bool isPalindrome(const string& str) {
    int left = 0, right = str.length() - 1;
    while (left < right)
        if (str[left++] != str[right--]) return false;
    return true;
}

int main() {
    string s = "madam";
    cout << s << (isPalindrome(s) ? " 是回文" : " 不是回文") << endl;
    return 0;
}
