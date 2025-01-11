#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct GraphType
{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

// 그래프 구조체
int choose(int distance[], int n, int found[]) // 가장 가까운 노드 선택 함수
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
	// 초기화
	for (int i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i]; // 시작 정점에서 각 정점으로의 초기 거리
		found[i] = FALSE;                 // 모든 정점을 방문하지 않은 상태로 초기화
	}
	found[start] = TRUE; // 시작 정점을 방문했다고 표시
	distance[start] = 0; // 시작 정점의 거리는 0

	// n-1번 반복 (모든 정점을 한 번씩 처리)
	for (int i = 0; i < g->n - 1; i++)
	{
		print_status(g); // 상태 출력
		int u = choose(distance, g->n, found); // 가장 가까운 노드 선택
		found[u] = TRUE; // 선택한 노드를 방문 처리

		// 선택된 노드를 통해 다른 노드로 가는 경로 검사
		for (int w = 0; w < g->n; w++)
			if (!found[w]) // 방문하지 않은 노드에 대해
				if (distance[u] + g->weight[u][w] < distance[w]) // 더 짧은 경로 발견 시 업데이트
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