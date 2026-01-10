#include <iostream>
#include <vector>

using namespace std;

class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        this->lockNodeUser = vector<int>(n, -1);
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            int p = parent[i];
            if (p != -1) {
                children[p].emplace_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (lockNodeUser[num] == -1) {
            lockNodeUser[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (lockNodeUser[num] == user) {
            lockNodeUser[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        bool res = lockNodeUser[num] == -1 \
            && !hasLockedAncestor(num) \
            && checkAndUnlockDescendant(num);
        if (res) {
            lockNodeUser[num] = user;
        }
        return res;
    }

    bool hasLockedAncestor(int num) {
        num = parent[num];
        while (num != -1) {
            if (lockNodeUser[num] != -1) {
                return true;
            }
            num = parent[num];
        }
        return false;
    }

    bool checkAndUnlockDescendant(int num) {
        bool res = lockNodeUser[num] != -1;
        lockNodeUser[num] = -1;
        for (int child : children[num]) {
            res |= checkAndUnlockDescendant(child);
        }
        return res;
    }

private:
    vector<int> parent;
    vector<int> lockNodeUser;
    vector<vector<int>> children;
};

int main() {
    vector<int> parent = { -1, 0, 0, 1, 1, 2, 2 };
    LockingTree lockingTree(parent);

    cout << lockingTree.lock(2, 2) << endl;    // 返回 true
    cout << lockingTree.unlock(2, 3) << endl;  // 返回 false
    cout << lockingTree.unlock(2, 2) << endl;  // 返回 true
    cout << lockingTree.lock(4, 5) << endl;    // 返回 true
    cout << lockingTree.upgrade(0, 1) << endl; // 返回 true
    cout << lockingTree.lock(0, 1) << endl;    // 返回 false

    return 0;
}
