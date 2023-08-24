//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    bool canChange(string start, string target) {
//        int n = start.length();
//        int i = 0, j = 0;
//        while (i < n && j < n) {
//            while (i < n && start[i] == '_') {
//                i++;
//            }
//            while (j < n && target[j] == '_') {
//                j++;
//            }
//            if (i < n && j < n) {
//                if (start[i] != target[j]) {
//                    return false;
//                }
//                char c = start[i];
//                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
//                    return false;
//                }
//                i++;
//                j++;
//            }
//        }
//        while (i < n) {
//            if (start[i] != '_') {
//                return false;
//            }
//            i++;
//        }
//        while (j < n) {
//            if (target[j] != '_') {
//                return false;
//            }
//            j++;
//        }
//        return true;
//    }
//};
//
//int main() {
//    Solution solution;
//    string start = "_L__R__R_";
//    string target = "L______RR";
//
//    if (solution.canChange(start, target)) {
//        cout << "Yes, the transformation is possible." << endl;
//    }
//    else {
//        cout << "No, the transformation is not possible." << endl;
//    }
//
//    return 0;
//}

#include <iostream>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n && j < n) {
            // 跳过 start 中的空位
            while (i < n && start[i] == '_') {
                i++;
            }
            // 跳过 target 中的空位
            while (j < n && target[j] == '_') {
                j++;
            }
            if (i < n && j < n) {
                if (start[i] != target[j]) {
                    return false;
                }
                char c = start[i];
                // 判断是否满足移动规则
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        // 检查剩余的空位是否符合规则
        while (i < n) {
            if (start[i] != '_') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (target[j] != '_') {
                return false;
            }
            j++;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string start = "_L__R__R_";
    string target = "L______RR";

    if (solution.canChange(start, target)) {
        cout << "是的，可以进行转化。" << endl;
    }
    else {
        cout << "不可以进行转化。" << endl;
    }

    return 0;
}
