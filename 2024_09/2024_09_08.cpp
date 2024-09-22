#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 查找小镇法官的函数
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);  // 用于存储每个人的信任度

        // 遍历 trust 数组，更新信任关系
        for (const auto& t : trust) {
            int a = t[0], b = t[1];
            trustCount[a]--;  // a 信任别人，信任度减一
            trustCount[b]++;  // b 被别人信任，信任度加一
        }

        // 寻找被所有人信任且不信任任何人的人
        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1) {  // 只有法官的信任度会等于 n-1
                return i;
            }
        }

        return -1;  // 如果没有找到符合条件的法官，返回 -1
    }
};

// 主函数，进行测试
int main() {
    Solution solution;

    // 示例 1
    int n1 = 2;
    vector<vector<int>> trust1 = { {1, 2} };
    cout << "法官是: " << solution.findJudge(n1, trust1) << endl;  // 输出应为 2

    // 示例 2
    int n2 = 3;
    vector<vector<int>> trust2 = { {1, 3}, {2, 3} };
    cout << "法官是: " << solution.findJudge(n2, trust2) << endl;  // 输出应为 3

    // 示例 3
    int n3 = 3;
    vector<vector<int>> trust3 = { {1, 3}, {2, 3}, {3, 1} };
    cout << "法官是: " << solution.findJudge(n3, trust3) << endl;  // 输出应为 -1

    return 0;
}
