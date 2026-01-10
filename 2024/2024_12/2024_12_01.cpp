#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 学生类
class Student {
public:
    string name;
    string id;

    Student(string n, string i) : name(n), id(i) {}
};

// 学生管理系统类
class StudentManager {
private:
    vector<Student> students;

public:
    // 添加学生
    void addStudent(string name, string id) {
        students.push_back(Student(name, id));
        cout << "学生 " << name << " 添加成功！" << endl;
    }

    // 显示所有学生
    void showStudents() {
        if (students.empty()) {
            cout << "没有学生信息！" << endl;
            return;
        }
        cout << "学生列表：" << endl;
        for (const auto& student : students) {
            cout << "学号: " << student.id << ", 姓名: " << student.name << endl;
        }
    }

    // 删除学生
    void deleteStudent(string id) {
        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "学号为 " << id << " 的学生已删除！" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "未找到学号为 " << id << " 的学生！" << endl;
        }
    }

    // 搜索学生
    void searchStudent(string id) {
        bool found = false;
        for (const auto& student : students) {
            if (student.id == id) {
                cout << "找到学生！学号: " << student.id << ", 姓名: " << student.name << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "未找到学号为 " << id << " 的学生！" << endl;
        }
    }
};

// 主函数
int main() {
    StudentManager manager;
    int choice;

    while (true) {
        // 菜单
        cout << "\n学生管理系统" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 显示学生列表" << endl;
        cout << "3. 删除学生" << endl;
        cout << "4. 搜索学生" << endl;
        cout << "5. 退出" << endl;
        cout << "请选择操作: ";
        cin >> choice;

        string name, id;

        switch (choice) {
        case 1:
            cout << "请输入学生姓名: ";
            cin >> name;
            cout << "请输入学生学号: ";
            cin >> id;
            manager.addStudent(name, id);
            break;

        case 2:
            manager.showStudents();
            break;

        case 3:
            cout << "请输入要删除的学生学号: ";
            cin >> id;
            manager.deleteStudent(id);
            break;

        case 4:
            cout << "请输入要搜索的学生学号: ";
            cin >> id;
            manager.searchStudent(id);
            break;

        case 5:
            cout << "退出系统！" << endl;
            return 0;

        default:
            cout << "无效的选择，请重新输入！" << endl;
        }
    }

    return 0;
}
