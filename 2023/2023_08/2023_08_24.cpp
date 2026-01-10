#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_count(m, 0); // To store the count of servers in each row
        vector<int> col_count(n, 0); // To store the count of servers in each column

        // Count the servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        int totalServers = 0;

        // Count the servers that can communicate with at least one other server
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1)) {
                    totalServers++;
                }
            }
        }

        return totalServers;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = { {1, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 1, 0, 0} };
    int result = solution.countServers(grid);
    cout << "Number of servers that can communicate: " << result << endl;
    return 0;
}
