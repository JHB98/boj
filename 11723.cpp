#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int m, num;
    bitset<20> bit;
    string com;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> com;
        if (!com.compare("add"))
        {
            cin >> num;
            bit.set(num - 1, true);
        }
        else if (!com.compare("remove"))
        {
            cin >> num;
            bit.set(num - 1, false);
        }
        else if (!com.compare("check"))
        {
            cin >> num;
            if (bit.test(num - 1))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (!com.compare("toggle"))
        {
            cin >> num;
            bit.flip(num - 1);
        }
        else if (!com.compare("all"))
        {
            bit.set();
        }
        else //empty
        {
            bit.reset();
        }
    }
    return 0;
}