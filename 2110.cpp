#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, c, l = 1, m, h, a = 0, ref, cnt, pre;
    vector<int> x;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        x.push_back(ref);
    }
    sort(x.begin(), x.end());
    h = x.back() - x.front();
    while (l <= h)
    {
        cnt = 1;
        pre = x[0];
        m = (l + h) / 2;
        for (int i = 1; i < n; i++)
        {
            if (x[i] - pre >= m)
            {
                cnt++;
                pre = x[i];
            }
        }
        if (cnt >= c)
        {
            a = max(a, m);
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    cout << a << "\n";
    return 0;
}