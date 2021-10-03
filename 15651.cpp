#include <iostream>
using namespace std;
int s[7], n, m;
void back(int index)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << s[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            s[index] = i;
            back(index + 1);
        }
    }
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    back(0);
    return 0;
}