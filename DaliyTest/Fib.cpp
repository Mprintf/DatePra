//给一个数N，让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数
//思路:找到距离N最近的两个Fibonacci数(一个左边,一个右边),求N到这两个数的距离,取较小值

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
			l = N - f;  //找离N最近的左边的数,并算出距离
		}
		else{
			r = f - N;  //找离N最近的右边的数,并算出距离
			break;
		}
	}
	cout << min(l, r) << endl;  //比较l和r,取距离较小值
	return 0;
}