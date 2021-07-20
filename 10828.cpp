#include <stdio.h>
#include <stack>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	stack<int> stack1;
	char order[100];
	int N, ref;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", order);
		if (!strcmp(order, "push"))
		{
			scanf("%d", &ref);
			stack1.push(ref);
		}
		else if (!strcmp(order, "pop"))
		{
			if (stack1.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", stack1.top());
				stack1.pop();
			}
		}
		else if (!strcmp(order, "size"))
		{
			printf("%d\n", stack1.size());
		}
		else if (!strcmp(order, "empty"))
		{
			if (stack1.empty())
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			if (stack1.empty())
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", stack1.top());
			}
		}
	}
	return 0;
}