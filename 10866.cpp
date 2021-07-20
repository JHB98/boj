#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
void push_front(int x);
void push_back(int x);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();
typedef struct deque
{
	int num;
	struct deque* next;
}deque;
deque *start, *end;

int main()
{
	int num, number;
	char order[100] = { 0 };
	start = (deque*)malloc(sizeof(deque));
	end = (deque*)malloc(sizeof(deque));
	start->next = end;
	end->next = start;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", order);
		if (!strcmp(order, "push_front"))
		{
			scanf("%d", &number);
			push_front(number);
		}

		else if (!strcmp(order, "push_back"))
		{
			scanf("%d", &number);
			push_back(number);
		}

		else if (!strcmp(order, "pop_front"))
		{
			printf("%d\n", pop_front());
		}

		else if (!strcmp(order, "pop_back"))
		{
			printf("%d\n", pop_back());
		}

		else if (!strcmp(order, "size"))
		{
			printf("%d\n", size());
		}

		else if (!strcmp(order, "empty"))
		{
			printf("%d\n", empty());
		}

		else if (!strcmp(order, "front"))
		{
			printf("%d\n", front());
		}

		else if (!strcmp(order, "back"))
		{
			printf("%d\n", back());
		}
	}

	return 0;
}
void push_front(int x)
{
	deque* newnode = (deque*)malloc(sizeof(deque));
	newnode->num = x;
	newnode->next = start->next;
	start->next = newnode;
	if (end->next == start)
	{
		end->next = newnode;
	}
}

void push_back(int x)
{
	deque* newnode = (deque*)malloc(sizeof(deque));
	newnode->num = x;
	newnode->next = end;
	end->next->next = newnode;
	end->next = newnode;
}

int pop_front()
{
	int retnum;
	if (start->next == end)
	{
		return -1;
	}
	deque* delnode = (deque*)malloc(sizeof(deque));
	retnum = start->next->num;
	delnode->next = start->next;
	start->next = start->next->next;
	free(delnode);
	if (start->next == end)
	{
		end->next = start;
	}
	return retnum;
}

int pop_back()
{
	int retnum;

	if (end->next == start)
	{
		return -1;
	}
	deque* delnode = (deque*)malloc(sizeof(deque));
	deque* checknode = (deque*)malloc(sizeof(deque));
	retnum = end->next->num;
	delnode->next = end->next;
	checknode = start;
	while (1)
	{
		if (checknode->next->next == end)
		{
			break;
		}
		checknode = checknode->next;
	}
	end->next = checknode;
	checknode->next = end;
	free(delnode);

	return retnum;
}

int size()
{	
	int cnt = 0;
	deque* checknode = (deque*)malloc(sizeof(deque));
	checknode = start;
	while (1)
	{
		if (checknode->next == end)
		{
			break;
		}
		checknode = checknode->next;
		cnt++;
	}
	return cnt;
}

int empty()
{	
	if (size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int front()
{
	if (empty())
	{
		return -1;
	}
	else
	{
		return start->next->num;
	}
}

int back()
{
	if (empty())
	{
		return -1;
	}
	else
	{
		return end->next->num;
	}
}