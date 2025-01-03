#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10

typedef struct GraphType {
	int n; //정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; // 10x10 행렬 설정
} GraphType;

int visited[MAX_VERTICES];

void init(GraphType*g) {
	
	g->n = 0;
	for (int r = 0; r < MAX_VERTICES; r++)
	{
		for (int c = 0; c < MAX_VERTICES; c++)
		{
			g->adj_mat[r][c] = 0;
		}
	}
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n)+1)>MAX_VERTICES)
	{
		printf("error: 정점의 개수 초과\n");
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start>=g->n|| end >= g->n){
		printf("그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("%2d", g->adj_mat[i][j]);
		}
		printf("\n");
	}

}

void dfs_mat(GraphType* g, int v) {
	visited[v]=TRUE;
	printf("정점 %d ->",v);
	
	for (int w = 0; w < g->n; w++){
		if (g->adj_mat[v][w]==1 && !visited[w]){
			dfs_mat(g, w);
		}
	}

}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g); // 그래프 초기화

	for (int i = 0; i < 5; i++)
	{
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 4);
	print_adj_mat(g);

	dfs_mat(g, 0);

	//정점을 입력 받아 차수를 구하는 함수 getGreed

	free(g);
	
}