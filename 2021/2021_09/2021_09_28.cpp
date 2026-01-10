#include <iostream>
using namespace std;

void funShift(int m, char* p, int n)
{
    char c;
    for (int j = 0; j < m; j++)
    {
        c = p[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            p[i] = p[i - 1];
        }
        p[0] = c;
    }
}

int main()
{
    int i, m, n;
    cin >> m >> n;
    char* p = new char[n + 1];
    p[n] = 0;
    for (i = 0; i < n; ++i)
        cin >> p[i];
    funShift(m, p, n);
    for (i = 0; i < n; ++i)
        cout << p[i] << ' ';
    cout << endl;
    delete[] p;
    return 0;
}