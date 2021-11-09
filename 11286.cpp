#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
struct cmp
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
        {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int, vector<int>, cmp> q;
    int n, ref;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        if (ref)
        {
            q.push(ref);
        }
        else
        {
            if (q.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }
    return 0;
}