//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    int maxAbsoluteSum(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> maxEndingHere(n);
//        vector<int> minEndingHere(n);
//
//        maxEndingHere[0] = nums[0];
//        minEndingHere[0] = nums[0];
//
//        int maxAbsolute = abs(nums[0]);
//
//        for (int i = 1; i < n; ++i) {
//            maxEndingHere[i] = max(nums[i], maxEndingHere[i - 1] + nums[i]);
//            minEndingHere[i] = min(nums[i], minEndingHere[i - 1] + nums[i]);
//            maxAbsolute = max(maxAbsolute, max(abs(maxEndingHere[i]), abs(minEndingHere[i])));
//        }
//
//        return maxAbsolute;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = { 1, -3, 2, 3, -4 };
//    int result = solution.maxAbsoluteSum(nums);
//    cout << "Maximum absolute sum of any subarray: " << result << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    int maxAbsoluteSum(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> maxEndingHere(n);
//        vector<int> minEndingHere(n);
//
//        // 初始化以第一个元素结尾的子数组的最大和和最小和
//        maxEndingHere[0] = nums[0];
//        minEndingHere[0] = nums[0];
//
//        // 初始化最大绝对和为第一个元素的绝对值
//        int maxAbsolute = abs(nums[0]);
//
//        // 遍历数组
//        for (int i = 1; i < n; ++i) {
//            // 更新以当前元素结尾的子数组的最大和
//            maxEndingHere[i] = max(nums[i], maxEndingHere[i - 1] + nums[i]);
//            // 更新以当前元素结尾的子数组的最小和
//            minEndingHere[i] = min(nums[i], minEndingHere[i - 1] + nums[i]);
//            // 更新最大绝对和，取当前最大和和最小和的绝对值的较大值
//            maxAbsolute = max(maxAbsolute, max(abs(maxEndingHere[i]), abs(minEndingHere[i])));
//        }
//
//        return maxAbsolute;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = { 1, -3, 2, 3, -4 };
//    int result = solution.maxAbsoluteSum(nums);
//    cout << "Maximum absolute sum of any subarray: " << result << endl;
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int num;
//
//    printf("请输入一个整数：");
//    scanf_s("%d", &num);
//
//    if (num > 0) {
//        printf("输入的数字是正数。\n");
//    }
//    else if (num < 0) {
//        printf("输入的数字是负数。\n");
//    }
//    else {
//        printf("输入的数字是零。\n");
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int choice;
//    int count = 0;
//
//    printf("请选择操作：\n");
//    printf("1. 打印 'Hello' 5 次\n");
//    printf("2. 计算 1 到 10 的和\n");
//    printf("3. 退出\n");
//
//    while (1) {
//        printf("请输入选项（1-3）：");
//        scanf_s("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            for (int i = 0; i < 5; i++) {
//                printf("Hello\n");
//            }
//            break;
//
//        case 2:
//            for (int i = 1; i <= 10; i++) {
//                count += i;
//            }
//            printf("1 到 10 的和为：%d\n", count);
//            break;
//
//        case 3:
//            printf("程序退出。\n");
//            return 0;
//
//        default:
//            printf("无效选项，请重新输入。\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int num = 42;
//    int* ptr;  // 定义一个整型指针变量
//
//    ptr = &num;  // 将指针指向 num 的地址
//
//    printf("num 的值：%d\n", num);        // 输出：num 的值：42
//    printf("ptr 存储的地址：%p\n", ptr);  // 输出：ptr 存储的地址：0x7ffee9eb59d0
//    printf("通过指针访问的值：%d\n", *ptr); // 输出：通过指针访问的值：42
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int* dynamicArray = NULL;  // 初始化为 NULL
//    int size = 5;
//
//    dynamicArray = (int*)malloc(size * sizeof(int));
//
//    if (dynamicArray != NULL) {
//        for (int i = 0; i < size; i++) {
//            dynamicArray[i] = i * 10;
//        }
//
//        for (int i = 0; i < size; i++) {
//            printf("dynamicArray[%d] = %d\n", i, dynamicArray[i]);
//        }
//
//        free(dynamicArray);
//    }
//    else {
//        printf("动态内存分配失败。\n");
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// 定义学生结构体
//struct Student {
//    char name[50];
//    int age;
//    struct Student* next;  // 指向下一个节点的指针
//};
//
//// 函数用于创建新的学生节点
//struct Student* createStudent(const char* name, int age) {
//    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
//    if (newStudent != NULL) {
//        strcpy_s(newStudent->name, name);
//        newStudent->age = age;
//        newStudent->next = NULL;
//    }
//    return newStudent;
//}
//
//// 函数用于在链表末尾插入学生节点
//void insertStudent(struct Student** head, struct Student* newStudent) {
//    if (*head == NULL) {
//        *head = newStudent;
//    }
//    else {
//        struct Student* current = *head;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = newStudent;
//    }
//}
//
//// 函数用于打印链表中的学生信息
//void printStudents(struct Student* head) {
//    struct Student* current = head;
//    while (current != NULL) {
//        printf("姓名：%s，年龄：%d\n", current->name, current->age);
//        current = current->next;
//    }
//}
//
//// 函数用于释放链表的内存
//void freeStudents(struct Student* head) {
//    struct Student* current = head;
//    while (current != NULL) {
//        struct Student* nextStudent = current->next;
//        free(current);
//        current = nextStudent;
//    }
//}
//
//int main() {
//    struct Student* studentList = NULL;
//
//    // 创建并插入学生节点
//    insertStudent(&studentList, createStudent("Alice", 20));
//    insertStudent(&studentList, createStudent("Bob", 22));
//    insertStudent(&studentList, createStudent("Charlie", 21));
//
//    // 打印学生信息
//    printf("学生信息：\n");
//    printStudents(studentList);
//
//    // 释放内存
//    freeStudents(studentList);
//
//    return 0;
//}

#include <stdio.h>
#include <string.h>

struct Book {
    char title[100] = "";
    char author[50] = "";
    int year = 0;
};

int main() {
    struct Book library[3];

    // 输入图书信息
    for (int i = 0; i < 3; i++) {
        printf("输入图书 #%d 的信息：\n", i + 1);
        printf("标题：");
        fgets(library[i].title, sizeof(library[i].title), stdin);
        library[i].title[strcspn(library[i].title, "\n")] = '\0';
        printf("作者：");
        fgets(library[i].author, sizeof(library[i].author), stdin);
        library[i].author[strcspn(library[i].author, "\n")] = '\0';
        printf("年份：");
        scanf_s("%d", &library[i].year);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}  // 读取多余的换行符
    }

    // 打印图书信息
    printf("\n图书馆中的图书信息：\n");
    for (int i = 0; i < 3; i++) {
        printf("图书 #%d：\n", i + 1);
        printf("标题：%s\n", library[i].title);
        printf("作者：%s\n", library[i].author);
        printf("年份：%d\n\n", library[i].year);
    }

    return 0;
}

