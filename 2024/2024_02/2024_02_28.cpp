#include <iostream>

// 类模板示例
template <typename T>
class Pair {
private:
    T first, second;
public:
    Pair(T f, T s) : first(f), second(s) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }
};

// 函数模板示例
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // 类模板示例
    Pair<int> intPair(10, 20);
    std::cout << "First: " << intPair.getFirst() << ", Second: " << intPair.getSecond() << std::endl;

    Pair<double> doublePair(3.14, 2.71);
    std::cout << "First: " << doublePair.getFirst() << ", Second: " << doublePair.getSecond() << std::endl;

    // 函数模板示例
    int sumInt = add(5, 10);
    std::cout << "Sum of integers: " << sumInt << std::endl;

    double sumDouble = add(3.14, 2.71);
    std::cout << "Sum of doubles: " << sumDouble << std::endl;

    return 0;
}
