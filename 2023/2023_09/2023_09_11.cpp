#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 首先按照课程的截止日期排序
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
            });

        int current_time = 0;  // 当前的时间，从第1天开始
        priority_queue<int> taken_durations;  // 已选课程的持续时间（最大堆）

        for (const vector<int>& course : courses) {
            int duration = course[0];
            int end_day = course[1];

            if (current_time + duration <= end_day) {
                // 如果当前时间加上课程持续时间不超过截止日期，就选这门课
                current_time += duration;
                taken_durations.push(duration);
            }
            else if (!taken_durations.empty() && taken_durations.top() > duration) {
                // 如果已选的课程中存在持续时间更长的课程，就替换掉它
                current_time -= taken_durations.top();
                taken_durations.pop();
                current_time += duration;
                taken_durations.push(duration);
            }
        }

        return taken_durations.size();
    }
};

int main() {
    // 示例输入
    vector<vector<int>> courses = { {100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200} };

    Solution solution;
    int result = solution.scheduleCourse(courses);

    // 输出结果
    cout << "最多可以修读的课程数目：" << result << endl;

    return 0;
}
