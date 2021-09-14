#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n, ans, s[2][100000];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> s[j][k];
            }
        }
        ans = max(s[0][0], s[1][0]);
        for (int k = 1; k < n; k++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (k == 1)
                {
                    if (!j)
                    {
                        s[j][k] += s[j + 1][k - 1];
                    }
                    else
                    {
                        s[j][k] += s[j - 1][k - 1];
                    }
                }
                else
                {
                    if (!j)
                    {
                        s[j][k] += max({s[j + 1][k - 1], s[j + 1][k - 2], s[j][k - 2]});
                    }
                    else
                    {
                        s[j][k] += max({s[j - 1][k - 1], s[j - 1][k - 2], s[j][k - 2]});
                    }
                }
                if (s[j][k] > ans)
                {
                    ans = s[j][k];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}