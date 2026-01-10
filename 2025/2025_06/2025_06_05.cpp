#include <iostream>
#include <vector>
using namespace std;

// 反转数组
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left++], arr[right--]);
    }
}

int main() {
    vector<int> nums = { 1, 2, 3, 4, 5 };
    reverseArray(nums);
    for (int n : nums) cout << n << " ";
    return 0;
}
