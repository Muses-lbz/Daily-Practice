#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 学生类
class Student {
public:
    // 构造函数
    Student(string name, int age, int id) : name(name), age(age), id(id) {}

    // 成员函数
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << endl;
    }

private:
    string name;
    int age;
    int id;
};

// 学生管理类
class StudentManager {
public:
    // 添加学生
    void addStudent(string name, int age, int id) {
        Student newStudent(name, age, id);
        students.push_back(newStudent);
    }

    // 显示所有学生信息
    void displayAllStudents(){
        cout << "Students List:" << endl;
        for (const auto& student : students) {
            student.displayInfo();
        }
    }

    // 查找学生
    void findStudent(int id) {
        for (const auto& student : students) {
            if (studentIdMatch(student, id)) {
                cout << "Student found:" << endl;
                student.displayInfo();
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

private:
    vector<Student> students;

    // 检查学生 ID 是否匹配
    bool studentIdMatch(const Student& student, int id) {
        return studentIdMatch(student, id);
    }
};

int main() {
    StudentManager manager;

    // 添加一些学生信息
    manager.addStudent("Alice", 20, 1001);
    manager.addStudent("Bob", 21, 1002);
    manager.addStudent("Charlie", 22, 1003);

    // 显示所有学生信息
    manager.displayAllStudents();

    // 查找学生信息
    manager.findStudent(1002); // 查找学生 ID 为 1002 的信息

    return 0;
}