//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������Ҫ��������ָ��ż��������������ֵ��С��������

#include<iostream>
#include<algorithm>
using namespace std;

bool IsPrime(int num){
	//ֻ���������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++){
		if ((num%i) == 0)
			return false;
	}
	return true;
}

int main(){
	int num, half, i;
	while (cin >> num){
		//���м俪ʼ��
		half = num / 2;
		for (i = half; i>0; i--){
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}