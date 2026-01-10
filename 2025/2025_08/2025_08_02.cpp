#include <iostream>
#include <fstream> // 用于文件操作
#include <string>
#include <filesystem>
#include <vector>
#include <ctime>
#include <iomanip> // 用于格式化输出

namespace fs = std::filesystem;

void createFileIfNotExists(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.good()) {
        std::ofstream newFile(filePath);
        newFile.close();
    }
}

int readLastNumberFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    int lastNumber = 0;
    if (file.is_open()) {
        file >> lastNumber;
        file.close();
    }
    return lastNumber;
}

void writeNumberToFile(const std::string& filePath, int number) {
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << number;
        file.close();
    }
}

void writeDateToFile(const std::string& filePath, const std::string& date) {
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << date;
        file.close();
    }
}

std::string readDateFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string savedDate;
    if (file.is_open()) {
        file >> savedDate;
        file.close();
    }
    return savedDate;
}

void resetNumberIfNeeded(int startNumber, const std::string& numberFilePath, const std::string& dateFilePath) {
    // 读取当前日期
    time_t now = time(nullptr);
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);
    char currentDate[15]; // 格式化为 YYYYMMDD
    strftime(currentDate, sizeof(currentDate), "%Y%m%d", &timeinfo);

    // 读取之前保存的日期
    std::string savedDate = readDateFromFile(dateFilePath);

    // 如果日期发生了变化，则重置序号为起始序号
    if (savedDate != currentDate) {
        // 删除 current_number.txt 文件并重新创建
        fs::remove(numberFilePath);
        createFileIfNotExists(numberFilePath);
        // 设置 currentNumber 为起始序号
        writeNumberToFile(numberFilePath, startNumber); // 写入起始序号到文件
        writeDateToFile(dateFilePath, currentDate); // 写入当前日期到文件
    }
}

void renameImagesInFolder(const std::string& folderPath, int startNumber, const std::string& numberFilePath, const std::string& dateFilePath) {
    resetNumberIfNeeded(startNumber, numberFilePath, dateFilePath); // 检查日期并重置数据

    int currentNumber = readLastNumberFromFile(numberFilePath); // 从文件中读取上次的序号

    for (const auto& entry : fs::recursive_directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            fs::path newFilePath = entry.path(); // 新路径变量

            // 检查文件是否为 .jfif 格式，并将其改为 .jpg 格式
            if (extension == ".jfif") {
                newFilePath = newFilePath.replace_extension(".jpg");
                fs::rename(entry.path(), newFilePath); // 重命名文件扩展名为 .jpg
                extension = ".jpg"; // 更新扩展名为 .jpg
            }

            // 只处理图片文件
            if (extension == ".jpg" || extension == ".png" || extension == ".jpeg" || extension == ".bmp") {
                // 获取当前日期时间作为前缀
                time_t now = time(nullptr);
                struct tm timeinfo;
                localtime_s(&timeinfo, &now);
                char datePrefix[15]; // 格式化为 YYYYMMDDHHMMSS
                strftime(datePrefix, sizeof(datePrefix), "%Y%m%d%H%M%S", &timeinfo);

                // 组合新的文件名
                std::string newFileName = newFilePath.parent_path().string() + "/" + std::string(datePrefix) + "_" + std::to_string(currentNumber) + extension;
                fs::rename(newFilePath, newFileName); // 重命名文件为新文件名

                // 递增 currentNumber
                ++currentNumber;
            }
        }
    }
    // 更新最后的序号到文件
    writeNumberToFile(numberFilePath, currentNumber);
}

void moveImagesToFolder(const std::string& sourceFolderPath, const std::string& targetFolderPath) {
    // 创建目标文件夹，如果不存在的话
    fs::create_directory(targetFolderPath);

    // 存储目标文件夹中已有的文件名
    std::vector<std::string> targetFileNames;
    for (const auto& entry : fs::recursive_directory_iterator(targetFolderPath)) {
        if (entry.is_regular_file()) {
            targetFileNames.push_back(entry.path().filename().string());
        }
    }

    for (const auto& entry : fs::recursive_directory_iterator(sourceFolderPath)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            // 只处理图片文件，你可以根据需要添加其他图片格式的判断条件
            if (extension == ".jpg" || extension == ".png" || extension == ".jpeg" || extension == ".bmp") {
                // 获取文件名
                std::string fileName = entry.path().filename().string();
                // 检查文件名是否已经存在于目标文件夹中
                if (std::find(targetFileNames.begin(), targetFileNames.end(), fileName) != targetFileNames.end()) {
                    std::cout << "Duplicate file name found: " << fileName << std::endl;
                    std::cout << "Aborting operation." << std::endl;
                    return;
                }
                // 拼接目标路径
                std::string targetPath = targetFolderPath + "/" + fileName;
                // 移动文件
                fs::rename(entry.path(), targetPath);
            }
        }
    }
    std::cout << "All images moved to target folder." << std::endl;
}

