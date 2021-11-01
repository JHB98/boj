#include <iostream>
#define MAX 1000001
using namespace std;
long long int d[MAX], s[MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n;
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; i * j < MAX; j++)
        {
            s[i * j] += i;
        }
    }
    for (int i = 1; i < MAX; i++)
    {
        d[i] = d[i - 1] + s[i];
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << d[n] << "\n";
    }
    return 0;
}