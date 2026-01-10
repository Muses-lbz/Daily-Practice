#include <windows.h>
#include <iostream>

int main() {
    // 替换为你群聊窗口的标题
    const char* windowTitle = "残虹大府后勤处";
    HWND hwnd = FindWindowA(NULL, windowTitle);

    if (hwnd != NULL) {
        RECT rect;
        GetWindowRect(hwnd, &rect);
        std::cout << "窗口坐标: (" << rect.left << ", " << rect.top << ")" << std::endl;
    }
    else {
        std::cerr << "未找到窗口，请检查窗口标题。" << std::endl;
    }

    return 0;
}
