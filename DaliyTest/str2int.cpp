//将一个字符串转换成一个整数的功能，
//但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0。
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int symbol = 1;//用来记录符号,默认为正数
		//负数
		if (str[0] == '-'){
			symbol = -1;
			str[0] = '0';
		}
		//正数
		else if (str[0] == '+'){
			str[0] = '0';
		}
		//'123'-> 
		//sum=0
		//sum=sum*10+str[0]=1
		//sum=sum*10+str[1]=12
		//sum=sum*10+str[2]=123
		int sum = 0;
		for (int i = 0; i<str.size(); i++){
			if (str[i]<'0' || str[i]>'9'){
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol*sum;
	}
};