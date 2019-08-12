#include<iostream>
using namespace std;


//自定义一个日期类
//创建对象的方式过于麻烦，C++中使用构造函数来解决这一问题
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


//构造函数
class Date{
	//无参构造函数
	Date(){

	}
	//带参构造函数
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
	//赋值运算符重载
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
	//调用无参构造函数
	Date d3;
	//调用带参构造函数
	Date d4(2019, 8, 12);
	Date d5(d3);
}


//析构函数
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
		if（_pData){
			free(_pData);   //释放堆上的空间
			_pData = NULL;  //将指针置为空
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	int _size;
	int _capacity;
};


