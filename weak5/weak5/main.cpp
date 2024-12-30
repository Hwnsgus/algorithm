#include <stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 5

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


int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	init(g);

	for (int i = 0; i < 4; i++)
	{
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
}