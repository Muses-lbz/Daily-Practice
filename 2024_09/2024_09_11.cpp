//#include <windows.h>
//#include <iostream>
//#include <string>
//#include <thread>
//#include <chrono>
//
//void sendMessage(const std::string& message) {
//    // 模拟输入消息
//    for (char c : message) {
//        INPUT input = { 0 };
//        input.type = INPUT_KEYBOARD;
//        input.ki.wVk = VkKeyScan(c) & 0xFF; // 获取虚拟键码
//
//        SendInput(1, &input, sizeof(INPUT)); // 按下键
//
//        // 模拟松开键
//        input.ki.dwFlags = KEYEVENTF_KEYUP;
//        SendInput(1, &input, sizeof(INPUT)); // 松开键
//
//        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // 控制输入速度
//    }
//
//    // 发送回车
//    INPUT inputEnter = { 0 };
//    inputEnter.type = INPUT_KEYBOARD;
//    inputEnter.ki.wVk = VK_RETURN; // 按下回车键
//
//    SendInput(1, &inputEnter, sizeof(INPUT)); // 按下回车键
//    inputEnter.ki.dwFlags = KEYEVENTF_KEYUP; // 松开回车键
//    SendInput(1, &inputEnter, sizeof(INPUT)); // 松开回车键
//
//    // 输出成功提示
//    std::cout << "消息发送成功: " << message << std::endl;
//}
//
//int main() {
//    std::string memberName = "小小"; // 替换为实际成员名
//    std::string message = "修炼";   // 替换为实际消息
//    std::string fullMessage = "@" + memberName + " " + message;
//    int interval = 90; // 90秒
//
//    while (true) {
//        sendMessage(fullMessage);
//        std::this_thread::sleep_for(std::chrono::seconds(interval));
//    }
//
//    return 0;
//}

#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void clickAt(int x, int y) {
    // 移动鼠标到指定坐标
    SetCursorPos(x, y);
    // 模拟鼠标左键点击
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void sendMessage(const std::string& message) {
    // 点击输入框位置
    clickAt(698, 19); // 替换为你的坐标

    // 模拟输入消息
    for (char c : message) {
        // 模拟按下键
        INPUT input = { 0 };
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VkKeyScan(c) & 0xFF;

        SendInput(1, &input, sizeof(INPUT)); // 按下键

        // 模拟松开键
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT)); // 松开键

        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // 控制输入速度
    }

    // 发送回车
    INPUT inputEnter = { 0 };
    inputEnter.type = INPUT_KEYBOARD;
    inputEnter.ki.wVk = VK_RETURN; // 按下回车键

    SendInput(1, &inputEnter, sizeof(INPUT)); // 按下回车键
    inputEnter.ki.dwFlags = KEYEVENTF_KEYUP; // 松开回车键
    SendInput(1, &inputEnter, sizeof(INPUT)); // 松开回车键

    // 输出成功提示
    std::cout << "消息发送成功: " << message << std::endl;
}

int main() {
    std::string memberName = "小小"; // 替换为实际成员名
    std::string message = "修炼";   // 替换为实际消息
    std::string fullMessage = "@" + memberName + " " + message;
    int interval = 90; // 90秒

    while (true) {
        sendMessage(fullMessage);
        std::this_thread::sleep_for(std::chrono::seconds(interval));
    }

    return 0;
}
