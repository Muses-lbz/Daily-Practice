#include <iostream>

using namespace std;

class Solution
{
public:
    int funny;
    int Printf()
    {
        cout << funny << endl;
        cout << "Hello World!" << endl;
        return 0;
    }
private:

protected:

};

int main()
{
    Solution S;
    S.funny = 1314;
    S.Printf();

    int x = 10;
    auto lambda = [x](int y) { return x + y; };
    int result = lambda(5);
    cout << result << endl;

    return 0;
}