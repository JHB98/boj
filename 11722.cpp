#include <iostream>
#include <vector>
using namespace std;
vector<int> a, s;
int lowerBound(int key)
{
    int l = 0, h = s.size() - 1, m, ans;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (s[m] < key)
        {
            h = m - 1;
            ans = m;
        }
        else if (s[m] > key)
        {
            l = m + 1;
        }
        else
        {
            ans = m;
            break;
        }
    }
    return ans;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, ref;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        a.push_back(ref);
    }
    for (int i = 0; i < n; i++)
    {
        if ((s.empty()) || (s.back() > a[i]))
        {
            s.push_back(a[i]);
        }
        else
        {
            s[lowerBound(a[i])] = a[i];
        }
    }
    cout << s.size() << "\n";
    return 0;
}