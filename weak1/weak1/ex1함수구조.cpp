#include<stdio.h>

int g; // ��������

//  �Լ��� ����� ����-> �ڵ��� �ߺ��� �ٿ��ִ� ������ ����
int sum(int a) {//int a = �Ű� ����, a = ���� ����
	int tmp=0; // res �������� -> �ش� �������� Ȱ���Ѵ�
	for (int i = 0; i <= a; i++) // i = ���� ���� 
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