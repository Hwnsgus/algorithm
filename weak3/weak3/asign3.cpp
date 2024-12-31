#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        printf("오류: 최대 정점 개수를 초과했습니다.\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        printf("정점 %d: ", i);
        GraphNode* p = g->adj_list[i];
        while (p != NULL) {
            printf("%d -> ", p->vertex);
            p = p->link;
        }
        printf("NULL\n");
    }
}

void compute_in_out_degree(GraphType* g, int in_degree[], int out_degree[]) {
    for (int i = 0; i < g->n; i++) {
        in_degree[i] = 0;
        out_degree[i] = 0;
    }

    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        while (p != NULL) {
            out_degree[i]++;
            in_degree[p->vertex]++;
            p = p->link;
        }
    }
}

int main() {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    // 5개의 정점을 가지는 그래프 예제
    for (int i = 0; i < 5; i++) {
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 1, 3);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 4);

    printf("인접 리스트:\n");
    print_adj_list(g);

    int in_degree[MAX_VERTICES], out_degree[MAX_VERTICES];
    compute_in_out_degree(g, in_degree, out_degree);

    printf("\n진입 차수 및 진출 차수:\n");
    for (int i = 0; i < g->n; i++) {
        printf("정점 %d: 진입 차수 = %d, 진출 차수 = %d\n", i, in_degree[i], out_degree[i]);
    }

    free(g);
    return 0;
}
