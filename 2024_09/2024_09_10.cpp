//#include <windows.h>
//#include <iostream>
//
//void ListWindows() {
//    HWND hwnd = GetTopWindow(NULL);
//    while (hwnd) {
//        char title[256];
//        GetWindowTextA(hwnd, title, sizeof(title));
//        if (IsWindowVisible(hwnd) && strlen(title) > 0) {
//            std::cout << "窗口句柄: " << hwnd << " | 标题: " << title << std::endl;
//        }
//        hwnd = GetNextWindow(hwnd, GW_HWNDNEXT);
//    }
//}
//
//int main() {
//    ListWindows();
//    return 0;
//}

#include <windows.h>
#include <iostream>

void ListWindows() {
    HWND hwnd = GetTopWindow(NULL);
    while (hwnd) {
        char title[256];
        GetWindowTextA(hwnd, title, sizeof(title));
        if (IsWindowVisible(hwnd) && strlen(title) > 0) {
            std::cout << "窗口句柄: " << hwnd << " | 标题: " << title << std::endl;
        }
        hwnd = GetNextWindow(hwnd, GW_HWNDNEXT);
    }
}

int main() {
    ListWindows();
    return 0;
}
