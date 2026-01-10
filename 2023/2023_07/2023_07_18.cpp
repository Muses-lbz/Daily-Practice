//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//        int n = queries.size();
//        vector<int> res(n, -1);
//        vector<pair<int, int>> pa(n);
//        for (int i = 0; i < n; ++i)
//            pa[i] = { queries[i], i };
//        sort(pa.begin(), pa.end());
//        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
//            return a[0] < b[0];
//            });
//        int p = 0;
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//        for (int i = 0; i < n; ++i)
//        {
//            while (p < intervals.size() && pa[i].first >= intervals[p][0])
//            {
//                pq.push({ intervals[p][1] - intervals[p][0] + 1, intervals[p][1] });
//                ++p;
//            }
//            while (!pq.empty() && pa[i].first > pq.top().second)
//                pq.pop();
//            if (!pq.empty())
//                res[pa[i].second] = pq.top().first;
//        }
//        return res;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<vector<int>> intervals = { {1, 4}, {2, 5}, {7, 9} };
//    vector<int> queries = { 2, 3, 10 };
//    vector<int> result = solution.minInterval(intervals, queries);
//
//    cout << "Result: ";
//    for (int length : result) {
//        cout << length << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> res(n, -1);
        vector<pair<int, int>> pa(n);

        // 将查询值和索引组成的pair存储在pa中
        for (int i = 0; i < n; ++i)
            pa[i] = { queries[i], i };

        // 按照查询值从小到大排序
        sort(pa.begin(), pa.end());

        // 按照区间起始值从小到大排序
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });

        int p = 0;
        // 使用最小堆来存储区间长度和区间的结束值
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; ++i) {
            // 将与当前查询值起始值相符的区间加入最小堆
            while (p < intervals.size() && pa[i].first >= intervals[p][0]) {
                pq.push({ intervals[p][1] - intervals[p][0] + 1, intervals[p][1] });
                ++p;
            }

            // 从堆中删除已经过期的区间
            while (!pq.empty() && pa[i].first > pq.top().second)
                pq.pop();

            // 如果堆不为空，取堆顶元素作为结果
            if (!pq.empty())
                res[pa[i].second] = pq.top().first;
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = { {1, 4}, {2, 5}, {7, 9} };
    vector<int> queries = { 2, 3, 10 };
    vector<int> result = solution.minInterval(intervals, queries);

    cout << "Result: ";
    for (int length : result) {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}