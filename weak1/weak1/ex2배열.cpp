#include<stdio.h>
//�迭 - ���� �������� �������� ���տ� ���� �޸�

int main() {
	int arr[] = { 10, 20, 30 };
	printf("%p\n", arr);// �ּҸ� ���� ,%d�� ���ڿ��� ��´�
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