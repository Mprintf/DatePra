//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
//用例"(()())",6 返回true;"()a()()",7 返回false
//思路:遍历字符串,将左括号入栈,遇到右括号则看栈顶元素,栈顶元素若为左括号则出栈;遍历完字符串,若栈为空则全部匹配返回true,否则返回false

#include<iostream>
#include<stack>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> s;
		//遍历字符串
		for (auto e : A){
			if (e == '(')
				s.push(e);   //左括号入栈
			if (e == ')'){
				if (s.empty() || s.top() != '(')    //遇到右括号则看栈顶元素,栈为空或者栈顶元素不为'(',返回false
					return false;
				s.pop();                            //栈顶元素为'(',出栈
			}
		}
		if (s.empty())
			return true;
		return false;
	}
};