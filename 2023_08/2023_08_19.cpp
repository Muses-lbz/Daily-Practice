//#include <iostream>
//
//class Solution {
//public:
//    int getSum(int a, int b) {
//        while (b != 0) {
//            int carry = a & b;
//            a = a ^ b;
//            b = static_cast<unsigned int>(carry) << 1;
//        }
//        return a;
//    }
//};
//
//int main() {
//    Solution solution;
//    int num1 = -5;
//    int num2 = -7;
//    int result = solution.getSum(num1, num2);
//    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result << std::endl;
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <cstring>
//
//class StringHolder {
//private:
//    char* str;
//
//public:
//    // 构造函数
//    StringHolder(const char* s) {
//        std::cout << "Constructing StringHolder" << std::endl;
//        str = new char[strlen(s) + 1];
//        strcpy(str, s);
//    }
//
//    // 析构函数
//    ~StringHolder() {
//        std::cout << "Destructing StringHolder" << std::endl;
//        delete[] str;
//    }
//
//    void display() {
//        std::cout << "String: " << str << std::endl;
//    }
//};
//
//int main() {
//    StringHolder obj1("Hello");
//
//    obj1.display();
//
//    StringHolder obj2("World");
//
//    obj2.display();
//
//    return 0;
//}

//#include <iostream>
//
//// 基类 Shape
//class Shape {
//public:
//    void display() {
//        std::cout << "This is a shape." << std::endl;
//    }
//};
//
//// Circle 类继承自 Shape 类
//class Circle : public Shape {
//public:
//    void display() {
//        std::cout << "This is a circle." << std::endl;
//    }
//};
//
//// Rectangle 类继承自 Shape 类
//class Rectangle : public Shape {
//public:
//    void display() {
//        std::cout << "This is a rectangle." << std::endl;
//    }
//};
//
//int main() {
//    Shape shape;
//    Circle circle;
//    Rectangle rectangle;
//
//    shape.display();      // 输出：This is a shape.
//    circle.display();     // 输出：This is a circle.
//    rectangle.display();  // 输出：This is a rectangle.
//
//    return 0;
//}

//#include <iostream>
//
//class Shape {
//public:
//    virtual void draw() {
//        std::cout << "Drawing a shape." << std::endl;
//    }
//};
//
//class Circle : public Shape {
//public:
//    void draw() override {
//        std::cout << "Drawing a circle." << std::endl;
//    }
//};
//
//class Rectangle : public Shape {
//public:
//    void draw() override {
//        std::cout << "Drawing a rectangle." << std::endl;
//    }
//};
//
//int main() {
//    Shape* shapePtr;
//
//    Circle circle;
//    Rectangle rectangle;
//
//    shapePtr = &circle;
//    shapePtr->draw();  // 输出：Drawing a circle.
//
//    shapePtr = &rectangle;
//    shapePtr->draw();  // 输出：Drawing a rectangle.
//
//    return 0;
//}

//#include <iostream>
//
//class Animal {
//public:
//    virtual void makeSound() {
//        std::cout << "Animal makes a sound." << std::endl;
//    }
//};
//
//class Dog : public Animal {
//public:
//    void makeSound() override {
//        std::cout << "Dog barks." << std::endl;
//    }
//};
//
//class Cat : public Animal {
//public:
//    void makeSound() override {
//        std::cout << "Cat meows." << std::endl;
//    }
//};
//
//int main() {
//    Animal* animals[3];
//
//    Dog dog;
//    Cat cat;
//
//    animals[0] = &dog;
//    animals[1] = &cat;
//    animals[2] = new Dog();  // 动态分配对象
//
//    for (int i = 0; i < 3; ++i) {
//        animals[i]->makeSound();  // 多态性，根据实际对象类型调用正确的方法
//    }
//
//    delete animals[2];  // 释放动态分配的对象
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//// 定义学生类
//class Student {
//private:
//    std::string name;
//    double score;
//
//public:
//    Student(const std::string& n, double s) : name(n), score(s) {}
//
//    const std::string& getName() const {
//        return name;
//    }
//
//    double getScore() const {
//        return score;
//    }
//};
//
//// 学生信息管理类
//class StudentManager {
//private:
//    std::vector<Student> students;  // 使用 std::vector 存储学生信息
//
//public:
//    // 添加学生信息
//    void addStudent(const Student& student) {
//        students.push_back(student);
//    }
//
//    // 显示学生列表
//    void displayStudents() {
//        std::cout << "学生列表：" << std::endl;
//        for (const auto& student : students) {
//            std::cout << "姓名：" << student.getName() << "，成绩：" << student.getScore() << std::endl;
//        }
//    }
//
//    // 计算平均成绩
//    double calculateAverageScore() {
//        if (students.empty()) {
//            return 0.0;
//        }
//
//        double totalScore = 0.0;
//        for (const auto& student : students) {
//            totalScore += student.getScore();
//        }
//        return totalScore / students.size();
//    }
//
//    // 根据姓名查找学生
//    void findStudentByName(const std::string& name) {
//        auto it = std::find_if(students.begin(), students.end(),
//            [&name](const Student& student) {
//                return student.getName() == name;
//            });
//
//        if (it != students.end()) {
//            std::cout << "找到学生：姓名：" << it->getName() << "，成绩：" << it->getScore() << std::endl;
//        }
//        else {
//            std::cout << "未找到学生。" << std::endl;
//        }
//    }
//};
//
//int main() {
//    StudentManager manager;
//
//    // 添加几名学生
//    manager.addStudent(Student("Alice", 85.0));
//    manager.addStudent(Student("Bob", 92.5));
//    manager.addStudent(Student("Charlie", 78.5));
//
//    // 显示学生列表
//    manager.displayStudents();
//
//    // 计算平均成绩并显示
//    double averageScore = manager.calculateAverageScore();
//    std::cout << "平均成绩：" << averageScore << std::endl;
//
//    // 查找学生并显示结果
//    manager.findStudentByName("Bob");
//    manager.findStudentByName("David");
//
//    return 0;
//}

