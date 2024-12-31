#include <stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 5
#define TRUE =1


int visited[MAX_VERTICES];

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g) {
	g->n = 0; // 주소 값 g가 가르키는 n에 0을 대입
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("그래프 정점의 개수 초과\n");
		return;
	}
	g->n++;
}


void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = TRUE;
	printf("정점 %d ->", v);
	for (w = g->adj_list[v];  w; w = w->link)
	{
		if (!visited[w->vertex])
		{
			dfs_list(g, w->vertex);
		}
	}
}



int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	init(g);

	for (int i = 0; i < 5; i++)
	{
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	insert_edge(g, 2, 4);
	insert_edge(g, 4, 2);

	dfs_list(g, 0);
	free(g);
}