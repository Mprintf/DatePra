//���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
//��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string line;
	while (getline(cin, line)){
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else{
			int dash = line.find('-');
			//�������Ʒֿ�
			string str1 = line.substr(0, dash);
			string str2 = line.substr(dash + 1);
			//��ȡ�Ƶ��������ո��������
			int num1 = count(str1.begin(), str1.end(), ' ');
			int num2 = count(str2.begin(), str2.end(), ' ');
			//�õ���һ����
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (num1 == num2){
				if (str.find(first1)>str.find(first2))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else{
				if (num1 == 3)
					cout << str1 << endl;
				else if (num2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}