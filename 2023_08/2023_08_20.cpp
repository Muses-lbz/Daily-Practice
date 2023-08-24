//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int main() {
//    std::vector<int> numbers = { 10, 20, 30, 40, 50 };
//
//    // 使用 std::find 查找值为 30 的元素
//    auto it = std::find(numbers.begin(), numbers.end(), 30);
//
//    if (it != numbers.end()) {
//        std::cout << "元素 30 已找到，位于索引 " << std::distance(numbers.begin(), it) << " 处。" << std::endl;
//    }
//    else {
//        std::cout << "元素 30 未找到。" << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//struct Student {
//    std::string name;
//    double score;
//};
//
//int main() {
//    std::vector<Student> students = {
//        {"Alice", 85.0},
//        {"Bob", 92.5},
//        {"Charlie", 78.5}
//    };
//
//    // 用户输入要查找的学生姓名
//    std::string targetName;
//    std::cout << "请输入要查找的学生姓名：";
//    std::cin >> targetName;
//
//    // 使用 std::find 查找指定学生
//    auto it = std::find_if(students.begin(), students.end(),
//        [&targetName](const Student& student) {
//            return student.name == targetName;
//        });
//
//    if (it != students.end()) {
//        std::cout << "找到学生 " << targetName << "，成绩为：" << it->score << std::endl;
//    }
//    else {
//        std::cout << "未找到学生：" << targetName << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//struct Student {
//    std::string name;
//    double score;
//};
//
//// 将分数转换为评级
//std::string getGrade(double score) {
//    if (score >= 90.0) {
//        return "A";
//    }
//    else if (score >= 80.0) {
//        return "B";
//    }
//    else if (score >= 70.0) {
//        return "C";
//    }
//    else if (score >= 60.0) {
//        return "D";
//    }
//    else {
//        return "F";
//    }
//}
//
//int main() {
//    std::vector<Student> students = {
//        {"Alice", 85.0},
//        {"Bob", 92.5},
//        {"Charlie", 78.5}
//    };
//
//    std::vector<std::string> grades;
//
//    // 使用 std::transform 将分数转换为评级并存储在另一个容器中
//    std::transform(students.begin(), students.end(), std::back_inserter(grades),
//        [](const Student& student) {
//            return getGrade(student.score);
//        });
//
//    // 显示学生评级
//    for (size_t i = 0; i < students.size(); ++i) {
//        std::cout << "学生 " << students[i].name << " 的评级为：" << grades[i] << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <queue>
//
//int main() {
//    std::priority_queue<int> maxHeap;  // 最大堆
//
//    // 插入元素
//    maxHeap.push(30);
//    maxHeap.push(10);
//    maxHeap.push(50);
//
//    // 获取根节点
//    std::cout << "最大元素：" << maxHeap.top() << std::endl;
//
//    // 删除根节点
//    maxHeap.pop();
//
//    // 获取根节点
//    std::cout << "新的最大元素：" << maxHeap.top() << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int main() {
//    std::vector<int> numbers = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
//
//    int target = 45;
//
//    // 使用 std::lower_bound 查找第一个大于或等于目标值的位置
//    auto it = std::lower_bound(numbers.begin(), numbers.end(), target);
//
//    if (it != numbers.end()) {
//        std::cout << "第一个大于或等于 " << target << " 的元素是：" << *it << std::endl;
//    }
//    else {
//        std::cout << "找不到大于或等于 " << target << " 的元素。" << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <memory>  // 包含智能指针头文件
//
//int main() {
//    // 使用 std::unique_ptr 创建一个动态整数数组
//    std::unique_ptr<int[]> numbers(new int[5]);
//
//    // 初始化数组
//    for (int i = 0; i < 5; ++i) {
//        numbers[i] = i * 10;
//    }
//
//    // 使用 std::unique_ptr 管理的动态数组
//    for (int i = 0; i < 5; ++i) {
//        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
//    }
//
//    // 不需要手动释放资源，unique_ptr 会自动释放
//
//    return 0;
//}

