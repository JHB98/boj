#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int K, N, M, num, print, size, cnt, popcnt, ref, refsize;
	bool check;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		queue<int> q;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			q.push(num);
		}
		popcnt = 0;
		while (!q.empty())
		{
			refsize = q.size() - 1;
			check = true;
			print = q.front();
			q.pop();
			cnt = 1;
			size = q.size();
			for (int i = 0; i < size; i++)
			{
				if (print < q.front())
				{
					for (int h = 0; h < refsize; h++)
					{
						ref = q.front();
						q.pop();
						q.push(ref);
					}
					q.push(print);
					if (cnt == M + 1)
					{
						M = q.size() - 1;
					}
					else
					{
						M--;
					}
					check = false;
					break;
				}
				else
				{
					ref = q.front();
					q.pop();
					q.push(ref);
					refsize--;
				}
			}
			if (check)
			{
				popcnt++;
				if (M == 0)
				{
					cout << popcnt << '\n';
					break;
				}
				else
				{
					M--;
				}
			}
		}
	}

	return 0;
}