//https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//����һ���ַ�,�ж��ַ����ճ��Ȼ��ǰ����ֵ�������

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector <string> str;
	str.resize(n);
	//����vector�����ַ��Ž�vector��
	for (auto& s : str)
		cin >> s;
	bool len = true, lex = true;
	//�ж��Ƿ񰴳�������,����string��size�Ƚ��ַ�����
	for (int i = 1; i<str.size(); i++){
		if (str[i].size()<str[i - 1].size())
			len = false;
	}
	//�ж��Ƿ��ֵ�������,����string��operate>=���������,����ASCII�����Ƚ��ַ�
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