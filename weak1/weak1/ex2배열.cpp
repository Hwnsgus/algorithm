#include<stdio.h>
//배열 - 같은 데이터의 연속적인 집합에 대한 메모리

int main() {
	int arr[] = { 10, 20, 30 };
	printf("%p\n", arr);// 주소를 찍음 ,%d는 문자열을 찍는다
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[1]);
	printf("%p\n", &arr[2]);

	int* p = arr;
	printf("%d\n", *p);
	printf("%d\n", *(p+1));
	printf("%d\n", *(p+2));

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", *(p + i));
	}
}