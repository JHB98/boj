#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p[1001] = {0}, ans[1001] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        ans[i] = p[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            ans[i] = min(ans[i], ans[i - j] + p[j]);
        }
    }
    cout << ans[n] << "\n";
    return 0;
}