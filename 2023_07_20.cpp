#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kadane(vector<int>& nums) {
        int maxEndingHere = nums[0];
        int maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        // 检查是否所有元素都是负数
        bool allNegative = true;
        int maxElement = nums[0];
        int totalSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            totalSum += nums[i];
            maxElement = max(maxElement, nums[i]);
            if (nums[i] > 0) {
                allNegative = false;
            }
        }

        if (allNegative) {
            return maxElement; // 返回数组中最大的负数
        }

        int nonCircularMaxSum = kadane(nums);

        // Invert the sign of all elements to find the minimum subarray sum.
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = -nums[i];
        }

        int nonCircularMinSum = kadane(nums);

        // Find the maximum circular subarray sum.
        int circularMaxSum = totalSum + nonCircularMinSum;

        return max(circularMaxSum, nonCircularMaxSum);
    }
};

int main() {
    Solution solution;
    vector<int> nums = { -3, -2, 5 };
    int result = solution.maxSubarraySumCircular(nums);
    cout << "The maximum circular subarray sum is: " << result << endl;
    return 0;
}
