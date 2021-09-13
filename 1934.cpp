#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b, n, ans, d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        d = 2;
        ans = 1;
        while (d <= min(a, b))
        {
            if ((!(a % d)) && (!(b % d)))
            {
                a /= d;
                b /= d;
                ans *= d;
            }
            else
            {
                d++;
            }
        }
        cout << ans * a * b << "\n";
    }
    return 0;
}