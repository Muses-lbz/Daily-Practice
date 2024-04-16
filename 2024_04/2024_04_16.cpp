//#include <iostream>
//#include <random>
//#include <vector>
//#include <algorithm>
//
//std::vector<int> generateRandomNumbers(int M) {
//    std::random_device rd; // 获取随机种子
//    std::mt19937 gen(rd()); // 使用 Mersenne Twister 引擎
//    std::uniform_int_distribution<> dis(1, M); // 均匀分布的随机数生成器
//
//    std::vector<int> numbers;
//    // 生成M个随机数
//    for (int i = 0; i < 9; ++i) {
//        numbers.push_back(dis(gen));
//    }
//
//    // 为了保证不重复，我们将向量排序并删除重复元素
//    std::sort(numbers.begin(), numbers.end());
//    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
//
//    // 如果生成的数字不够9个，则继续生成直到满足条件
//    while (numbers.size() < 9) {
//        int new_number = dis(gen);
//        if (std::find(numbers.begin(), numbers.end(), new_number) == numbers.end()) {
//            numbers.push_back(new_number);
//        }
//    }
//
//    // 对生成的数字按顺序排序
//    std::sort(numbers.begin(), numbers.end());
//
//    return numbers;
//}
//
//int main() {
//    int M;
//    std::cout << "请输入数字M：";
//    std::cin >> M;
//
//    if (M <= 8) {
//        std::cerr << "输入的数字必须大于8。" << std::endl;
//        return 1;
//    }
//
//    std::vector<int> randomNumbers = generateRandomNumbers(M);
//
//    std::cout << "随机生成的9个数字按顺序输出为：";
//    for (int num : randomNumbers) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = (int)graph.size();
        vector<int> ids(n); // 用于标识每个节点所属的连通分量
        unordered_map<int, int> id_to_size; // 记录每个连通分量的大小
        int id = 0;

        // BFS遍历每个节点，标记连通分量并计算大小
        for (int i = 0; i < n; ++i) {
            if (!ids[i]) {
                ++id;
                int size = 1;
                queue<int> q;
                q.push(i);
                ids[i] = id;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v = 0; v < n; ++v) {
                        if (!ids[v] && graph[u][v] == 1) {
                            ++size;
                            q.push(v);
                            ids[v] = id;
                        }
                    }
                }
                id_to_size[id] = size;
            }
        }

        unordered_map<int, int> id_to_initials; // 记录每个连通分量中初始感染节点的数量
        for (int u : initial) {
            ++id_to_initials[ids[u]];
        }

        int ans = n + 1, ans_removed = 0;
        // 遍历初始感染节点列表，选择能够最小化感染节点数量的节点
        for (int u : initial) {
            int removed = (id_to_initials[ids[u]] == 1 ? id_to_size[ids[u]] : 0);
            if (removed > ans_removed || (removed == ans_removed && u < ans)) {
                ans = u;
                ans_removed = removed;
            }
        }

        return ans;
    }
};

int main() {
    // 测试用例
    vector<vector<int>> graph = { {1, 0, 0, 0},
                                  {0, 1, 0, 0},
                                  {0, 0, 1, 1},
                                  {0, 0, 1, 1} };
    vector<int> initial = { 3, 1 };

    Solution solution;
    int result = solution.minMalwareSpread(graph, initial);

    cout << "移除的节点索引：" << result << endl;

    return 0;
}