//#include <iostream>
//#include <memory>  // 包含智能指针头文件
//
//class Child;  // 前向声明
//
//class Parent {
//public:
//    std::shared_ptr<Child> child;
//
//    Parent() {
//        std::cout << "Parent 构造函数" << std::endl;
//    }
//
//    ~Parent() {
//        std::cout << "Parent 析构函数" << std::endl;
//    }
//};
//
//class Child {
//public:
//    std::weak_ptr<Parent> parent;
//
//    Child() {
//        std::cout << "Child 构造函数" << std::endl;
//    }
//
//    ~Child() {
//        std::cout << "Child 析构函数" << std::endl;
//    }
//};
//
//int main() {
//    // 使用 std::shared_ptr 和 std::weak_ptr 解决循环引用问题
//    std::shared_ptr<Parent> parent = std::make_shared<Parent>();
//    std::shared_ptr<Child> child = std::make_shared<Child>();
//
//    parent->child = child;
//    child->parent = parent;
//
//    // 输出引用计数
//    std::cout << "Parent 引用计数: " << parent.use_count() << std::endl;
//    std::cout << "Child 引用计数: " << child.use_count() << std::endl;
//
//    // 使用 weak_ptr 检查对象状态
//    std::shared_ptr<Parent> parentCopy = child->parent.lock();
//    if (parentCopy) {
//        std::cout << "Parent 对象仍然存在。" << std::endl;
//    }
//    else {
//        std::cout << "Parent 对象已被释放。" << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <thread>
//
//// 线程函数，作为线程入口点执行的任务
//void threadFunction(int threadId) {
//    std::cout << "线程 " << threadId << " 正在执行任务。" << std::endl;
//}
//
//int main() {
//    // 创建两个线程，并将 threadFunction 作为线程函数传递
//    std::thread thread1(threadFunction, 1);
//    std::thread thread2(threadFunction, 2);
//
//    // 等待线程执行完成
//    thread1.join();
//    thread2.join();
//
//    std::cout << "所有线程任务已完成。" << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <queue>
//
//const int BUFFER_SIZE = 5;
//std::queue<int> buffer;
//std::mutex mtx;
//std::condition_variable cv;
//
//// 生产者线程函数
//void producer() {
//    for (int i = 0; i < 10; ++i) {
//        std::unique_lock<std::mutex> lock(mtx);
//
//        // 如果缓冲区已满，等待消费者消费数据
//        cv.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });
//
//        buffer.push(i);
//        std::cout << "生产者放入数据: " << i << std::endl;
//
//        // 通知消费者有数据可用
//        cv.notify_all();
//    }
//}
//
//// 消费者线程函数
//void consumer() {
//    for (int i = 0; i < 10; ++i) {
//        std::unique_lock<std::mutex> lock(mtx);
//
//        // 如果缓冲区为空，等待生产者产生数据
//        cv.wait(lock, [] { return !buffer.empty(); });
//
//        int data = buffer.front();
//        buffer.pop();
//        std::cout << "消费者取出数据: " << data << std::endl;
//
//        // 通知生产者有空间可用
//        cv.notify_all();
//    }
//}
//
//int main() {
//    std::thread producerThread(producer);
//    std::thread consumerThread(consumer);
//
//    producerThread.join();
//    consumerThread.join();
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//
//class Animal {
//public:
//    Animal(const std::string& name) : name(name) {}
//    virtual void speak() const {
//        std::cout << name << " makes a sound." << std::endl;
//    }
//
//protected: // 使用 protected 让派生类可以访问 name
//    std::string name;
//};
//
//class Mammal : public virtual Animal {
//public:
//    Mammal(const std::string& name) : Animal(name) {}
//    void speak() const override {
//        std::cout << name << " is a mammal." << std::endl;
//    }
//};
//
//class WingedAnimal : public virtual Animal {
//public:
//    WingedAnimal(const std::string& name) : Animal(name) {}
//    void speak() const override {
//        std::cout << name << " can fly." << std::endl;
//    }
//};
//
//class Bat : public Mammal, public WingedAnimal {
//public:
//    Bat(const std::string& name) : Animal(name), Mammal(name), WingedAnimal(name) {}
//    void speak() const override {
//        Mammal::speak(); // 调用 Mammal 类中的 speak 函数
//        WingedAnimal::speak(); // 调用 WingedAnimal 类中的 speak 函数
//    }
//};
//
//int main() {
//    Bat bat("Batty");
//    bat.speak(); // 调用虚继承的成员函数，避免二义性
//    return 0;
//}

