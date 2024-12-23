#include<stdio.h>

int g; // 전역변수

//  함수로 만드는 과정-> 코드의 중복을 줄여주는 장점이 존재
int sum(int a) {//int a = 매개 변수, a = 지역 변수
	int tmp=0; // res 지역변수 -> 해당 블럭에서만 활용한다
	for (int i = 0; i <= a; i++) // i = 지역 변수 
	{
		tmp += i;
	}
	return tmp;
}

int main() {
	int a = sum(10);
	printf("%d", a);
	
}

/*
int main() {
	int sum;
	for (int i = 0; i <= 10; i++)
	{
		sum += i;
	}
	printf("%d", sum);
	return 0;
}
*/