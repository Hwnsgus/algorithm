#include<stdio.h>
#include <malloc.h>
#include<stdlib.h>
#define MAX_ELEMENT 10

/*
* 스택: 가장 최근에 들어온 데이터
* 큐: 가장 먼저 들어온(가장 오래된) 데이터
* 우선순위 큐: 우선 순위를 정하여 데이터를 저장
* 이진트리 - 자식의 개수가 둘 또는 하나 인 트리
* 완전이진트리 자식 노드의 순서가 오른쪽 왼쪽 순으로 내려가는 트리 배열이 비지 않음
* 우선순위 MAX heap -> 최대값을 부모 노드로 설정, 기입되는 데이터를 순차적으로 자식 노드와 부모 노드의 크기를 비교하여 노드의 순서를 정한다.
* 부모 노드의 주소를 찾으려면 첫 순서 자식 노드에서 /2 
* 
* 과제: 8개 값을 배열에 넣기 -> 연습장
*/

typedef struct {
	int key;
}element;

//typedef 자료형을 통일 -> HeapType 이라는 자료형으로 지정
typedef struct { 
	element heap[MAX_ELEMENT]; // heap에 int의 정수 자료형 저장
	int heap_size;
} HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType)); //메모리의 주소 값을 리턴하는 타입에 반환
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) { //HeapTyipe 은 배열, 포인터 사용 element 는 int 자료형
	int i;
	i = ++(h->heap_size);

	//완전이진트리의 로직
	while ((i != 1) && item.key > h->heap[i / 2].key) {//i/2 => 부모노드의 주소 a.key 들어온 자식 노드의 값과 i/2로 나온 부모 노드의 크기를 비교, 반복문 사용
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item; // 반복문이 끝나고 부모 노드가 트리에 대입됨
}

void delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];//h->heap_size = h가 가리키는 heap의 사이즈, 배열의 마지막 데이터
	
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child< h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) child++;
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child]; // temp 아래로 내려감

		parent = child;
		child = child * 2;
		
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element tmp = { 40 };
	element e4;
	HeapType* heap;

	heap = create();  //메모리할당

	//초기화 init
	init(heap);

	//힙에 데이터추가
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, tmp);
	
	//힙의 삭제, 1번 인덱스 값 인출
	e4 = delete_max_heap(heap);
	printf("%d\n", e4.key);

	free(heap);
	return 0;
}