//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class Solution {
//public:
//    double average(std::vector<int>& salary) {
//        // 对工资数组进行排序
//        std::sort(salary.begin(), salary.end());
//
//        // 去掉最低工资和最高工资
//        salary.erase(salary.begin());
//        salary.pop_back();
//
//        // 计算剩余工资的总和
//        double sum = 0;
//        for (int s : salary) {
//            sum += s;
//        }
//
//        // 计算平均工资
//        return sum / salary.size();
//    }
//};
//
//int main() {
//    std::vector<int> salary = { 4000, 3000, 1000, 2000 };
//    Solution sol;
//    double avg = sol.average(salary);
//    std::cout << "Average salary: " << avg << std::endl;
//    return 0;
//}

#include <iostream>

using namespace std;

class Solution
{
public:
    int Printf()
    {
        cout << "Hello World!" << endl;
        return 0;
    }
private:

protected:

};

int main()
{
    Solution S;
    S.Printf();

    return 0;
}