#include <iostream>
using namespace std;
int n, s[8];
bool check[8];
void back(int index)
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!check[i - 1])
            {
                check[i - 1] = true;
                s[index] = i;
                back(index + 1);
                check[i - 1] = false;
                s[index] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    back(0);
    return 0;
}