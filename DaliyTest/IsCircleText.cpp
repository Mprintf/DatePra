#include<iostream>
#include<string>
using namespace std;

//���ַ���B���뵽�ַ���A��,�ж���ɵ��ַ����Ƿ��γɻ��Ĵ�,��󷵻��γɻ��Ĵ����뷽����������
bool IsCircleText(string str){
	int begin = 0;
	int end = str.size() - 1;
	while (begin<end){
		if (str[begin] != str[end]){
			return false;
		}
		else{
			begin++;
			end--;
		}
	}
	return true;
}


int main(){
	string str1, str2, temp;
	int count = 0;
	cin >> str1 >> str2;
	for (int i = 0; i <= str1.size(); i++){
		temp = str1;
		temp.insert(i, str2);
		if (IsCircleText(temp))
			count++;
	}
	cout << count << endl;
	return 0;
}