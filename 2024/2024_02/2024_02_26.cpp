#include <iostream>

int main() {
    // 指针数组示例
    int a = 10, b = 20, c = 30;
    int* ptrArr[3] = {}; // 声明一个包含3个整型指针的指针数组

    ptrArr[0] = &a; // 将指针指向变量 a
    ptrArr[1] = &b; // 将指针指向变量 b
    ptrArr[2] = &c; // 将指针指向变量 c

    // 输出指针数组中的元素值
    std::cout << "指针数组中的元素值：" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "ptrArr[" << i << "] = " << *ptrArr[i] << std::endl;
    }

    // 数组指针示例
    int arr[5] = { 1, 2, 3, 4, 5 };
    int(*ptr)[5]; // 声明一个指向包含5个整数的数组的指针

    ptr = &arr; // 将指针指向数组 arr

    // 输出数组指针指向的数组中的元素值
    std::cout << "\n数组指针指向的数组中的元素值：" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "(*ptr)[" << i << "] = " << (*ptr)[i] << std::endl;
    }

    return 0;
}
