#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, ref, min, max, mid, sum, ans;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        v.push_back(ref);
    }
    cin >> m;
    sort(v.begin(), v.end());
    min = 0;
    max = v[v.size() - 1];
    while (min <= max)
    {
        sum = 0;
        mid = (min + max) / 2;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > mid)
            {
                sum += mid;
            }
            else
            {
                sum += v[i];
            }
        }
        if (sum < m)
        {
            min = mid + 1;
            ans = mid;
        }
        else if (sum > m)
        {
            max = mid - 1;
        }
        else
        {
            ans = mid;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}