#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��ʼ������
void Init(int arr[], int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		arr[i] = i;
	}
}
//�������
void Empty(int arr[], int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		arr[i] = 0;
	}
}
//����Ԫ������
void Reverse(int arr[], int size) {
	int i = 0;
	int tmp = 0;
	for (i = 0; i < size/2; i++) {
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - i - 1] = tmp;
	}
}
//��ӡ������Ԫ��
void Print(int arr[],int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main() {
	int A[9];
	int size = sizeof(A)/sizeof(A[0]);
	Init(A,size);
	Print(A,size);
	Reverse(A,size);
	Print(A, size);
	Empty(A, size);
	Print(A, size);
	system("pause");
	return 0;
}


