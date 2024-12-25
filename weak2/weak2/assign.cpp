#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

// 요소 구조체 정의
typedef struct {
    int key;
} element;

// 힙 구조체 정의
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 힙 생성 함수
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

// 힙 초기화 함수
void init(HeapType* h) {
    h->heap_size = 0;
}

// 최대 힙에 요소를 삽입하는 함수
void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size); // 힙 크기 증가

    // 최대 힙 속성을 유지하기 위해 위로 재정렬
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i = i / 2;
    }
    h->heap[i] = item;
}

// 힙을 레벨 순회로 출력하는 함수
void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

int main() {
    int input[] = { 3, 7, 10, 8, 6, 4, 15, 25 };
    int n = sizeof(input) / sizeof(input[0]);

    // 힙 생성 및 초기화
    HeapType* heap = create();
    init(heap);

    for (int i = 0; i < n; i++) {
        element e;
        e.key = input[i];
        insert_max_heap(heap, e);
    }

    // 힙 출력
    printf("최대 힙: \n");
    print_heap(heap);

    // 할당된 메모리 해제
    free(heap);
    return 0;
}
