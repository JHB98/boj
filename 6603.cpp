#include <iostream>
#include <vector>
using namespace std;
vector<int> n;
int print[6], cnt;
void back(int j)
{
    print[cnt++] = n[j];
    if (print[5])
    {
        for (int i = 0; i < 6; i++)
        {
            cout << print[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = j + 1; i < n.size(); i++)
        {
            back(i);
        }
    }
    print[--cnt] = 0;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int k, ref;
    while (1)
    {
        cin >> k;
        if (!k)
        {
            break;
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                cin >> ref;
                n.push_back(ref);
            }
            for (int i = 0; i <= k - 6; i++)
            {
                back(i);
            }
            n.clear();
            cout << "\n";
        }
    }
    return 0;
}