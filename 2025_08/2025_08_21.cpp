//#include <iostream>
//#include <filesystem>
//#include <string>
//#include <vector>
//#include <regex>
//#include <iomanip>
//#include <sstream>
//
//namespace fs = std::filesystem;
//
//// 判断文件是否是图片（根据文件扩展名）
//bool isImageFile(const fs::path& filePath) {
//    std::regex imagePattern(R"((\.jpg|\.jpeg|\.png|\.bmp|\.gif)$)", std::regex_constants::icase);
//    return std::regex_search(filePath.extension().string(), imagePattern);
//}
//
//// 获取新的文件名
//std::string getNewFileName(int index) {
//    std::ostringstream oss;
//    oss << "DIY WORD _" << std::setw(4) << std::setfill('0') << index << ".jpg"; // 假设所有图片都重命名为jpg格式
//    return oss.str();
//}
//
//// 递归遍历并重命名文件
//void renameImages(const fs::path& directory, int& index) {
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (fs::is_directory(entry.path())) {
//            // 如果是子目录，递归调用
//            renameImages(entry.path(), index);
//        }
//        else if (fs::is_regular_file(entry.path()) && isImageFile(entry.path())) {
//            // 如果是图片文件，重命名
//            fs::path newFilePath = directory / getNewFileName(index);
//            fs::rename(entry.path(), newFilePath);
//            std::cout << "Renamed: " << entry.path().string() << " -> " << newFilePath.string() << std::endl;
//            index++;
//        }
//    }
//}
//
//int main() {
//    fs::path targetDirectory = "E:/Documents Beauty/Convert Files"; // 目标目录路径
//    int startIndex = 1; // 重命名的起始索引
//
//    try {
//        if (fs::exists(targetDirectory) && fs::is_directory(targetDirectory)) {
//            renameImages(targetDirectory, startIndex);
//            std::cout << "All images have been renamed successfully." << std::endl;
//        }
//        else {
//            std::cerr << "The specified path does not exist or is not a directory." << std::endl;
//        }
//    }
//    catch (const fs::filesystem_error& e) {
//        std::cerr << "Filesystem error: " << e.what() << std::endl;
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Exception: " << e.what() << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <filesystem>
//#include <string>
//#include <vector>
//#include <regex>
//#include <iomanip>
//#include <sstream>
//
//namespace fs = std::filesystem;
//
//// 判断文件是否是图片（根据文件扩展名）
//bool isImageFile(const fs::path& filePath) {
//    std::regex imagePattern(R"((\.jpg|\.jpeg|\.png|\.bmp|\.gif)$)", std::regex_constants::icase);
//    return std::regex_search(filePath.extension().string(), imagePattern);
//}
//
//// 获取新的文件名
//std::string getNewFileName(int index) {
//    std::ostringstream oss;
//    oss << " Diy Word  _"
//        << std::setw(4) << std::setfill('0') << index << ".jpg"; // 假设所有图片都重命名为jpg格式
//    return oss.str();
//}
//
//// 递归遍历并重命名+移动文件
//void renameAndMoveImages(const fs::path& directory, const fs::path& outputDir, int& index) {
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (fs::is_directory(entry.path())) {
//            // 如果是子目录，递归调用
//            renameAndMoveImages(entry.path(), outputDir, index);
//        }
//        else if (fs::is_regular_file(entry.path()) && isImageFile(entry.path())) {
//            // 如果是图片文件，重命名
//            fs::path newFileName = getNewFileName(index);
//            fs::path tempNewPath = entry.path().parent_path() / newFileName;
//
//            // 先在原目录中重命名
//            fs::rename(entry.path(), tempNewPath);
//
//            // 构造最终移动后的路径
//            fs::path finalPath = outputDir / newFileName;
//
//            // 移动到目标文件夹
//            fs::rename(tempNewPath, finalPath);
//
//            //std::cout << "Moved: " << entry.path().string()
//                //<< " -> " << finalPath.string() << std::endl;
//
//            index++;
//        }
//    }
//}
//
//int main() {
//    fs::path targetDirectory = "E:/Documents Beauty/Convert Files"; // 原始目录
//    fs::path outputDirectory = "E:/Documents Beauty/Convert Founder"; // 新的存放目录
//    int startIndex = 1; // 重命名的起始索引
//
//    try {
//        if (!fs::exists(outputDirectory)) {
//            fs::create_directories(outputDirectory); // 如果目标目录不存在，创建
//        }
//
//        if (fs::exists(targetDirectory) && fs::is_directory(targetDirectory)) {
//            renameAndMoveImages(targetDirectory, outputDirectory, startIndex);
//            std::cout << "All images have been renamed and moved successfully." << std::endl;
//        }
//        else {
//            std::cerr << "The specified path does not exist or is not a directory." << std::endl;
//        }
//    }
//    catch (const fs::filesystem_error& e) {
//        std::cerr << "Filesystem error: " << e.what() << std::endl;
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Exception: " << e.what() << std::endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <filesystem>
#include <regex>
#include <iomanip>
#include <sstream>

namespace fs = std::filesystem;

// 判断文件是否是图片
bool isImageFile(const fs::path& filePath) {
    std::regex imagePattern(R"((\.jpg|\.jpeg|\.png|\.bmp|\.gif)$)", std::regex_constants::icase);
    return std::regex_search(filePath.extension().string(), imagePattern);
}

// 获取新的文件名（用文件夹名作为前缀）
std::string getNewFileName(const std::string& folderName, int index) {
    std::ostringstream oss;
    oss << folderName << " _"
        << std::setw(4) << std::setfill('0') << index << ".jpg";
    return oss.str();
}

// 遍历重命名并移动
void renameAndMoveImages(const fs::path& directory,
    const fs::path& outputDir,
    const std::string& folderName,
    int& index) {
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (fs::is_directory(entry.path())) {
            renameAndMoveImages(entry.path(), outputDir, folderName, index);
        }
        else if (fs::is_regular_file(entry.path()) && isImageFile(entry.path())) {
            fs::path newFileName = getNewFileName(folderName, index);
            fs::path finalPath = outputDir / newFileName;

            fs::rename(entry.path(), finalPath);

            /*std::cout << "Moved: " << entry.path().string()
                << " -> " << finalPath.string() << std::endl;*/

            index++;
        }
    }
}

int main() {
    fs::path targetDirectory = "E:/Documents Beauty/Convert Files"; // 原始目录
    fs::path outputRoot = "E:/Documents Beauty/Convert Founder"; // 总输出目录

    try {
        // 1. 找到原始目录下的第一个文件夹
        fs::path subFolder;
        for (const auto& entry : fs::directory_iterator(targetDirectory)) {
            if (fs::is_directory(entry.path())) {
                subFolder = entry.path();
                break;
            }
        }

        if (subFolder.empty()) {
            std::cerr << "No subfolder found in " << targetDirectory << std::endl;
            return 1;
        }

        // 2. 获取文件夹名称
        std::string folderName = subFolder.filename().string();

        // 3. 在输出目录里创建同名子文件夹
        fs::path outputDir = outputRoot / folderName;
        if (!fs::exists(outputDir)) {
            fs::create_directories(outputDir);
        }

        // 4. 重命名并移动
        int startIndex = 1;
        renameAndMoveImages(subFolder, outputDir, folderName, startIndex);

        std::cout << "All Images Renamed And Moved Into " << std::endl 
            << outputDir.string() << std::endl;
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

