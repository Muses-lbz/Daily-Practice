#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int count1 = 0; // 变成 "0101..."
        int count2 = 0; // 变成 "1010..."

        for (int i = 0; i < s.size(); i++) {

            // 情况1：目标 0101...
            if (i % 2 == 0) {
                if (s[i] != '0') count1++;
            }
            else {
                if (s[i] != '1') count1++;
            }

            // 情况2：目标 1010...
            if (i % 2 == 0) {
                if (s[i] != '1') count2++;
            }
            else {
                if (s[i] != '0') count2++;
            }
        }

        return min(count1, count2);
    }
};

int main() {
    Solution sol;

    cout << sol.minOperations("0100") << endl; // 1
    cout << sol.minOperations("10") << endl;   // 0
    cout << sol.minOperations("1111") << endl; // 2

    return 0;
}