#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
typedef struct
{
	int x;
	int y;
}Point;
int compare(const void* point1, const void* point2);
int main()
{
	int N;
	Point* point;
	scanf("%d", &N);
	point = (Point*)malloc(sizeof(Point) * N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &point[i].x, &point[i].y);
	}

	qsort(point, N, sizeof(Point), compare);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", point[i].x, point[i].y);
	}

	return 0;
}
int compare(const void* point1, const void* point2)
{
	if (((Point*)point1)->y > ((Point*)point2)->y)
	{
		return 1;
	}

	else if (((Point*)point1)->y < ((Point*)point2)->y)
	{
		return -1;
	}

	else
	{
		if (((Point*)point1)->x > ((Point*)point2)->x)
		{
			return 1;
		}

		else if (((Point*)point1)->x < ((Point*)point2)->x)
		{
			return -1;
		}
	}
}