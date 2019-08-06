//求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//根据位运算，获取每一位的二进制值。获取第i位的值： (n >> i) & 1。如果1连续，则计数累加，如果不连续，则从0开始计数。
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