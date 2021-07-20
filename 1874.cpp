#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	int n, ref, num = 1;
	stack<int> s;
	vector<int> v;
	vector<char> cv;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> ref;
		v.push_back(ref);
	}

	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			if (((s.empty()) && (num <= v[i])) || (s.top() < v[i]))
			{
				s.push(num++);
				cv.push_back('+');
			}
			else if (s.top() == v[i])
			{
				s.pop();
				cv.push_back('-');
				break;
			}
			else
			{
				cout << "NO" << "\n";
				return 0;
			}
		}
	}
	for (int i = 0; i < cv.size(); i++)
	{
		cout << cv[i] << "\n";
	}
	return 0;
}