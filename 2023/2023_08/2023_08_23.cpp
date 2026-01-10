//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries);
//};
//
//vector<int> Solution::countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
//    vector<int> degree(n);
//    unordered_map<int, int> cnt;
//    for (auto edge : edges) {
//        int x = edge[0] - 1, y = edge[1] - 1;
//        if (x > y) {
//            swap(x, y);
//        }
//        degree[x]++;
//        degree[y]++;
//        cnt[x * n + y]++;
//    }
//
//    vector<int> arr = degree;
//    vector<int> ans;
//    sort(arr.begin(), arr.end());
//    for (int bound : queries) {
//        int total = 0;
//        for (int i = 0; i < n; i++) {
//            int j = upper_bound(arr.begin() + i + 1, arr.end(), bound - arr[i]) - arr.begin();
//            total += n - j;
//        }
//        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
//            int val = it->first;
//            int freq = it->second;
//            int x = val / n;
//            int y = val % n;
//            if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
//                total--;
//            }
//        }
//        ans.emplace_back(total);
//    }
//
//    return ans;
//}
//
//int main() {
//    int n = 4;
//    vector<vector<int>> edges = { {1,2},{2,4},{1,3},{2,3},{2,1} };
//    vector<int> queries = { 2, 3 };
//
//    Solution solution;
//    vector<int> result = solution.countPairs(n, edges, queries);
//
//    cout << "Results: ";
//    for (int num : result) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries);
};

vector<int> Solution::countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
    vector<int> degree(n);  // 存储每个节点的度数
    unordered_map<int, int> cnt;  // 存储点对出现的次数

    // 遍历每条边，统计节点的度数和点对的出现次数
    for (auto edge : edges) {
        int x = edge[0] - 1, y = edge[1] - 1;
        if (x > y) {
            swap(x, y);  // 保持 x <= y，避免重复统计
        }
        degree[x]++;
        degree[y]++;
        cnt[x * n + y]++;  // 使用一个唯一标识表示点对，避免重复
    }

    vector<int> arr = degree;  // 存储度数的副本，用于排序和查找
    vector<int> ans;  // 存储每个查询的答案
    sort(arr.begin(), arr.end());  // 对度数进行排序，方便双指针查找

    for (int bound : queries) {
        int total = 0;  // 存储满足条件的点对数量
        for (int i = 0; i < n; i++) {
            // 使用双指针查找满足条件的度数组合
            int j = upper_bound(arr.begin() + i + 1, arr.end(), bound - arr[i]) - arr.begin();
            total += n - j;  // 统计满足条件的点对数量
        }
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            int val = it->first;  // 获取点对的唯一标识
            int freq = it->second;  // 获取点对出现的次数
            int x = val / n;  // 获取点对中的节点 x
            int y = val % n;  // 获取点对中的节点 y
            if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                total--;  // 通过比较度数和点对出现次数判断是否减少计数
            }
        }
        ans.emplace_back(total);  // 将每个查询的结果加入答案数组
    }

    return ans;  // 返回所有查询的答案数组
}

int main() {
    int n = 4;
    vector<vector<int>> edges = { {1,2},{2,4},{1,3},{2,3},{2,1} };
    vector<int> queries = { 2, 3 };

    Solution solution;
    vector<int> result = solution.countPairs(n, edges, queries);

    cout << "Results: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
