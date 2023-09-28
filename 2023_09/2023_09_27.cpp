#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // 筛选满足条件的餐馆
        vector<vector<int>> filteredRestaurants;
        for (const vector<int>& restaurant : restaurants) {
            int id = restaurant[0];
            int rating = restaurant[1];
            int vegan = restaurant[2];
            int price = restaurant[3];
            int distance = restaurant[4];

            // 检查是否满足过滤条件
            if ((veganFriendly == 0 || vegan == veganFriendly) && price <= maxPrice && distance <= maxDistance) {
                filteredRestaurants.push_back({ id, rating });
            }
        }

        // 使用自定义比较函数排序
        sort(filteredRestaurants.begin(), filteredRestaurants.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0]; // 如果评分相同，按照id从高到低排序
            }
            return a[1] > b[1]; // 否则按照评分从高到低排序
            });

        // 提取餐馆的id
        vector<int> result;
        for (const vector<int>& restaurant : filteredRestaurants) {
            result.push_back(restaurant[0]);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // 示例输入
    vector<vector<int>> restaurants = {
        {1, 4, 1, 40, 10},
        {2, 8, 0, 50, 5},
        {3, 8, 1, 30, 4},
        {4, 10, 0, 10, 3},
        {5, 1, 1, 15, 1}
    };

    int veganFriendly = 1;
    int maxPrice = 50;
    int maxDistance = 10;

    vector<int> result = solution.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);

    // 输出结果
    for (int id : result) {
        cout << id << " ";
    }

    return 0;
}
