#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//初始化数组
void Init(int arr[], int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		arr[i] = i;
	}
}
//清空数组
void Empty(int arr[], int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		arr[i] = 0;
	}
}
//数组元素逆置
void Reverse(int arr[], int size) {
	int i = 0;
	int tmp = 0;
	for (i = 0; i < size/2; i++) {
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - i - 1] = tmp;
	}
}
//打印数组中元素
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


