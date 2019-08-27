//https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//��֪һ�������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����
//���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��
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