//#include <iostream>
//#include <string>
//
//class Animal {
//public:
//    Animal(const std::string& name) : name(name) {}
//    virtual void speak() const {
//        std::cout << name << " makes a sound." << std::endl;
//    }
//
//protected: // 使用 protected 让派生类可以访问 name
//    std::string name;
//};
//
//class Mammal : public virtual Animal {
//public:
//    Mammal(const std::string& name) : Animal(name) {}
//    void speak() const override {
//        std::cout << name << " is a mammal." << std::endl;
//    }
//};
//
//class WingedAnimal : public virtual Animal {
//public:
//    WingedAnimal(const std::string& name) : Animal(name) {}
//    void speak() const override {
//        std::cout << name << " can fly." << std::endl;
//    }
//};
//
//class Bat : public Mammal, public WingedAnimal {
//public:
//    Bat(const std::string& name) : Animal(name), Mammal(name), WingedAnimal(name) {}
//    void speak() const override {
//        Mammal::speak(); // 调用 Mammal 类中的 speak 函数
//        WingedAnimal::speak(); // 调用 WingedAnimal 类中的 speak 函数
//    }
//};
//
//int main() {
//    Bat bat("Batty");
//    bat.speak(); // 调用虚继承的成员函数，避免菱形继承问题
//    return 0;
//}

//#include <iostream>
//#include <string>
//
//class Animal {
//public:
//    Animal(const std::string& name) : name(name) {}
//    virtual void speak() const {
//        std::cout << name << " makes a sound." << std::endl;
//    }
//
//protected:
//    std::string name;
//};
//
//class Mammal : public virtual Animal {
//public:
//    Mammal(const std::string& name) : Animal(name) {}
//    void speak() const override {
//        std::cout << name << " is a mammal." << std::endl;
//    }
//};
//
//class WingedAnimal : public virtual Animal {
//public:
//    WingedAnimal(const std::string& name) : Animal(name) {}
//    void speak() const override {
//        std::cout << name << " can fly." << std::endl;
//    }
//};
//
//class Bat : public Mammal, public WingedAnimal {
//public:
//    Bat(const std::string& name) : Animal(name), Mammal(name), WingedAnimal(name) {}
//    void speak() const override {
//        Mammal::speak(); // 调用 Mammal 类中的 speak 函数
//        WingedAnimal::speak(); // 调用 WingedAnimal 类中的 speak 函数
//    }
//};
//
//int main() {
//    Bat bat("Batty");
//    bat.speak(); // 调用虚继承的成员函数，避免菱形继承问题
//    return 0;
//}

//#include <iostream>
//#include <string>
//
//class Product {
//public:
//    virtual void use() = 0;
//};
//
//class ConcreteProductA : public Product {
//public:
//    void use() override {
//        std::cout << "Using Concrete Product A" << std::endl;
//    }
//};
//
//class ConcreteProductB : public Product {
//public:
//    void use() override {
//        std::cout << "Using Concrete Product B" << std::endl;
//    }
//};
//
//class Factory {
//public:
//    static Product* createProduct(const std::string& type) {
//        if (type == "A") {
//            return new ConcreteProductA();
//        }
//        else if (type == "B") {
//            return new ConcreteProductB();
//        }
//        return nullptr;
//    }
//};
//
//int main() {
//    Product* productA = Factory::createProduct("A");
//    Product* productB = Factory::createProduct("B");
//
//    productA->use(); // Using Concrete Product A
//    productB->use(); // Using Concrete Product B
//
//    delete productA;
//    delete productB;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//class Observer {
//public:
//    virtual void update(const std::string& message) = 0;
//};
//
//class Subject {
//private:
//    std::vector<Observer*> observers;
//    std::string state;
//
//public:
//    void attach(Observer* observer) {
//        observers.push_back(observer);
//    }
//
//    void detach(Observer* observer) {
//        for (auto it = observers.begin(); it != observers.end(); ++it) {
//            if (*it == observer) {
//                observers.erase(it);
//                break;
//            }
//        }
//    }
//
//    void setState(const std::string& newState) {
//        state = newState;
//        notify();
//    }
//
//    void notify() {
//        for (Observer* observer : observers) {
//            observer->update(state);
//        }
//    }
//};
//
//class ConcreteObserver : public Observer {
//public:
//    void update(const std::string& message) override {
//        std::cout << "Received message: " << message << std::endl;
//    }
//};
//
//int main() {
//    Subject subject;
//    ConcreteObserver observer1, observer2;
//
//    subject.attach(&observer1);
//    subject.attach(&observer2);
//
//    subject.setState("State changed.");
//
//    subject.detach(&observer1);
//
//    subject.setState("Another state change.");
//
//    return 0;
//}

