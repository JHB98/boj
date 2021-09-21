#include <iostream>
using namespace std;
int n, m, ss, sw, s, w;
char field[250][250];
bool check[250][250];
void dfs(int i, int j)
{
    int d[4] = {-1, 0, 1, 0}, ref1, ref2;
    check[i][j] = true;
    if (field[i][j] == 'v')
    {
        sw++;
    }
    if (field[i][j] == 'o')
    {
        ss++;
    }
    for (int k = 0; k < 4; k++)
    {
        ref1 = i + d[k];
        ref2 = j + d[3 - k];
        if ((ref1 >= 0) && (ref1 < n) && (ref2 >= 0) && (ref2 < m) && (!check[ref1][ref2]) && (field[ref1][ref2] != '#'))
        {
            dfs(ref1, ref2);
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> field[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((!check[i][j]) && (field[i][j] != '#'))
            {
                ss = sw = 0;
                dfs(i, j);
                if (ss > sw)
                {
                    s += ss;
                }
                else
                {
                    w += sw;
                }
            }
        }
    }
    cout << s << " " << w << "\n";
    return 0;
}