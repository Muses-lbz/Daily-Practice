#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> isConnected(n + 1, vector<bool>(n + 1, false));
        vector<int> degrees(n + 1, 0);

        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            isConnected[u][v] = isConnected[v][u] = true;
            degrees[u]++;
            degrees[v]++;
        }

        int minDegree = INT_MAX;

        for (int u = 1; u <= n; ++u) {
            for (int v = u + 1; v <= n; ++v) {
                if (isConnected[u][v]) {  // Only consider connected nodes
                    for (int w = v + 1; w <= n; ++w) {
                        if (isConnected[v][w] && isConnected[u][w]) {  // Form a trio
                            int trioDegree = degrees[u] + degrees[v] + degrees[w] - 6;  // Subtract shared edges
                            minDegree = min(minDegree, trioDegree);
                        }
                    }
                }
            }
        }

        return (minDegree == INT_MAX) ? -1 : minDegree;
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = { {1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6} };
    int result = solution.minTrioDegree(n, edges);
    cout << "Minimum degree of connective triplets: " << result << endl;
    return 0;
}
