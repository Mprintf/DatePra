#include<iostream>
using namespace std;


//�Զ���һ��������
//��������ķ�ʽ�����鷳��C++��ʹ�ù��캯���������һ����
class Date{
public:
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void Display(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main(){
	Date d1, d2;
	d1.SetDate(2019, 8, 12);
	d1.Display();
	d2.SetDate(1996, 3, 21);
	d2.Display();
	getchar();
	return 0;
}


//���캯��
class Date{
	//�޲ι��캯��
	Date(){

	}
	//���ι��캯��
	Date(int year,int month,int day){
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ���������
	Date& operate = (const Date& d){
		if (this != &d){
			_year = d.year;
			_month = d._month;
			_day = d._day;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate(){
	//�����޲ι��캯��
	Date d3;
	//���ô��ι��캯��
	Date d4(2019, 8, 12);
	Date d5(d3);
}


//��������
typeef int DataType;
class SeqList{
public:
	SeqList(int capacity = 10){
		_pData = (DataType*)malloc(capacity*sizeof(DataType));
		assert(_pData);
		_size = 0;
		_capacity = capacity;
	}
	~SeqList(){
		if��_pData){
			free(_pData);   //�ͷŶ��ϵĿռ�
			_pData = NULL;  //��ָ����Ϊ��
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	int _size;
	int _capacity;
};


