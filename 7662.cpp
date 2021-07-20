#include <iostream>
#include <set>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, k, num;
    char ch;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        multiset<int> m;
        for (int j = 0; j < k; j++)
        {
            cin >> ch;
            if (ch == 'I')
            {
                cin >> num;
                m.insert(num);
            }
            else
            {
                cin >> num;
                if (!m.empty())
                {
                    if (num == 1)
                    {
                        m.erase(--m.end());
                    }
                    else
                    {
                        m.erase(m.begin());
                    }
                }
            }
        }
        if (m.empty())
        {
            cout << "EMPTY"
                 << "\n";
        }
        else
        {
            cout << *(--m.end()) << " " << *(m.begin()) << "\n";
        }
    }
    return 0;
}