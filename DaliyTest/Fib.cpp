//��һ����N�������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci��
//˼·:�ҵ�����N���������Fibonacci��(һ�����,һ���ұ�),��N�����������ľ���,ȡ��Сֵ

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f<N){
			l = N - f;  //����N�������ߵ���,���������
		}
		else{
			r = f - N;  //����N������ұߵ���,���������
			break;
		}
	}
	cout << min(l, r) << endl;  //�Ƚ�l��r,ȡ�����Сֵ
	return 0;
}