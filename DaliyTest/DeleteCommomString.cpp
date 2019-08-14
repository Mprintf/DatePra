//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 0; i<str2.size(); i++){
		int index;
		//find返回值为size_type;当查找不到目标时,返回值为 npos, 可以这样判断
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
	//使用哈希表将str2中的字符映射到哈希表中相应的位置，并统计出现的次数
	int hashtable[256] = { 0 };
	for (int i = 0; i<str2.size(); i++){
		hashtable[str2[i]]++;
	}
	//遍历str1中的字符，在哈希表中对应的位置如果为0，则表示不是公共字符，添加到要返回的字符串中
	for (int i = 0; i<str1.size(); i++){
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;
	return 0;
}