#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n, m;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string site, password;
    map<string, string> search;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> site >> password;
        search.insert(pair<string, string>(site, password));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> site;
        cout << search.find(site)->second << '\n';
    }
    return 0;
}