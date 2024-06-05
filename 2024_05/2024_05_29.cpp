//#include <string>
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    int maximumLength(string s) {
//        int n = (int)s.size();
//        // 使用哈希表记录每个字符连续出现的长度
//        unordered_map<char, vector<int>> cnt;
//        for (int i = 0, j = 0; i < s.size(); i = j) {
//            while (j < s.size() && s[j] == s[i]) {
//                j++;
//            }
//            cnt[s[i]].emplace_back(j - i);
//        }
//
//        int res = -1;
//        // 对每个字符的长度向量进行处理
//        for (auto& [_, vec] : cnt) {
//            int lo = 1, hi = n - 2;
//            // 二分查找找到最大长度
//            while (lo <= hi) {
//                int mid = (lo + hi) / 2;
//                int count = 0;
//                // 计算能够形成长度为 mid 的特殊子字符串的数量
//                for (int x : vec) {
//                    if (x >= mid) {
//                        count += x - mid + 1;
//                    }
//                }
//                // 如果数量大于等于3，更新结果并尝试更长的子字符串
//                if (count >= 3) {
//                    res = max(res, mid);
//                    lo = mid + 1;
//                }
//                else {
//                    // 否则，尝试更短的子字符串
//                    hi = mid - 1;
//                }
//            }
//        }
//        return res;
//    }
//};
//
//// 主函数用于测试 Solution 类中的 maximumLength 函数
//int main() {
//    Solution solution;
//    string test_str = "aaaa";
//    int result = solution.maximumLength(test_str);
//    cout << "输入: " << test_str << endl;
//    cout << "输出: " << result << endl;
//    return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

// 命名空间使用
using namespace std;

// 定义一个基类 - 书籍
class Book {
public:
    Book(string id = "", string title = "", string author = "")
        : id(id), title(title), author(author) {}

    // 虚函数 - 获取书籍信息
    virtual string getInfo() const {
        return "ID: " + id + ", Title: " + title + ", Author: " + author;
    }

    string getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

private:
    string id;
    string title;
    string author;
};

// 派生类 - 纸质书
class PaperBook : public Book {
public:
    PaperBook(string id = "", string title = "", string author = "", int pages = 0)
        : Book(id, title, author), pages(pages) {}

    string getInfo() const override {
        return Book::getInfo() + ", Pages: " + to_string(pages);
    }

private:
    int pages;
};

// 派生类 - 电子书
class EBook : public Book {
public:
    EBook(string id = "", string title = "", string author = "", double fileSize = 0.0)
        : Book(id, title, author), fileSize(fileSize) {}

    string getInfo() const override {
        return Book::getInfo() + ", File Size: " + to_string(fileSize) + "MB";
    }

private:
    double fileSize;
};

// 模板类 - 库存管理
template <typename T>
class Library {
public:
    void addBook(const T& book) {
        lock_guard<mutex> lock(libMutex);
        books[book.getId()] = book;
    }

    void removeBook(const string& id) {
        lock_guard<mutex> lock(libMutex);
        books.erase(id);
    }

    T getBook(const string& id) {
        lock_guard<mutex> lock(libMutex);
        return books.at(id);
    }

    vector<T> getAllBooks() {
        lock_guard<mutex> lock(libMutex);
        vector<T> allBooks;
        for (const auto& pair : books) {
            allBooks.push_back(pair.second);
        }
        return allBooks;
    }

    // 多线程函数 - 保存数据到文件
    void saveToFile(const string& filename) {
        lock_guard<mutex> lock(fileMutex);
        ofstream file(filename);
        for (const auto& pair : books) {
            file << pair.second.getInfo() << endl;
        }
        file.close();
    }

    // 多线程函数 - 从文件加载数据
    void loadFromFile(const string& filename) {
        lock_guard<mutex> lock(fileMutex);
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            // 简单解析示例，实际情况需根据格式具体处理
            // 此处假设每行格式为：ID: id, Title: title, Author: author, Pages/File Size: value
            // 根据具体类型创建相应对象
        }
        file.close();
    }

private:
    unordered_map<string, T> books;
    mutex libMutex;    // 库存管理锁
    mutex fileMutex;   // 文件操作锁
};

// 全局对象
Library<PaperBook> paperLibrary;
Library<EBook> ebookLibrary;

// 多线程示例函数
void addBooksThread() {
    for (int i = 0; i < 10; ++i) {
        paperLibrary.addBook(PaperBook("P" + to_string(i), "Paper Book " + to_string(i), "Author " + to_string(i), 100 + i));
        ebookLibrary.addBook(EBook("E" + to_string(i), "E-Book " + to_string(i), "Author " + to_string(i), 1.5 * i));
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// 主函数
int main() {
    // 创建线程并行添加书籍
    thread t1(addBooksThread);
    thread t2(addBooksThread);

    t1.join();
    t2.join();

    // 打印所有纸质书
    vector<PaperBook> paperBooks = paperLibrary.getAllBooks();
    cout << "Paper Books:" << endl;
    for (const auto& book : paperBooks) {
        cout << book.getInfo() << endl;
    }

    // 打印所有电子书
    vector<EBook> ebooks = ebookLibrary.getAllBooks();
    cout << "E-Books:" << endl;
    for (const auto& book : ebooks) {
        cout << book.getInfo() << endl;
    }

    // 保存书籍信息到文件
    paperLibrary.saveToFile("paper_books.txt");
    ebookLibrary.saveToFile("ebooks.txt");

    return 0;
}
