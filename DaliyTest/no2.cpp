#include<iostream>
#include<vector>
using namespace std;
//有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//最多可以放多少块蛋糕在网格盒子里。

//问题分析:想要((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))=4
//只有0+4或4+0这两种情况符合要求,x1=x2且y2=y1+2或x2=x1+2且y1=y2
//即:
//当(x1,y1)处有蛋糕,则(x1,y1+2)和(x+2,y1)处不能放蛋糕
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