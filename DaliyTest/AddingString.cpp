//�����������ӷ�

#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

string AddingInteger(string num1, string num2){
	//�����λ��ʼ
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	string result = "";
	//��ǰλ����ӽ��
	int carry = 0;
	while (i >= 0 || j >= 0){
		if (i >= 0){
			carry += num1[i] - '0';
		}
		if (j >= 0){
			carry += num2[j] - '0';
		}
		result += (char)(carry % 10 + '0');
		//��ǰλ����н�λ���1
		carry /= 10;
		i--;
		j--;
	}
	//�����������н�λ��ӡ�1��
	if (carry == 1)
		result += '1';
	//��������string
	reverse(result.begin(), result.end());
	return result;
}


int main(){
	string str1, str2;
	while (cin >> str1 >> str2){
		cout << AddingInteger(str1, str2) << endl;
	}
	return 0;
}