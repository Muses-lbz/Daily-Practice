//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    bool lemonadeChange(vector<int>& bills) {
//        int fiveCount = 0;
//        int tenCount = 0;
//
//        for (int bill : bills) {
//            if (bill == 5) {
//                fiveCount++;
//            }
//            else if (bill == 10) {
//                if (fiveCount >= 1) {
//                    fiveCount--;
//                    tenCount++;
//                }
//                else {
//                    return false;
//                }
//            }
//            else if (bill == 20) {
//                if (tenCount >= 1 && fiveCount >= 1) {
//                    tenCount--;
//                    fiveCount--;
//                }
//                else if (fiveCount >= 3) {
//                    fiveCount -= 3;
//                }
//                else {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> bills = { 5, 5, 5, 10, 20 };
//
//    if (solution.lemonadeChange(bills)) {
//        cout << "You can give correct change to every customer." << endl;
//    }
//    else {
//        cout << "Sorry, you cannot give correct change to every customer." << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//int main() {
//    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
//
//    // 使用范围-based for循环遍历向量中的元素
//    for (int num : numbers) {
//        std::cout << num << " ";
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <list>
//
//int main() {
//    std::vector<int> vec = { 1, 2, 3, 4, 5 };
//    std::list<int> lst = { 10, 20, 30, 40, 50 };
//
//    // 向容器中插入元素
//    vec.push_back(6);
//    lst.push_front(0);
//
//    // 从容器中删除元素
//    vec.pop_back();
//    lst.pop_back();
//
//    // 遍历容器并输出元素
//    std::cout << "Vector elements: ";
//    for (int num : vec) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    std::cout << "List elements: ";
//    for (int num : lst) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <set>
#include <map>

int main() {
    std::set<std::string> names;
    names.insert("Alice");
    names.insert("Bob");
    names.insert("Charlie");
    names.insert("Alice"); // 重复元素将被忽略

    std::map<int, std::string> ages;
    ages[25] = "Alice";
    ages[30] = "Bob";
    ages[22] = "Charlie";
    ages[25] = "David"; // 重复键将覆盖原有的值

    // 查找元素
    if (names.find("Alice") != names.end()) {
        std::cout << "Alice is in the set." << std::endl;
    }
    else {
        std::cout << "Alice is not in the set." << std::endl;
    }

    // 遍历容器并输出元素
    std::cout << "Names: ";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    std::cout << "Ages: ";
    for (const auto& entry : ages) {
        std::cout << "Name: " << entry.second << ", Age: " << entry.first << " ";
    }
    std::cout << std::endl;

    return 0;
}
