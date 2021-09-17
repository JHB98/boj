#include <iostream>
using namespace std;
bool chess[14][14];
bool row[14];
int n, cnt;
bool check(pair<int, int> q)
{
    int d1[2] = {-1, -1}, d2[2] = {-1, 1}, ref1, ref2;
    if (row[q.second])
    {
        return false;
    }
    for (int i = 0; i < 2; i++)
    {
        ref1 = q.first;
        ref2 = q.second;
        while (1)
        {
            ref1 += d1[i];
            ref2 += d2[i];
            if ((ref1 >= 0) && (ref1 < n) && (ref2 >= 0) && (ref2 < n))
            {
                if (chess[ref1][ref2])
                {
                    return false;
                }
            }
            else
            {
                break;
            }
        }
    }
    return true;
}
void back(int num)
{
    if (num == n)
    {
        cnt++;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (check({num, i}))
            {
                chess[num][i] = true;
                row[i] = true;
                back(num + 1);
                chess[num][i] = false;
                row[i] = false;
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    back(0);
    cout << cnt << "\n";
    return 0;
}