#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int dp[100000][2], num[100000], n, ans;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    ans = dp[0][0] = num[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + num[i], num[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + num[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << "\n";
    return 0;
}