#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 10

typedef struct GraphType {
	int n; //정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; // 10x10 행렬 설정
} GraphType;


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

}

void print_adj_mat(GraphType* g) {

}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g); // 그래프 초기화

	for (int i = 0; i < 4; i++)
	{
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);

	free(g);
	
}