#include <hpdf.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

// 错误处理函数
void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data) {
    std::cerr << "HPDF ERROR: " << error_no << ", detail: " << detail_no << std::endl;
}

// 插入图片到 PDF
void insert_image_to_pdf(HPDF_Doc pdf, const std::string& image_path, HPDF_Page page, float x, float y, float width, float height) {
    // 加载图片
    HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf, image_path.c_str());

    if (!image) {
        std::cerr << "无法加载图片: " << image_path << std::endl;
        return;
    }

    // 按照指定的宽度和高度绘制图片
    HPDF_Page_DrawImage(page, image, x, y, width, height);
}

// 创建新页面
HPDF_Page create_new_page(HPDF_Doc pdf) {
    HPDF_Page page = HPDF_AddPage(pdf);
    HPDF_Page_SetWidth(page, 595);  // A4 页面宽度
    HPDF_Page_SetHeight(page, 842); // A4 页面高度
    return page;
}

int main() {
    // 创建 PDF 文档
    HPDF_Doc pdf = HPDF_New(error_handler, nullptr);
    if (!pdf) {
        std::cerr << "无法创建 PDF 文档！" << std::endl;
        return 1;
    }

    // 获取指定目录下的图片文件
    std::string image_dir = "E:/Documents Beauty/Convert Files"; // 替换为图片所在的路径
    std::vector<std::string> image_files;

    // 遍历目录并收集图片文件
    for (const auto& entry : std::filesystem::directory_iterator(image_dir)) {
        if (entry.is_regular_file() && (entry.path().extension() == ".jpg" || entry.path().extension() == ".jpeg" || entry.path().extension() == ".png")) {
            image_files.push_back(entry.path().string());
        }
    }

    // 设置图片插入位置和尺寸
    float x = 50.0f; // 图片 X 坐标
    float y = 842 - 50 - 150.0f; // 第一页图片的 Y 坐标，留出上边距
    float width = 200.0f; // 图片宽度
    float height = 150.0f; // 图片高度
    float page_top_margin = 50.0f; // 页面的上边距，预留空白区域

    // 创建第一页
    HPDF_Page page = create_new_page(pdf);

    // 插入每张图片到 PDF
    for (size_t i = 0; i < image_files.size(); ++i) {
        // 如果 y 坐标低于上边距，则换新的一页
        if (y < page_top_margin + height) {
            page = create_new_page(pdf);
            x = 50.0f; // 重置 X 坐标
            y = 842 - page_top_margin - height; // 重置 Y 坐标，留出上边距
        }

        insert_image_to_pdf(pdf, image_files[i], page, x, y, width, height);

        // 更新插入位置，插入第二张图片
        x += width;  // 更新 X 坐标，插入第二张图片
        if (x + width > 595 - 50) {  // 如果右侧超出页面宽度
            x = 50.0f;  // 重置 X 坐标
            y -= (height);  // 更新 Y 坐标，换行插入
        }
    }

    // 保存 PDF
    HPDF_SaveToFile(pdf, "output.pdf");

    // 释放资源
    HPDF_Free(pdf);

    std::cout << "PDF 生成成功！" << std::endl;
    return 0;
}
