//求两个数a,b的最小公倍数
//最小公倍数=a*b/最大公约数(a,b)

#include<iostream>
using namespace std;
//辗转相除法求最大公约数
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