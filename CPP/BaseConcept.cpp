#include<iostream>
using namespace std;
//
////命名空间:namespace 名称{}
//namespace Test{
//	int a=10;
//	int b = 20;
//}
//
//namespace Test1{
//	int c = 30;
//	namespace Test2{
//		int d = 40;
//	}
//}
////命名空间的使用
//using namespace Test1::Test2;  //这里必须指明Test2是Test1中的成员,否则会报错
//int main(){
//	printf("%d ", Test::a);
//	cout << Test::a ;
//	return 0;
//}
//
//
//int ADD(int a = 1, int b = 1){
//	return a + b;
//}
//
//int SUB(int a, int b = 1){
//	return a - b;
//}
//
//int main(){
//	int add = ADD();
//	cout << add;
//	return 0;
//}
//
////函数重载
//int ADD(int a, int b){
//	return a + b;
//}
//
//double ADD(double a, double b){
//	return a+b;
//}
//
//int main(){
//	ADD(1, 2);
//	ADD(1.0, 2.0);
//	ADD('1','2');  //如果没有合适匹配的函数进行调用,编译器可能会尝试进行参数类型转换,如果转换成功,则按照转换的类型进行函数调用
//	return 0;
//}
//
////基于范围的for循环
//void Test(){
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for (auto e : array){
//		cout << e << endl;
//	}
//	return 0;
//}
//
//
////传值:优点:可读性强,函数的副作用不会影响外部的实参
////     缺点:传参效率低,不能通过形参改变实参
////按照值得方式传参,形参只是实参的一份拷贝,它们有着不同的内存空间
//void Swap(int left, int right){
//	int temp = left;
//	left = right;
//	right = temp;
//}
////传址:优点:传参效率高,可以通过形参改变外部的实参
////     缺点:不安全,可读性差
//void Swap(int* left, int* right){
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//
////如何通过传值的方式,可以起到交换的作用
////引用:给已存在的一个变量取的别名,共用一块地址空间
////引用的类型必须与引用的实体类型一致
//
//int main(){
//	int a = 10;
//
//	//引用必须在定义时初始化
//	int& ra = a;
//
//	//一个变量可以有多个引用
//	int& rra = a;
//
//	//引用一旦引用了一个实体,不能再引用其他实体
//	int b = 20;
//	//int& ra = b;
//
//	ra = 100;    //a=100
//	return 0;
//}
////常引用
//int main(){
//	const int a = 10;
//	//int& ra = a;     //a是常量,本语句编译时会出错
//	const int& ra = a;
//
//	return 0;
//}
//
////引用的使用场景
//做参数
//void Swap(int& left, int& right){
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main(){
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//
//	return 0;
//}
//引用作为函数返回值,一定不能返回函数栈上的空间
//返回结果的生命周期不受函数控制
int ret;
int& ADD(int a, int b){
	//return a + b;  //非常量引用的初始值必须为左值
	//int ret=(a + b);
	ret = a + b;
	return ret;
}
int main(){
	int& ret = ADD(1, 2);
	ADD(3, 4);
	printf("%d", ret);  //7
	printf("%d", ret);  //随机值,7

	return 0;
}










