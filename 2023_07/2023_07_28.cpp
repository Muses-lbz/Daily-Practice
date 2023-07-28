#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        vector<int> inDegree(n + 1, 0);
        vector<int> earliestTime(n + 1, 0);

        // Build the directed graph and calculate the in-degrees of each course
        for (const auto& relation : relations) {
            int prevCourse = relation[0];
            int nextCourse = relation[1];
            graph[prevCourse].push_back(nextCourse);
            inDegree[nextCourse]++;
        }

        queue<int> q;

        // Find courses without prerequisites (in-degree is 0) and add them to the queue
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                earliestTime[i] = time[i - 1];
            }
        }

        // Perform topological sorting
        while (!q.empty()) {
            int currentCourse = q.front();
            q.pop();

            for (int nextCourse : graph[currentCourse]) {
                inDegree[nextCourse]--;
                earliestTime[nextCourse] = max(earliestTime[nextCourse], earliestTime[currentCourse] + time[nextCourse - 1]);
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Find the maximum earliestTime which represents the minimum time required to finish all courses
        int minTime = *max_element(earliestTime.begin(), earliestTime.end());
        return minTime;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> relations = { {2, 1}, {3, 1}, {4, 1}, {4, 3}, {5, 3} };
    vector<int> time = { 2, 4, 1, 3, 2 };

    Solution solution;
    int minTime = solution.minimumTime(n, relations, time);

    cout << "Minimum time required to finish all courses: " << minTime << " months" << endl;

    return 0;
}
