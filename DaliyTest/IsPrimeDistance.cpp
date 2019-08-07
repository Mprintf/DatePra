//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，要求输出组成指定偶数的两个素数差值最小的素数对

#include<iostream>
#include<algorithm>
using namespace std;

bool IsPrime(int num){
	//只遍历到开方出不能被开方左边的数整除，则一定不能被开方右边的数整除
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
		//从中间开始找
		half = num / 2;
		for (i = half; i>0; i--){
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}