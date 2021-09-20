#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans[8], input[8];
bool check[8];
void back(int num)
{
    int save = 0;
    if (num == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if ((!check[i]) && (save != input[i]))
            {
                save = input[i];
                check[i] = true;
                ans[num] = input[i];
                back(num + 1);
                check[i] = false;
                ans[num] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);
    back(0);
    return 0;
}