//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
//����"(()())",6 ����true;"()a()()",7 ����false
//˼·:�����ַ���,����������ջ,������������ջ��Ԫ��,ջ��Ԫ����Ϊ���������ջ;�������ַ���,��ջΪ����ȫ��ƥ�䷵��true,���򷵻�false

#include<iostream>
#include<stack>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> s;
		//�����ַ���
		for (auto e : A){
			if (e == '(')
				s.push(e);   //��������ջ
			if (e == ')'){
				if (s.empty() || s.top() != '(')    //������������ջ��Ԫ��,ջΪ�ջ���ջ��Ԫ�ز�Ϊ'(',����false
					return false;
				s.pop();                            //ջ��Ԫ��Ϊ'(',��ջ
			}
		}
		if (s.empty())
			return true;
		return false;
	}
};