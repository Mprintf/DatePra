//https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//已知一个三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int m, n;
	while (cin >> n){
		m = 2 * n - 1;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = 1;
		for (int i = 0; i<n; i++){
			dp[i][0] = dp[i][2 * i] = 1;
			for (int j = 1; j<2 * i; j++){
				if (j == 1)
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
		int k;
		for (k = 0; k<m; k++){
			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0){
				cout << k + 1 << endl;
				break;
			}
		}
		if (k == m){
			cout << -1 << endl;
		}
	}
	return 0;
}