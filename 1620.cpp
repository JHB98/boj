#include <iostream>
#include <unordered_map>
#include <utility>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    string ref;
    unordered_map<int, string> map1;
    unordered_map<string, int> map2;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ref;
        map1.insert({i + 1, ref});
        map2.insert({ref, i + 1});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> ref;
        if (isdigit(ref[0]))
        {
            cout << map1.find(stoi(ref))->second << "\n";
        }
        else
        {
            cout << map2.find(ref)->second << "\n";
        }
    }
    return 0;
}