//��������a,b����С������
//��С������=a*b/���Լ��(a,b)

#include<iostream>
using namespace std;
//շת����������Լ��
int gcd(int a, int b){
	int r;
	while (r = a%b){
		a = b;
		b = r;
	}
	return b;
}

int main(){
	int a, b;
	while (cin >> a >> b){
		int c = a*b / gcd(a, b);
		cout << c << endl;
	}
	return 0;
}