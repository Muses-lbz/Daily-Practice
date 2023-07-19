#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int direction = 0;

        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        int maxDistanceSq = 0;

        for (const auto& command : commands) {
            if (command == -2) {
                direction = (direction + 3) % 4;
            }
            else if (command == -1) {
                direction = (direction + 1) % 4;
            }
            else {
                for (int i = 0; i < command; i++) {
                    int nextX = x + directions[direction][0];
                    int nextY = y + directions[direction][1];
                    string nextPos = to_string(nextX) + "," + to_string(nextY);

                    if (obstacleSet.find(nextPos) != obstacleSet.end()) {
                        break;
                    }

                    x = nextX;
                    y = nextY;
                    maxDistanceSq = max(maxDistanceSq, x * x + y * y);
                }
            }
        }

        return maxDistanceSq;
    }
};

int main() {
    Solution solution;

    vector<int> commands = { 2, 1, -2, 1, 3 };
    vector<vector<int>> obstacles = { {1, 1}, {2, 2}, {3, 3}, {4, 4} };

    int maxDistanceSq = solution.robotSim(commands, obstacles);

    cout << "Max Euclidean Distance Squared: " << maxDistanceSq << endl;

    return 0;
}