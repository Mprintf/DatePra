//输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
//请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR
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
			//将两手牌分开
			string str1 = line.substr(0, dash);
			string str2 = line.substr(dash + 1);
			//获取牌的张数（空格的数量）
			int num1 = count(str1.begin(), str1.end(), ' ');
			int num2 = count(str2.begin(), str2.end(), ' ');
			//拿到第一张牌
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