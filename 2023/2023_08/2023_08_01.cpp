#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int sumOfPower(std::vector<int>& nums) {
        long long s = 0, t = 0, M = 1e9 + 7;
        sort(nums.begin(), nums.end());
        for (auto& x : nums) {
            s = (s + (t + x) % M * x % M * x % M) % M;
            t = (2 * t + x) % M;
        }
        return s;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 2, 3, 1 };
    int result = solution.sumOfPower(nums);
    std::cout << "The sum of power is: " << result << std::endl;
    return 0;
}
