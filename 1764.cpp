#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, cnt = 0, min, mid, max;
    vector<string> str, ans;
    vector<string>::iterator iter;
    string ref;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        str.push_back(ref);
    }
    sort(str.begin(), str.end());
    for (int i = 0; i < m; i++)
    {
        cin >> ref;
        min = 0;
        max = str.size() - 1;
        while (min <= max)
        {
            mid = (min + max) / 2;
            if (str[mid] > ref)
            {
                max = mid - 1;
            }
            else if (str[mid] < ref)
            {
                min = mid + 1;
            }
            else
            {
                ans.push_back(ref);
                cnt++;
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << "\n";
    for (iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << *iter << "\n";
    }
    return 0;
}