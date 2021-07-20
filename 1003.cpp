#include <iostream>
using namespace std;
pair<int, int> memo[41];
pair<int, int> fibo(int n)
{
    pair<int, int> p, r;
    if ((memo[n].first == 0) && (memo[n].second == 0))
    {
        p = fibo(n - 1);
        r = fibo(n - 2);
        memo[n].first = p.first + r.first;
        memo[n].second = p.second + r.second;
    }
    return memo[n];
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n;
    pair<int, int> p;
    cin >> t;
    memo[0].first = memo[1].second = 1;
    memo[0].second = memo[1].first = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        p = fibo(n);
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}