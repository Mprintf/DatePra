//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i<str2.size(); i++){
		int index;
		//find����ֵΪsize_type;�����Ҳ���Ŀ��ʱ,����ֵΪ npos, ���������ж�
		while ((index = str1.find(str2[i])) != string::npos){
			str1.erase(index, 1);
		}
	}
	cout << str1 << endl;
	return 0;
}

int main(){
	string str1, str2, ret;
	getline(cin, str1);
	getline(cin, str2);
	//ʹ�ù�ϣ��str2�е��ַ�ӳ�䵽��ϣ������Ӧ��λ�ã���ͳ�Ƴ��ֵĴ���
	int hashtable[256] = { 0 };
	for (int i = 0; i<str2.size(); i++){
		hashtable[str2[i]]++;
	}
	//����str1�е��ַ����ڹ�ϣ���ж�Ӧ��λ�����Ϊ0�����ʾ���ǹ����ַ�����ӵ�Ҫ���ص��ַ�����
	for (int i = 0; i<str1.size(); i++){
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;
	return 0;
}