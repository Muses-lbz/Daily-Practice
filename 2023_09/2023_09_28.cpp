#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        // 遍历花期，记录每个花期的开始和结束，以及花数目的增加和减少
        for (auto& flower : flowers) {
            cnt[flower[0]]++;
            cnt[flower[1] + 1]--;
        }
        int m = persons.size();
        vector<int> indices(m);
        iota(indices.begin(), indices.end(), 0);
        // 按照人的到达时间排序，并创建一个索引数组
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return persons[a] < persons[b];
            });

        vector<int> ans(m);
        int curr = 0;
        auto it = cnt.begin();
        for (int x : indices) {
            // 更新当前在花期内的花的数量
            while (it != cnt.end() && it->first <= persons[x]) {
                curr += it->second;
                it++;
            }
            ans[x] = curr;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> flowers = { {1, 6}, {3, 7}, {9, 12}, {4, 13} };
    vector<int> people = { 2, 3, 7, 11 };
    vector<int> result = solution.fullBloomFlowers(flowers, people);

    cout << "每个人在花期内花的数目：" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
