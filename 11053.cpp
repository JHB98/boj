#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a, s;
int main()
{
    int n, ref;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        a.push_back(ref);
    }
    for (int i = 0; i < n; i++)
    {
        if (s.empty() || (a[i] > s.back()))
        {
            s.push_back(a[i]);
        }
        else
        {
            s[lower_bound(s.begin(), s.end(), a[i]) - s.begin()] = a[i];
        }
    }
    cout << s.size() << "\n";
    return 0;
}