#include <iostream>
#include <stack>
#pragma warning(disable: 4996)
using namespace std;
int main()
{
	stack<int> stack;
	int K, n, sum = 0, size;
	
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> n;
		if (n == 0)
		{
			stack.pop();
		}

		else
		{
			stack.push(n);
		}
	}
	size = stack.size();
	for (int i = 0; i < size; i++)
	{
		sum += stack.top();
		stack.pop();
	}

	cout << sum << "\n";

	return 0;
}