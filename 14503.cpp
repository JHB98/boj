#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool map[50][50] = {false};
    bool check[50][50] = {false};
    int n, m, d, ref1, ref2, ans = 0, r[4] = {-1, 0, 1, 0}, choice, cnt;
    pair<int, int> s;
    cin >> n >> m >> s.first >> s.second >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ref1;
            if (ref1)
            {
                map[i][j] = true;
            }
        }
    }
    while (1)
    {
        check[s.first][s.second] = true;
        cnt = 0;
        ans++;
        while (1)
        {
            switch (d)
            {
            case 1:
                choice = 0;
                break;
            case 2:
                choice = 1;
                break;
            case 3:
                choice = 2;
                break;
            case 0:
                choice = 3;
                break;
            }
            ref1 = s.first + r[choice];
            ref2 = s.second + r[3 - choice];
            if ((ref1 >= 0) && (ref1 < n) && (ref2 >= 0) && (ref2 < m) && (!map[ref1][ref2]) && (!check[ref1][ref2]))
            {
                if ((--d) < 0)
                {
                    d = 3;
                }
                s.first = ref1;
                s.second = ref2;
                break;
            }
            else
            {
                cnt++;
                if ((--d) < 0)
                {
                    d = 3;
                }
                if (cnt == 4)
                {
                    switch (d)
                    {
                    case 1:
                        choice = 3;
                        break;
                    case 2:
                        choice = 0;
                        break;
                    case 3:
                        choice = 1;
                        break;
                    case 0:
                        choice = 2;
                        break;
                    }
                    ref1 = s.first + r[choice];
                    ref2 = s.second + r[3 - choice];
                    if ((ref1 < 0) || (ref1 >= n) || (ref2 < 0) || (ref2 >= m) || (map[ref1][ref2]))
                    {
                        cout << ans << "\n";
                        return 0;
                    }
                    s.first = ref1;
                    s.second = ref2;
                    cnt = 0;
                }
            }
        }
    }
    return 0;
}