#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 判断两个矩阵是否相等
    bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = (int)(a.size());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != b[i][j]) 
                    return false;
            }
        }
        return true;
    }

    // 顺时针旋转 90 度
    void rotate90(vector<vector<int>>& mat) {
        int n = (int)(mat.size());

        // 转置
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // 每行反转
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (isEqual(mat, target)) return true;
            rotate90(mat);
        }
        return false;
    }
};

int main() {
    Solution sol;

    // 示例1
    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> target = {
        {1, 0},
        {0, 1}
    };

    bool result = sol.findRotation(mat, target);

    if (result) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}