#include <iostream>
#include <algorithm>
using namespace std;
int l, c, check1, check2;
char s[15], a[15];
bool check3[15];
void back(int n, int start)
{
    if ((n == l) && (check1 >= 2) && (check2 >= 1))
    {
        for (int i = 0; i < l; i++)
        {
            cout << s[i];
        }
        cout << "\n";
    }
    else
    {
        for (int i = start; i < c; i++)
        {
            if (!check3[i])
            {
                check3[i] = true;
                s[n] = a[i];
                if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                {
                    check2++;
                }
                else
                {
                    check1++;
                }
                back(n + 1, i + 1);
                check3[i] = false;
                if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                {
                    check2--;
                }
                else
                {
                    check1--;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> a[i];
    }
    sort(a, a + c);
    back(0, 0);
    return 0;
}