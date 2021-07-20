#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	int N, number;
	char order[100];
	queue<int> q;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> order;

		if (!strcmp(order, "push"))
		{
			cin >> number;
			q.push(number);
		}

		else if (!strcmp(order, "pop"))
		{
			if (q.size() == 0)
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (!strcmp(order, "size"))
		{
			cout << q.size() << endl;
		}

		else if (!strcmp(order, "empty"))
		{
			if (q.empty())
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}

		else if (!strcmp(order, "front"))
		{
			if (q.empty())
			{
				cout << "-1" << endl;
			}
			else 
			{
				cout << q.front() << endl;
			}
		}

		else if (!strcmp(order, "back"))
		{
			if (q.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << q.back() << endl;
			}
		}
	}

	return 0;
}