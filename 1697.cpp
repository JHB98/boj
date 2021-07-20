#include <iostream>
#include <queue>
using namespace std;
bool map[100001];
int n, k;
void bfs()
{
    queue<int> q;
    int num, cnt = 0, ch1 = 1, ch2 = 0;
    map[n] = true;
    q.push(n);
    while (1)
    {
        num = q.front();
        if (num == k)
        {
            break;
        }
        q.pop();
        ch1--;
        if ((num - 1 >= 0) && (!map[num - 1]))
        {
            map[num - 1] = true;
            q.push(num - 1);
            ch2++;
        }
        if ((num + 1 <= 100000) && (!map[num + 1]))
        {
            map[num + 1] = true;
            q.push(num + 1);
            ch2++;
        }
        if ((num * 2 <= 100000) && (!map[num * 2]))
        {
            map[num * 2] = true;
            q.push(num * 2);
            ch2++;
        }
        if (!ch1)
        {
            cnt++;
            ch1 = ch2;
            ch2 = 0;
        }
    }
    cout << cnt << "\n";
}
int main()
{
    cin >> n >> k;
    bfs();
    return 0;
}
