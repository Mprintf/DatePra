#include<iostream>
#include<string>
using namespace std;

//将字符串B插入到字符串A中,判断组成的字符串是否形成回文串,最后返回形成回文串插入方法的种类数
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