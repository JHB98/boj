#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, dp[10001] = {0}, g[10001] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
    }
    dp[1] = g[1];
    dp[2] = g[1] + g[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(max(dp[i - 3] + g[i - 1], dp[i - 2]) + g[i], dp[i - 1]);
    }
    cout << dp[n] << "\n";
    return 0;
}