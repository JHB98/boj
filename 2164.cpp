#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int num, frontNum;
	queue<int> q;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		q.push(i);
	}
	while (1)
	{
		if (q.size() == 1)
		{
			break;
		}

		q.pop();
		frontNum = q.front();
		q.pop();
		q.push(frontNum);
	}
	cout << q.front() << endl;
	return 0;
}