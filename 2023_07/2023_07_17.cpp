//#include <iostream>
//
//float resqrt(float num, float epsilon = 0.0001) {
//    float guess = num;  // 初始猜测值为 num
//    float diff;
//
//    while (true) {
//        float new_guess = 0.5f * (guess + num / guess);  // 使用牛顿迭代公式计算新的猜测值
//        diff = new_guess - guess;  // 计算当前猜测值与上一次猜测值的差值
//
//        // 如果差值小于给定的 epsilon，认为已经达到了足够的精度
//        if (diff < epsilon && -diff < epsilon) {
//            break;
//        }
//
//        guess = new_guess;  // 更新猜测值
//    }
//
//    return guess;
//}
//
//int main() {
//    float num;
//    std::cout << "请输入一个非负实数: ";
//    std::cin >> num;
//
//    if (num < 0) {
//        std::cout << "输入错误，无法计算负数的平方根。" << std::endl;
//        return 0;
//    }
//
//    float result = resqrt(num);
//    std::cout << "平方根: " << result << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    string result = "";  // 存储相加结果的字符串
    int carry = 0;  // 进位标志

    // 从字符串的最低位开始逐位相加
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;  // 取 num1 的当前位数字，若已遍历完则取 0
        int digit2 = j >= 0 ? num2[j] - '0' : 0;  // 取 num2 的当前位数字，若已遍历完则取 0
        int sum = digit1 + digit2 + carry;  // 当前位的数字相加

        carry = sum / 10;  // 计算进位
        sum = sum % 10;  // 计算当前位的值

        result += (sum + '0');  // 将当前位的值转为字符并加入结果字符串
        i--;
        j--;
    }

    reverse(result.begin(), result.end());  // 反转结果字符串，得到正确的顺序

    return result;
}

int main() {
    string num1, num2;
    cout << "请输入非负整数 num1: ";
    cin >> num1;
    cout << "请输入非负整数 num2: ";
    cin >> num2;

    string sum = addStrings(num1, num2);
    cout << "两个数字的和为: " << sum << endl;

    return 0;
}
