#include <iostream>
#include <deque>
using namespace std;
deque<pair<int, bool>> c;
void pop(int n)
{
    if (c[n - 1].second)
    {
        c[n - 1].second = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int stage = 1, n, k, ref, is_0 = 0;
    pair<int, bool> s;
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> ref;
        c.push_back({ref, false});
    }
    while (1)
    {
        s = c.back();
        c.pop_back();
        c.push_front(s);
        pop(n);
        for (int i = n - 2; i >= 0; i--)
        {
            if (c[i].second)
            {
                if (!c[i + 1].second && c[i + 1].first)
                {
                    c[i].second = false;
                    c[i + 1].second = true;
                    c[i + 1].first--;
                    if (!c[i + 1].first)
                    {
                        is_0++;
                    }
                }
            }
        }
        pop(n);
        if (c.front().first)
        {
            c.front().second = true;
            c.front().first--;
            if (!c.front().first)
            {
                is_0++;
            }
        }
        if (is_0 >= k)
        {
            break;
        }
        stage++;
    }
    cout << stage << "\n";
    return 0;
}