int main() {
    std::string folderPath = "E:/Documents Beauty/Convert Files"; // 指定文件夹路径
    std::string targetFolderPath = "E:/Documents Beauty/Convert Folder"; // 指定目标文件夹路径
    std::string numberFilePath = "current_number.txt"; // 记录当前序号的文件路径
    std::string dateFilePath = "current_date.txt"; // 记录当前日期的文件路径
    int startNumber = 10001; // 指定起始序号

    createFileIfNotExists(numberFilePath); // 检查并创建记录序号的文件
    createFileIfNotExists(dateFilePath); // 检查并创建记录日期的文件

    renameImagesInFolder(folderPath, startNumber, numberFilePath, dateFilePath); // 重命名图片并更新序号

    std::cout << "Image renaming completed." << std::endl;

    int choice;
    choice = 1;

    if (choice == 1) {
        // 移动图片到指定文件夹
        moveImagesToFolder(folderPath, targetFolderPath);
    }

    return 0;
}

//#include <iostream>
//#include <filesystem>
//#include <string>
//#include <vector>
//#include <regex>
//#include <iomanip>
//#include <sstream>
//#include <algorithm>
//
//namespace fs = std::filesystem;
//
//// 判断文件是否是图片
//bool isImageFile(const fs::path& filePath) {
//    std::regex imagePattern(R"((\.jpg|\.jpeg|\.png|\.bmp|\.gif)$)", std::regex_constants::icase);
//    return std::regex_search(filePath.extension().string(), imagePattern);
//}
//
//// 生成统一的新文件名
//std::string getNewFileName(int index) {
//    std::ostringstream oss;
//    oss << "Image_" << std::setw(4) << std::setfill('0') << index << ".jpg";
//    return oss.str();
//}
//
//// 第一步：收集所有图片路径，不动文件
//void collectImageFiles(const fs::path& directory, std::vector<fs::path>& imageFiles) {
//    try {
//        for (const auto& entry : fs::recursive_directory_iterator(directory, fs::directory_options::follow_directory_symlink)) {
//            if (fs::is_regular_file(entry.path()) && isImageFile(entry.path())) {
//                imageFiles.push_back(entry.path());
//            }
//        }
//    }
//    catch (const fs::filesystem_error& e) {
//        std::cerr << "遍历错误：" << e.what() << std::endl;
//    }
//}
//
//// 第二步：统一重命名，不再修改结构
//void renameImagesSafely(const std::vector<fs::path>& imageFiles, int& index) {
//    bool hasShownConflictWarning = false; // 用于标记是否已经输出过一次提示
//
//    for (const auto& filePath : imageFiles) {
//        fs::path newFilePath = filePath.parent_path() / getNewFileName(index);
//
//        if (fs::exists(newFilePath)) {
//            if (!hasShownConflictWarning) {
//                std::cerr << "跳过：检测到目标文件已存在，后续重复冲突将不再提示。" << std::endl;
//                hasShownConflictWarning = true;
//            }
//            continue;
//        }
//
//        try {
//            fs::rename(filePath, newFilePath);
//            //std::cout << "已重命名：" << filePath << " -> " << newFilePath << std::endl;
//            index++;
//        }
//        catch (const fs::filesystem_error& e) {
//            std::cerr << "重命名失败：" << filePath << "，错误：" << e.what() << std::endl;
//        }
//    }
//}
//
//
//int main() {
//    fs::path targetDirectory = "E:/Documents Beauty/Convert Files"; // 替换为你的路径
//    int startIndex = 1;
//
//    try {
//        if (fs::exists(targetDirectory) && fs::is_directory(targetDirectory)) {
//            std::vector<fs::path> imageFiles;
//
//            // 第一步：完整收集所有图片
//            collectImageFiles(targetDirectory, imageFiles);
//
//            // 可选：排序（按文件名），保持一致性
//            std::sort(imageFiles.begin(), imageFiles.end());
//
//            // 第二步：重命名
//            renameImagesSafely(imageFiles, startIndex);
//
//            std::cout << "所有图片已重命名完成。" << std::endl;
//        }
//        else {
//            std::cerr << "指定路径不存在或不是目录。" << std::endl;
//        }
//    }
//    catch (const std::exception& e) {
//        std::cerr << "异常：" << e.what() << std::endl;
//    }
//
//    return 0;
//}

