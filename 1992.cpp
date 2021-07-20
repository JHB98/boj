#include <iostream>
using namespace std;
bool map[64][64];
void ans(int x, int y, int size)
{
    bool check = false;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (map[x][y] != map[i][j])
            {
                check = true;
                break;
            }
        }
    }
    if (check)
    {
        cout << "(";
        ans(x, y, size / 2);
        ans(x, y + size / 2, size / 2);
        ans(x + size / 2, y, size / 2);
        ans(x + size / 2, y + size / 2, size / 2);
        cout << ")";
    }
    else
    {
        cout << map[x][y];
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    char ref;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ref;
            if (ref == '1')
            {
                map[i][j] = true;
            }
            else
            {
                map[i][j] = false;
            }
        }
    }
    ans(0, 0, n);
    cout << "\n";
    return 0;
}