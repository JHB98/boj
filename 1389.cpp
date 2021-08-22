#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, a, b, sum, min = 10000, ans;
    cin >> n >> m;
    int price[n][n];
    memset(price, 10000, sizeof(price));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        price[a - 1][b - 1] = price[b - 1][a - 1] = 1;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            price[i][i] = 0;
            for (int j = 0; j < n; j++)
            {
                if (price[i][j] > price[i][k] + price[k][j])
                {
                    price[i][j] = price[i][k] + price[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += price[i][j];
        }
        if (sum < min)
        {
            min = sum;
            ans = i + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}