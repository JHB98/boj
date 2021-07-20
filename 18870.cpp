#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int compare(const void *num1, const void *num2);
vector<int> num;
vector<int> sorted;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, low, high, mid, index = 0, refNum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> refNum;
        num.push_back(refNum);
    }
    sorted = num;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    while (index < n)
    {
        low = 0, high = sorted.size() - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (sorted[mid] < num[index])
            {
                low = mid + 1;
            }
            else if (sorted[mid] > num[index])
            {
                high = mid - 1;
            }
            else
            {
                break;
            }
        }
        cout << mid << ' ';
        index++;
    }
    cout << '\n';
    return 0;
}