#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序算法
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    vector<int> nums = { 5, 2, 9, 1, 5, 6 };
    bubbleSort(nums);
    for (int n : nums) cout << n << " ";
    return 0;
}
