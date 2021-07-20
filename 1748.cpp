#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int len, num;
    long long ans;
    string n;
    cin >> n;
    len = n.length() - 1;
    if (len == 0)
    {
        cout << n << "\n";
        return 0;
    }
    num = stoi(n);
    ans = (num - pow(10, len) + 1) * (len + 1);
    for (int i = len; i > 0; i--)
    {
        ans += 9 * pow(10, i - 1) * i;
    }
    cout << ans << "\n";
    return 0;
}