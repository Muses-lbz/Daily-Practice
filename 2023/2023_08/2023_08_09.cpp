//#include <iostream>
//
//class Solution {
//public:
//    int subtractProductAndSum(int n) {
//        int product = 1;
//        int sum = 0;
//
//        while (n > 0) {
//            int digit = n % 10;
//            product *= digit;
//            sum += digit;
//            n /= 10;
//        }
//
//        int difference = product - sum;
//        return difference;
//    }
//};
//
//int main() {
//    Solution solution;
//    int n = 234;
//    int result = solution.subtractProductAndSum(n);
//    std::cout << "Result: " << result << std::endl;
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int n = 5; // 数组大小
//    int* arr; // 指向整数数组的指针
//
//    // 使用malloc分配内存
//    arr = (int*)malloc(n * sizeof(int));
//    if (arr == NULL) {
//        printf("内存分配失败\n");
//        return 1;
//    }
//
//    // 初始化数组
//    for (int i = 0; i < n; i++) {
//        arr[i] = i * 10;
//    }
//
//    // 打印数组内容
//    printf("数组内容：");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // 使用realloc调整数组大小
//    n = 10;
//    arr = (int*)realloc(arr, n * sizeof(int));
//    if (arr == NULL) {
//        printf("内存重新分配失败\n");
//        return 1;
//    }
//
//    // 初始化扩展部分的数组
//    for (int i = 5; i < n; i++) {
//        arr[i] = i * 10;
//    }
//
//    // 打印扩展后的数组内容
//    printf("扩展后的数组内容：");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    // 释放内存
//    free(arr);
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char source[] = "Hello, ";
//    char destination[20]; // 目标字符串
//
//    // 使用strcpy复制字符串
//    strcpy_s(destination, source);
//    printf("复制后的字符串: %s\n", destination);
//
//    // 使用strcat追加字符串
//    char append[] = "world!";
//    strcat_s(destination, append);
//    printf("追加后的字符串: %s\n", destination);
//
//    // 使用strlen获取字符串长度
//    size_t length = strlen(destination);
//    printf("字符串长度: %zu\n", length);
//
//    // 使用strcmp比较字符串
//    char str1[] = "apple";
//    char str2[] = "banana";
//    int compare_result = strcmp(str1, str2);
//
//    if (compare_result < 0) {
//        printf("%s 在字典顺序上小于 %s\n", str1, str2);
//    }
//    else if (compare_result > 0) {
//        printf("%s 在字典顺序上大于 %s\n", str1, str2);
//    }
//    else {
//        printf("%s 和 %s 相等\n", str1, str2);
//    }
//
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int main() {
//    FILE* file; // 文件指针
//    char buffer[100]; // 缓冲区用于读写数据
//
//    // 打开文件以写入数据
//    file = fopen("example.txt", "w");
//    if (file == NULL) {
//        printf("无法打开文件\n");
//        return 1;
//    }
//
//    // 写入数据到文件
//    fprintf(file, "这是一个文件写入示例。\n");
//    fputs("另一行写入的数据。\n", file);
//
//    // 关闭文件
//    fclose(file);
//
//    // 打开文件以读取数据
//    file = fopen("example.txt", "r");
//    if (file == NULL) {
//        printf("无法打开文件\n");
//        return 1;
//    }
//
//    // 读取并打印文件内容
//    printf("文件内容：\n");
//    while (fgets(buffer, sizeof(buffer), file) != NULL) {
//        printf("%s", buffer);
//    }
//
//    // 关闭文件
//    fclose(file);
//
//    return 0;
//}

//#include <stdio.h>
//
//int add(int a, int b) {
//    return a + b;
//}
//
//int subtract(int a, int b) {
//    return a - b;
//}
//
//int main() {
//    int (*operation)(int, int); // 定义一个接受两个整数参数并返回整数的函数指针
//    int a = 10, b = 5;
//
//    operation = add; // 将函数指针指向 add 函数
//    printf("加法结果：%d\n", operation(a, b));
//
//    operation = subtract; // 将函数指针指向 subtract 函数
//    printf("减法结果：%d\n", operation(a, b));
//
//    return 0;
//}

//#include <stdio.h>
//
//// 回调函数类型
//typedef void (*ButtonClickCallback)(void);
//
//// 模拟按钮
//void simulateButtonClick(ButtonClickCallback callback) {
//    printf("模拟按钮点击事件\n");
//    callback(); // 调用回调函数
//}
//
//// 回调函数实现
//void onButtonClicked() {
//    printf("按钮被点击了！\n");
//}
//
//int main() {
//    printf("程序开始\n");
//
//    // 模拟按钮点击，传递回调函数
//    simulateButtonClick(onButtonClicked);
//
//    printf("程序结束\n");
//
//    return 0;
//}

//#include <stdio.h>
//
//// 检查特定位是否设置
//int isBitSet(int num, int pos) {
//    return (num & (1 << pos)) != 0;
//}
//
//// 设置特定位
//int setBit(int num, int pos) {
//    return num | (1 << pos);
//}
//
//// 清除特定位
//int clearBit(int num, int pos) {
//    return num & ~(1 << pos);
//}
//
//int main() {
//    int num = 42; // 00101010
//
//    printf("初始数字：%d\n", num);
//
//    int bitPos = 3;
//
//    if (isBitSet(num, bitPos)) {
//        printf("位 %d 已设置\n", bitPos);
//    }
//    else {
//        printf("位 %d 未设置\n", bitPos);
//    }
//
//    num = setBit(num, 1); // 设置位 1
//    printf("设置位 1 后的数字：%d\n", num);
//
//    num = clearBit(num, 5); // 清除位 5
//    printf("清除位 5 后的数字：%d\n", num);
//
//    return 0;
//}

//#include <stdio.h>
//
//#define FLAG_A (1 << 0) // 00000001
//#define FLAG_B (1 << 1) // 00000010
//#define FLAG_C (1 << 2) // 00000100
//
//int main() {
//    int state = 0; // 初始状态
//
//    // 设置标志 A 和 B
//    state |= FLAG_A;
//    state |= FLAG_B;
//
//    // 检查标志 C 是否设置
//    if (state & FLAG_C) {
//        printf("标志 C 已设置\n");
//    }
//    else {
//        printf("标志 C 未设置\n");
//    }
//
//    // 清除标志 B
//    state &= ~FLAG_B;
//
//    // 打印最终状态
//    printf("最终状态：%d\n", state);
//
//    return 0;
//}

//#include <stdio.h>
//
//// 函数接受一个指向数组的指针和数组的大小作为参数
//void printArray(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int numbers[] = { 1, 2, 3, 4, 5 };
//    int length = sizeof(numbers) / sizeof(numbers[0]); // 计算数组长度
//
//    printf("原始数组：\n");
//    printArray(numbers, length); // 调用函数，传递数组和长度
//
//    return 0;
//}

//#include <stdio.h>
//
//// 函数接受一个指向数组的指针和数组的大小作为参数
//void printArray(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int numbers[] = { 1, 2, 3, 4, 5 };
//    int length = sizeof(numbers) / sizeof(numbers[0]); // 计算数组长度
//
//    printf("原始数组：\n");
//    printArray(numbers, length); // 调用函数，传递数组和长度
//
//    return 0;
//}

//#include <stdio.h>
//
//// 函数接受一个指向整数指针的指针作为参数
//void modifyValue(int** ptr) {
//    **ptr = 42; // 修改指向的整数的值
//}
//
//int main() {
//    int value = 10;
//    int* ptr = &value; // 指向整数的指针
//    int** doublePtr = &ptr; // 指向指针的指针
//
//    printf("原始值：%d\n", value);
//
//    // 调用函数，传递指向指针的指针
//    modifyValue(doublePtr);
//
//    printf("修改后的值：%d\n", value);
//
//    return 0;
//}

//#include <stdio.h>
//#include <math.h> // 包含数学库
//
//int main() {
//    double x = -4.5;
//    double y = 16.0;
//    double exponent = 3.0;
//
//    // 计算绝对值
//    double absValue = fabs(x);
//    printf("绝对值：%lf\n", absValue);
//
//    // 计算平方根
//    double squareRoot = sqrt(y);
//    printf("平方根：%lf\n", squareRoot);
//
//    // 计算幂次方
//    double powerResult = pow(y, exponent);
//    printf("%lf 的 %lf 次方：%lf\n", y, exponent, powerResult);
//
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <time.h> // 包含时间库
//
//int main() {
//    // 获取当前时间（从1970年1月1日开始的秒数）
//    time_t currentTime;
//    time(&currentTime);
//
//    printf("当前时间（秒数）：%lld\n", currentTime);
//
//    // 将时间值转换为字符串
//    char* timeString = ctime(&currentTime);
//    printf("时间字符串：%s", timeString);
//
//    // 格式化日期和时间
//    struct tm* timeInfo;
//    timeInfo = localtime(&currentTime);
//
//    char formattedTime[50];
//    strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S", timeInfo);
//    printf("格式化时间：%s\n", formattedTime);
//
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//
//int main() {
//    FILE* file = fopen("nonexistent_file.txt", "r");
//    if (file == NULL) {
//        perror("打开文件失败");
//        printf("错误码：%d\n", errno);
//        exit(EXIT_FAILURE);
//    }
//
//    // 这里可以继续处理文件操作
//
//    fclose(file);
//
//    return 0;
//}

#include <stdio.h>

// 定义错误码
#define ERR_FILE_NOT_FOUND 1
#define ERR_PERMISSION_DENIED 2
#define ERR_INVALID_INPUT 3

// 函数用于模拟打开文件操作
int openFile(const char* filename) {
    // 模拟打开失败
    return ERR_FILE_NOT_FOUND;
}

int main() {
    const char* filename = "example.txt";
    int result = openFile(filename);

    if (result == ERR_FILE_NOT_FOUND) {
        printf("错误：文件 %s 不存在\n", filename);
    }
    else if (result == ERR_PERMISSION_DENIED) {
        printf("错误：无权限访问文件 %s\n", filename);
    }
    else if (result == ERR_INVALID_INPUT) {
        printf("错误：无效输入\n");
    }
    else {
        printf("成功打开文件 %s\n", filename);
    }

    return 0;
}
