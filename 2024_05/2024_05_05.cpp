#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0); // 创建一个与输入数组相同大小的结果数组，并初始化为零

        if (k == 0) { // 如果 k 等于 0，则直接返回结果数组
            return result;
        }

        for (int i = 0; i < n; ++i) { // 遍历循环数组
            int sum = 0; // 初始化当前索引位置的替换值为零
            if (k > 0) { // 如果 k 大于 0，则向后取和
                for (int j = 1; j <= k; ++j) { // 遍历取和的数字个数
                    sum += code[(i + j) % n]; // 计算当前索引位置的替换值
                }
            }
            else { // 如果 k 小于 0，则向前取和
                for (int j = -1; j >= k; --j) { // 遍历取和的数字个数
                    sum += code[(i + j + n) % n]; // 计算当前索引位置的替换值
                }
            }
            result[i] = sum; // 将计算得到的替换值存储在结果数组中
        }

        return result; // 返回结果数组
    }
};

int main() {
    Solution solution;
    vector<int> code = { 5, 7, 1, 4 };
    int k = 3;
    vector<int> decrypted_code = solution.decrypt(code, k);
    cout << "Decrypted code:";
    for (int num : decrypted_code) {
        cout << " " << num;
    }
    cout << endl;
    return 0;
}
