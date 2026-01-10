//#include <iostream>
//#include <vector>
//#include <string>
//
//class Solution {
//public:
//    std::vector<std::string> removeComments(std::vector<std::string>& source) {
//        std::vector<std::string> result;
//        bool blockComment = false; // 标志变量，表示当前是否在块注释中
//        std::string currentLine;
//
//        for (const std::string& line : source) {
//            for (size_t i = 0; i < line.length(); i++) {
//                if (!blockComment) {
//                    // 判断是否进入块注释
//                    if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '*') {
//                        blockComment = true;
//                        i++; // 跳过 '*'
//                    }
//                    // 判断是否进入行注释
//                    else if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '/') {
//                        break; // 跳过剩余部分，不添加到结果
//                    }
//                    else {
//                        currentLine.push_back(line[i]);
//                    }
//                }
//                else {
//                    // 判断是否退出块注释
//                    if (line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/') {
//                        blockComment = false;
//                        i++; // 跳过 '/'
//                    }
//                }
//            }
//
//            // 如果不在块注释中且当前行不为空，将其添加到结果中
//            if (!blockComment && !currentLine.empty()) {
//                result.push_back(currentLine);
//                currentLine.clear();
//            }
//        }
//
//        return result;
//    }
//};
//
//int main() {
//    Solution solution;
//    std::vector<std::string> source = {
//        "/*Test program */",
//        "int main()",
//        "{ ",
//        "  // variable declaration ",
//        "int a, b, c;",
//        "/* This is a test",
//        "   multiline  ",
//        "   comment for ",
//        "   testing */",
//        "a = b + c;",
//        "}"
//    };
//
//    std::vector<std::string> result = solution.removeComments(source);
//    for (const std::string& line : result) {
//        std::cout << line << std::endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> removeComments(std::vector<std::string>& source) {
        std::vector<std::string> result; // 存储最终的去注释结果
        bool blockComment = false; // 标志变量，表示当前是否在块注释中
        std::string currentLine; // 用于暂存当前处理的代码行

        for (const std::string& line : source) {
            for (size_t i = 0; i < line.length(); i++) {
                if (!blockComment) {
                    // 判断是否进入块注释
                    if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '*') {
                        blockComment = true; // 进入块注释
                        i++; // 跳过 '*' 字符
                    }
                    // 判断是否进入行注释
                    else if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '/') {
                        break; // 跳过剩余部分，不添加到结果
                    }
                    else {
                        currentLine.push_back(line[i]); // 将当前字符添加到暂存的行中
                    }
                }
                else {
                    // 判断是否退出块注释
                    if (line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                        blockComment = false; // 退出块注释
                        i++; // 跳过 '/' 字符
                    }
                }
            }

            // 如果不在块注释中且当前行不为空，将其添加到结果中
            if (!blockComment && !currentLine.empty()) {
                result.push_back(currentLine);
                currentLine.clear(); // 清空暂存的行，准备处理下一行
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> source = {
        "/*Test program */",
        "int main()",
        "{ ",
        "  // variable declaration ",
        "int a, b, c;",
        "/* This is a test",
        "   multiline  ",
        "   comment for ",
        "   testing */",
        "a = b + c;",
        "}"
    };

    std::vector<std::string> result = solution.removeComments(source);
    for (const std::string& line : result) {
        std::cout << line << std::endl;
    }

    return 0;
}
