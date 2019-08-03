//https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//给出一组字符,判断字符按照长度还是按照字典序排列

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector <string> str;
	str.resize(n);
	//遍历vector并将字符放进vector中
	for (auto& s : str)
		cin >> s;
	bool len = true, lex = true;
	//判断是否按长度排列,利用string的size比较字符长度
	for (int i = 1; i<str.size(); i++){
		if (str[i].size()<str[i - 1].size())
			len = false;
	}
	//判断是否按字典序排列,利用string的operate>=运算符重载,按照ASCII码来比较字符
	for (int i = 1; i<str.size(); i++){
		if (str[i - 1]>str[i])
			lex = false;
	}

	if (len&&lex)
		cout << "both" << endl;
	else if (len&&!lex)
		cout << "lengths" << endl;
	else if (!len&&lex)
		cout << "lexicographically" << endl;
	else if (!len&&!lex)
		cout << "none" << endl;

	return 0;

}