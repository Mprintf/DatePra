//��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//����λ���㣬��ȡÿһλ�Ķ�����ֵ����ȡ��iλ��ֵ�� (n >> i) & 1�����1������������ۼӣ���������������0��ʼ������
#include<iostream>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int maxbyte = 0, count = 0;
		while (n){
			if (n & 1){
				++count;
				maxbyte = max(count, maxbyte);
			}
			else
				count = 0;
			n = n >> 1;
		}
		cout << maxbyte << endl;
	}

	return 0;
}