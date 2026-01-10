#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> stk;
        int i = 0, n = (int)preorder.size();

        while (i < n) {
            if (preorder[i] == ',') {
                i++;
                continue;
            }
            else if (preorder[i] == '#') {
                if (!stk.empty() && stk.top() == '#') {
                    while (!stk.empty() && stk.top() == '#') {
                        stk.pop(); // 弹出栈顶的 '#'
                        if (stk.empty()) return false; // 无效
                        stk.pop(); // 弹出节点值
                    }
                    stk.push('#'); // 入栈表示一个子树结束
                }
                else {
                    stk.push('#'); // 入栈表示一个叶子节点
                }
            }
            else { // 数值节点
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                stk.push('x'); // 入栈表示一个数值节点
            }
            i++;
        }

        return stk.size() == 1 && stk.top() == '#'; // 如果栈中只剩下一个 '#'，则序列有效
    }
};

int main() {
    Solution sol;
    string preorder1 = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    string preorder2 = "1,#";
    string preorder3 = "9,#,#,1";

    cout << "示例1结果：" << (sol.isValidSerialization(preorder1) ? "true" : "false") << endl;
    cout << "示例2结果：" << (sol.isValidSerialization(preorder2) ? "true" : "false") << endl;
    cout << "示例3结果：" << (sol.isValidSerialization(preorder3) ? "true" : "false") << endl;

    return 0;
}
