#include <stdio.h>
//구조체- 같은 자료형이나 서로 다른 자료형에 대한 연속적인 메모리 공간
//사용자 정의 자료형
//자료형에 대한 정의, 정의문  -> 선언문(메모리 요청, 선언)

struct Sample {
	int x;
	double y;
};

int main() {
	int i = 10;// 메모리 선언(int i) + 초기화(= 10) 선언과 초기화를 동시에 함
	//struct Sample test {}; // 선언문
	//test.x = 10; //초기화
	//test.y = 3.14;

	struct Sample test ={20, 3.14}; // 선언과 초기화를 동시에 진행
	printf("%d\n", test.x);
	printf("%f\n", test.y);

	//구조체와 포인터
	//포인터 변수의 선언 ex) int *p  
	//포인터의 타입(p의 자료형?) = 주소의 자료형(struct Sample)을 따라감
	struct Sample* p;
	p = &test;

	printf("%d\n", p->x);
	printf("%f\n", p->y);

	//구조체의 크기 sizeof 함수 사용
	printf("%zu\n", sizeof(int)); // 4 출력
	printf("%zu\n", sizeof(i)); // 4 출력
	printf("%zu\n", sizeof(test)); // 사용하는 메모리는 12(int 4, double 8)이지만 16 출력 int를 8바이트 할당하도록 함

}