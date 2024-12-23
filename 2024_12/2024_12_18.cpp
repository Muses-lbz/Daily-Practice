#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class ExamRoom {
public:
    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if (seats.empty()) {
            // 如果没有座位被占用，学生坐在第 0 号座位
            seats.insert(0);
            return 0;
        }

        // 计算最远座位
        int maxDist = 0;
        int bestSeat = 0;

        // 考虑第一个学生坐在最左侧的情况
        auto it = seats.begin();
        int firstSeat = *it;
        maxDist = firstSeat;  // 第一个座位到座位 0 的距离
        bestSeat = 0;

        // 考虑相邻学生之间的空座位
        auto prev = it;
        it++;
        for (; it != seats.end(); ++it) {
            int currSeat = *it;
            int dist = (currSeat - *prev) / 2;  // 空座位间隔的一半
            if (dist > maxDist) {
                maxDist = dist;
                bestSeat = *prev + dist;
            }
            prev = it;
        }

        // 考虑最后一个学生坐在最右侧的情况
        int lastSeat = *prev;
        if (n - 1 - lastSeat > maxDist) {
            bestSeat = n - 1;
        }

        // 把学生安排到最佳座位
        seats.insert(bestSeat);
        return bestSeat;
    }

    void leave(int p) {
        seats.erase(p);
    }

private:
    int n;  // 总座位数
    std::set<int> seats;  // 已占座位集合
};

int main() {
    ExamRoom examRoom(10);
    std::cout << examRoom.seat() << std::endl;  // 输出 0
    std::cout << examRoom.seat() << std::endl;  // 输出 9
    std::cout << examRoom.seat() << std::endl;  // 输出 4
    std::cout << examRoom.seat() << std::endl;  // 输出 2
    examRoom.leave(4);
    std::cout << examRoom.seat() << std::endl;  // 输出 5

    return 0;
}
