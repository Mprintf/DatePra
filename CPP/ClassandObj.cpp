#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "ClassandObj.h"
using namespace std;
//C�����нṹ��ֻ�ܶ������,C++��Ҳ�����������庯��
#if 0
struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s;
	s.SetStudentInfo("Peter", "��", 18);
	return 0;
}
#endif



#if 0
void person::InitPerson(char* name, char* gender, int age){
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void person::PrintPerson(){
	cout << _name << '-' << _gender << '-' << _age;
}


int main(){
	person a,b,c;
	a.InitPerson("Tom", "��", 20);
	a.PrintPerson();
	b .InitPerson("Toom", "��", 21);
	b.PrintPerson();
	c.InitPerson("Tooom", "��", 22);
	c.PrintPerson();

	return 0;
}
#endif
class A{
public:
	int ADD(int left, int right){
		return left + right;
	}
private:
	int a;
	char b;
};

class B{

};

int main(){
	cout << sizeof(A) << ' ' << sizeof(B);
	getchar();
	return 0;
}
//offsetof(�ṹ������,��Ա)   �ṹ����ĳ����Ա����ڽṹ����ʼλ�õ�ƫ����

