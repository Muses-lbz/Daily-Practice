#include <iostream>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = (int)binary.size();
        int j = 0;
        // 遍历输入字符串中的每个字符
        for (int i = 0; i < n; i++) {
            // 当遇到一个 '0' 字符时，开始移动连续的 0 到字符串的末尾，保持字符串中 1 的数量不变
            if (binary[i] == '0') {
                // 使用指针 j 跟踪当前位置，确保在移动连续的 0 时不会改变已经置为 1 的位置
                while (j <= i || (j < n && binary[j] == '1')) {
                    j++;
                }
                // 移动完成后，将当前位置 i 和下一个位置 i + 1 的字符置为 '1' 和 '0'，以满足题目要求
                if (j < n) {
                    binary[j] = '1';
                    binary[i] = '1';
                    binary[i + 1] = '0';
                }
            }
        }
        return binary;
    }
};

int main() {
    Solution sol;
    string binary = "000110";
    // 输出结果
    cout << sol.maximumBinaryString(binary) << endl;
    return 0;
}
