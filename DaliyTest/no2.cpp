#include<iostream>
#include<vector>
using namespace std;
//��һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//�����ԷŶ��ٿ鵰������������

//�������:��Ҫ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))=4
//ֻ��0+4��4+0�������������Ҫ��,x1=x2��y2=y1+2��x2=x1+2��y1=y2
//��:
//��(x1,y1)���е���,��(x1,y1+2)��(x+2,y1)�����ܷŵ���
int main(){
	int w, h;
	int ret = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);
	for (int i = 0; i<w; i++){
		for (int j = 0; j<h; j++){
			if (a[i][j] == 1){
				ret++;
				if ((j + 2)<h)
					a[i][j + 2] = 0;
				if ((i + 2)<w)
					a[i + 2][j] = 0;
			}
		}
	}
	cout << ret;
	return 0;
}