//#include <iostream>
//#include <list>
//#include <string>
//
//class TodoItem {
//private:
//    std::string description;
//    bool completed;
//
//public:
//    TodoItem(const std::string& desc) : description(desc), completed(false) {}
//
//    const std::string& getDescription() const {
//        return description;
//    }
//
//    bool isCompleted() const {
//        return completed;
//    }
//
//    void markAsCompleted() {
//        completed = true;
//    }
//};
//
//class TodoList {
//private:
//    std::list<TodoItem> items;  // 使用 std::list 存储待办事项
//
//public:
//    // 添加待办事项
//    void addTask(const std::string& description) {
//        items.push_back(TodoItem(description));
//    }
//
//    // 显示待办事项列表
//    void displayTasks() {
//        std::cout << "待办事项列表：" << std::endl;
//        for (const auto& item : items) {
//            std::cout << (item.isCompleted() ? "[已完成] " : "[未完成] ") << item.getDescription() << std::endl;
//        }
//    }
//
//    // 完成待办事项
//    void completeTask(const std::string& description) {
//        for (auto& item : items) {
//            if (item.getDescription() == description) {
//                item.markAsCompleted();
//                std::cout << "已完成任务：" << description << std::endl;
//                return;
//            }
//        }
//        std::cout << "未找到任务：" << description << std::endl;
//    }
//};
//
//int main() {
//    TodoList list;
//
//    // 添加几个待办事项
//    list.addTask("购物");
//    list.addTask("写作业");
//    list.addTask("锻炼");
//
//    // 显示待办事项列表
//    list.displayTasks();
//
//    // 标记任务为已完成
//    list.completeTask("写作业");
//    list.completeTask("做家务");
//
//    // 显示更新后的待办事项列表
//    list.displayTasks();
//
//    return 0;
//}

#include <iostream>
#include <set>
#include <string>

class MeetingManager {
private:
    std::set<std::string> participants; // 使用 std::set 存储会议参与者

public:
    // 添加会议参与者
    void addParticipant(const std::string& name) {
        participants.insert(name);
    }

    // 显示会议参与者名单
    void displayParticipants() {
        std::cout << "会议参与者名单：" << std::endl;
        for (const auto& participant : participants) {
            std::cout << participant << std::endl;
        }
    }

    // 查找会议参与者
    void findParticipant(const std::string& name) {
        auto it = participants.find(name);
        if (it != participants.end()) {
            std::cout << "找到参与者：" << *it << std::endl;
        }
        else {
            std::cout << "未找到参与者：" << name << std::endl;
        }
    }

    // 移除会议参与者
    void removeParticipant(const std::string& name) {
        participants.erase(name);
    }
};

int main() {
    MeetingManager manager;

    // 添加会议参与者
    manager.addParticipant("Alice");
    manager.addParticipant("Bob");
    manager.addParticipant("Charlie");

    // 显示会议参与者名单
    manager.displayParticipants();

    // 查找会议参与者
    manager.findParticipant("Bob");
    manager.findParticipant("David");

    // 移除会议参与者
    manager.removeParticipant("Charlie");

    // 显示更新后的会议参与者名单
    manager.displayParticipants();

    return 0;
}
