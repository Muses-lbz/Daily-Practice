//#include <iostream>
//#include <cmath>
//#include <random>
//
//// 目标函数
//double f(double x) {
//    return x * x;
//}
//
//// 模拟退火算法
//double simulatedAnnealing() {
//    // 初始温度
//    double temperature = 1000.0;
//    // 终止温度
//    double minTemperature = 0.01;
//    // 温度衰减率
//    double coolingRate = 0.95;
//    // 当前解
//    double currentSolution = 10.0;
//
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_real_distribution<double> distribution(-1.0, 1.0);
//
//    while (temperature > minTemperature) {
//        // 生成邻域解
//        double nextSolution = currentSolution + distribution(gen);
//        // 计算目标函数变化
//        double deltaE = f(nextSolution) - f(currentSolution);
//        // 接受更差解或根据概率接受
//        if (deltaE < 0 || std::exp(-deltaE / temperature) > distribution(gen)) {
//            currentSolution = nextSolution;
//        }
//        // 降低温度
//        temperature *= coolingRate;
//    }
//
//    return currentSolution;
//}
//
//int main() {
//    double solution = simulatedAnnealing();
//    std::cout << "Optimal solution: " << solution << std::endl;
//    std::cout << "Minimum value: " << f(solution) << std::endl;
//    return 0;
//}

#include <iostream>

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0, sign = 1;
        while (n != 0)
        {
            sum += sign * (n % 10);
            sign = -sign;
            n /= 10;
        }
        return -sign * sum;
    }
};

int main() {
    Solution solution;

    int n = 12345;
    int result = solution.alternateDigitSum(n);
    std::cout << "Alternate Digit Sum: " << result << std::endl;

    n = 1000;
    result = solution.alternateDigitSum(n);
    std::cout << "Alternate Digit Sum: " << result << std::endl;

    system("pause");
    return 0;
}