//#include <iostream>
//
//// 链表节点结构
//struct Node {
//    int data;
//    Node* next;
//    Node(int val) : data(val), next(nullptr) {}
//};
//
//int main() {
//    // 创建链表节点
//    Node* head = new Node(1);
//    head->next = new Node(2);
//    head->next->next = new Node(3);
//
//    // 遍历链表并打印数据
//    Node* current = head;
//    while (current != nullptr) {
//        std::cout << current->data << " ";
//        current = current->next;
//    }
//    std::cout << std::endl;
//
//    // 清理内存
//    current = head;
//    while (current != nullptr) {
//        Node* temp = current;
//        current = current->next;
//        delete temp;
//    }
//
//    return 0;
//}

//#include <iostream>
//
//// 链表节点结构
//struct Node {
//    int data;
//    Node* next;
//    Node(int val) : data(val), next(nullptr) {}
//};
//
//int main() {
//    // 创建链表节点
//    Node* head = new Node(1);
//    head->next = new Node(2);
//    head->next->next = new Node(3);
//
//    // 遍历链表并打印数据
//    Node* current = head;
//    while (current != nullptr) {
//        std::cout << current->data << " ";
//        current = current->next;
//    }
//    std::cout << std::endl;
//
//    // 清理内存
//    current = head;
//    while (current != nullptr) {
//        Node* temp = current;
//        current = current->next;
//        delete temp;
//    }
//
//    return 0;
//}

//#include <iostream>
//
//// 循环链表节点结构
//struct Node {
//    int data;
//    Node* next;
//    Node(int val) : data(val), next(nullptr) {}
//};
//
//int main() {
//    // 创建循环链表节点
//    Node* head = new Node(1);
//    Node* second = new Node(2);
//    Node* third = new Node(3);
//
//    // 构建循环链表关系
//    head->next = second;
//    second->next = third;
//    third->next = head;
//
//    // 从任意节点开始遍历并打印数据
//    Node* start = second;  // 从第二个节点开始遍历
//    Node* current = start;
//    for (int i = 0; i < 5; ++i) {  // 遍历5次
//        std::cout << current->data << " ";
//        current = current->next;
//    }
//    std::cout << std::endl;
//
//    // 清理内存
//    Node* temp = head;
//    do {
//        Node* nextNode = temp->next;
//        delete temp;
//        temp = nextNode;
//    } while (temp != head);
//
//    return 0;
//}

#include <iostream>

// 双向循环链表节点结构
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

int main() {
    // 创建双向循环链表节点
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // 构建双向循环链表关系
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = head;

    // 从前往后遍历并打印数据
    Node* currentForward = head;
    for (int i = 0; i < 5; ++i) {
        std::cout << currentForward->data << " ";
        currentForward = currentForward->next;
    }
    std::cout << std::endl;

    // 从后往前遍历并打印数据
    Node* currentBackward = third;
    for (int i = 0; i < 5; ++i) {
        std::cout << currentBackward->data << " ";
        currentBackward = currentBackward->prev;
    }
    std::cout << std::endl;

    // 清理内存
    Node* temp = head;
    do {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != head);

    return 0;
}
