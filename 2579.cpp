#include <iostream>
#include <vector>
using namespace std;
vector<int> st = {0};
int ans[301];
int dp(int n)
{
    if (n == 0)
    {
        return ans[n];
    }
    else if (ans[n])
    {
        return ans[n];
    }
    else
    {
        ans[n] = max(dp(n - 3) + st[n - 1], dp(n - 2)) + st[n];
        return ans[n];
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, ref;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        st.push_back(ref);
    }
    ans[1] = st[1];
    ans[2] = st[1] + st[2];
    cout << dp(n) << "\n";
    return 0;
}