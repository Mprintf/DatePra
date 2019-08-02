#pragma once

class person{

public:
	void InitPerson(char* name, char* gender, int age);
	void PrintPerson();

private:
	char _name[20];
	char _gender[3];
	int _age;
};