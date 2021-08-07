#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n, sum = 0;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i * (n / i);
    }
    cout << sum << "\n";
    return 0;
}