#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* ���Ѵ� (������ ���� ���) */

typedef struct GraphType
{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

// �׷��� ����ü
int choose(int distance[], int n, int found[]) // ���� ����� ��� ���� �Լ�
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (int i = 0; i < n; i++)
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(GraphType *g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");

	for (int i = 0; i < g->n; i++)
	{
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" found: ");

	for (int i = 0; i < g->n; i++)
	{
		printf("%2d", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType *g, int start)
{
	// �ʱ�ȭ
	for (int i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i]; // ���� �������� �� ���������� �ʱ� �Ÿ�
		found[i] = FALSE;                 // ��� ������ �湮���� ���� ���·� �ʱ�ȭ
	}
	found[start] = TRUE; // ���� ������ �湮�ߴٰ� ǥ��
	distance[start] = 0; // ���� ������ �Ÿ��� 0

	// n-1�� �ݺ� (��� ������ �� ���� ó��)
	for (int i = 0; i < g->n - 1; i++)
	{
		print_status(g); // ���� ���
		int u = choose(distance, g->n, found); // ���� ����� ��� ����
		found[u] = TRUE; // ������ ��带 �湮 ó��

		// ���õ� ��带 ���� �ٸ� ���� ���� ��� �˻�
		for (int w = 0; w < g->n; w++)
			if (!found[w]) // �湮���� ���� ��忡 ����
				if (distance[u] + g->weight[u][w] < distance[w]) // �� ª�� ��� �߰� �� ������Ʈ
					distance[w] = distance[u] + g->weight[u][w];
	}
}


int main(void)
{
	GraphType g = {7,
				   {{0, 7, INF, INF, 3, 10, INF},
					{7, 0, 4, 10, 2, 6, INF},
					{INF, 4, 0, 2, INF, INF, INF},
					{INF, 10, 2, 0, 11, 9, 4},
					{3, 2, INF, 11, 0, INF, 5},
					{10, 6, INF, 9, INF, 0, INF},
					{INF, INF, INF, 4, 5, INF, 0}}};
	shortest_path(&g, 0);
	return 0;
}