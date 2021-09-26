#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int sea[20][20], n, s = 2, cnt, ans;
bool check[20][20];
pair<int, int> shark;
struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> fish;
void bfs(pair<int, int> shark)
{
    queue<pair<int, int>> q;
    bool find = false;
    pair<int, int> ref;
    int d[4] = {-1, 0, 1, 0}, qsize, save = 0;
    check[shark.first][shark.second] = true;
    q.push(shark);
    while (!q.empty() && !find)
    {
        qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            ref = q.front();
            q.pop();
            if ((sea[ref.first][ref.second] != 9) && (sea[ref.first][ref.second] < s) && (sea[ref.first][ref.second]) > 0)
            {
                if (!find)
                {
                    find = true;
                    ans += save;
                }
                fish.push({ref.first, ref.second});
            }
            if (!find)
            {
                for (int j = 0; j < 4; j++)
                {
                    int l = ref.first + d[j];
                    int r = ref.second + d[3 - j];
                    if ((l >= 0) && (l < n) && (r >= 0) && (r < n) && (!check[l][r]) && (sea[l][r] <= s))
                    {
                        check[l][r] = true;
                        q.push({l, r});
                    }
                }
            }
        }
        save++;
    }
}
void eat()
{
    sea[shark.first][shark.second] = 0;
    shark = fish.top();
    sea[shark.first][shark.second] = 9;
    cnt++;
    if (s == cnt)
    {
        s++;
        cnt = 0;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sea[i][j];
            if (sea[i][j] == 9)
            {
                shark.first = i;
                shark.second = j;
            }
        }
    }
    while (1)
    {
        bfs(shark);
        if (fish.empty())
        {
            break;
        }
        eat();
        memset(check, false, sizeof(check));
        while (!fish.empty())
        {
            fish.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
