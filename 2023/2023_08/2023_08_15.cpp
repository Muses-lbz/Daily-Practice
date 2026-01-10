//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//	string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
//		int n = s.size();
//		vector<pair<int, int>> sortedIndices; // Pair of (original index, replacement index)
//
//		// Create pairs of (original index, replacement index) and sort them in descending order
//		for (int i = 0; i < indices.size(); ++i) {
//			sortedIndices.push_back({ indices[i], i });
//		}
//		sort(sortedIndices.rbegin(), sortedIndices.rend());
//
//		// Perform replacements
//		for (auto& pair : sortedIndices) {
//			int origIndex = pair.first;
//			int sourceIndex = pair.second;
//			string source = sources[sourceIndex];
//			string target = targets[sourceIndex];
//
//			// Check if the substring at origIndex matches the source string
//			if (s.substr(origIndex, source.size()) == source) {
//				// Replace the matched substring with the target string
//				s.replace(origIndex, source.size(), target);
//			}
//		}
//
//		return s;
//	}
//};
//
//int main() {
//	Solution solution;
//
//	string s = "abcd";
//	vector<int> indices = { 0 };
//	vector<string> sources = { "ab" };
//	vector<string> targets = { "eee" };
//
//	string result = solution.findReplaceString(s, indices, sources, targets);
//	cout << "Result: " << result << endl;
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<pair<int, int>> sortedIndices; // 存储 (原始索引, 替换索引) 的向量

        // 创建 (原始索引, 替换索引) 的对，并按原始索引降序排序
        for (int i = 0; i < indices.size(); ++i) {
            sortedIndices.push_back({ indices[i], i });
        }
        sort(sortedIndices.rbegin(), sortedIndices.rend());

        // 执行替换操作
        for (auto& pair : sortedIndices) {
            int origIndex = pair.first; // 原始索引
            int sourceIndex = pair.second; // 替换索引
            string source = sources[sourceIndex]; // 源子字符串
            string target = targets[sourceIndex]; // 目标子字符串

            // 检查原始字符串中 origIndex 处的子字符串是否与 source 匹配
            if (s.substr(origIndex, source.size()) == source) {
                // 将匹配的子字符串替换为目标子字符串
                s.replace(origIndex, source.size(), target);
            }
        }

        return s;
    }
};

int main() {
    Solution solution;

    string s = "abcd";
    vector<int> indices = { 0 };
    vector<string> sources = { "ab" };
    vector<string> targets = { "eee" };

    string result = solution.findReplaceString(s, indices, sources, targets);
    cout << "Result: " << result << endl;

    return 0;
}
