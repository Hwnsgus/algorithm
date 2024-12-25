#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

// ��� ����ü ����
typedef struct {
    int key;
} element;

// �� ����ü ����
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// �� ���� �Լ�
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

// �� �ʱ�ȭ �Լ�
void init(HeapType* h) {
    h->heap_size = 0;
}

// �ִ� ���� ��Ҹ� �����ϴ� �Լ�
void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size); // �� ũ�� ����

    // �ִ� �� �Ӽ��� �����ϱ� ���� ���� ������
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i = i / 2;
    }
    h->heap[i] = item;
}

// ���� ���� ��ȸ�� ����ϴ� �Լ�
void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

int main() {
    int input[] = { 3, 7, 10, 8, 6, 4, 15, 25 };
    int n = sizeof(input) / sizeof(input[0]);

    // �� ���� �� �ʱ�ȭ
    HeapType* heap = create();
    init(heap);

    for (int i = 0; i < n; i++) {
        element e;
        e.key = input[i];
        insert_max_heap(heap, e);
    }

    // �� ���
    printf("�ִ� ��: \n");
    print_heap(heap);

    // �Ҵ�� �޸� ����
    free(heap);
    return 0;
}
