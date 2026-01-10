#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

class Solution {
public:
    int halveArray(std::vector<int>& nums) {
        long long sum = 0;
        std::priority_queue<double, std::vector<double>, std::less<double>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
            sum += nums[i];
        }
        int cnt = 0;
        double temp = 0;
        while (temp * 2 < sum) {
            double x = heap.top();
            heap.pop();
            temp += x / 2;
            cnt++;
            heap.push(x / 2);
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = { 5, 19, 8, 1 };
    std::cout << "Result 1: " << solution.halveArray(nums1) << std::endl; // Output: 3

    std::vector<int> nums2 = { 3, 8, 20 };
    std::cout << "Result 2: " << solution.halveArray(nums2) << std::endl; // Output: 3

    return 0;
}
