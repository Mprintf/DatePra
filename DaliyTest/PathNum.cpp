//����n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ�ÿ��ֻ�������߻�������,���ܹ��ж������߷�
//�ݹ�Ľⷨ
#include<iostream>
using namespace std;

int PathNum(int m,int n){
    if(m==0||n==0)
        return 1;
    return PathNum(m-1,n)+PathNum(m,n-1);
}

int main(){
    int a,b;
    while(cin>>a>>b)
        cout<<PathNum(a,b)<<endl;
    return 0;
}

//��̬�滮�Ľⷨ
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int m, n;
	while (cin >> m >> n){
		vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){
				if (i == 0 && j == 0){
					v[i][j] = 1;
					continue;
				}
				if (i == 0)
					v[i][j] = v[i][j - 1];
				else if (j == 0)
					v[i][j] = v[i - 1][j];
				else
					v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		cout << v[n][m] << endl;
	}
	return 0;
}