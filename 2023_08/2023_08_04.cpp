#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_i, start_j, end_i, end_j;
        int emptyCount = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
                else if (grid[i][j] == 2) {
                    end_i = i;
                    end_j = j;
                }
                else if (grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }

        int pathCount = 0;
        dfs(grid, start_i, start_j, end_i, end_j, emptyCount + 1, pathCount);
        return pathCount;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, int end_i, int end_j, int remainingCount, int& pathCount) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) {
            return;
        }

        if (i == end_i && j == end_j) {
            if (remainingCount == 0) {
                pathCount++;
            }
            return;
        }

        int original = grid[i][j];
        grid[i][j] = -1;

        dfs(grid, i + 1, j, end_i, end_j, remainingCount - 1, pathCount);
        dfs(grid, i - 1, j, end_i, end_j, remainingCount - 1, pathCount);
        dfs(grid, i, j + 1, end_i, end_j, remainingCount - 1, pathCount);
        dfs(grid, i, j - 1, end_i, end_j, remainingCount - 1, pathCount);

        grid[i][j] = original;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    int paths = solution.uniquePathsIII(grid);
    cout << "Number of unique paths: " << paths << endl;

    return 0;
}
