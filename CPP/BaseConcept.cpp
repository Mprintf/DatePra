#include<iostream>
using namespace std;
//
////�����ռ�:namespace ����{}
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
////�����ռ��ʹ��
//using namespace Test1::Test2;  //�������ָ��Test2��Test1�еĳ�Ա,����ᱨ��
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
////��������
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
//	ADD('1','2');  //���û�к���ƥ��ĺ������е���,���������᳢ܻ�Խ��в�������ת��,���ת���ɹ�,����ת�������ͽ��к�������
//	return 0;
//}
//
////���ڷ�Χ��forѭ��
//void Test(){
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for (auto e : array){
//		cout << e << endl;
//	}
//	return 0;
//}
//
//
////��ֵ:�ŵ�:�ɶ���ǿ,�����ĸ����ò���Ӱ���ⲿ��ʵ��
////     ȱ��:����Ч�ʵ�,����ͨ���βθı�ʵ��
////����ֵ�÷�ʽ����,�β�ֻ��ʵ�ε�һ�ݿ���,�������Ų�ͬ���ڴ�ռ�
//void Swap(int left, int right){
//	int temp = left;
//	left = right;
//	right = temp;
//}
////��ַ:�ŵ�:����Ч�ʸ�,����ͨ���βθı��ⲿ��ʵ��
////     ȱ��:����ȫ,�ɶ��Բ�
//void Swap(int* left, int* right){
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//
////���ͨ����ֵ�ķ�ʽ,�����𵽽���������
////����:���Ѵ��ڵ�һ������ȡ�ı���,����һ���ַ�ռ�
////���õ����ͱ��������õ�ʵ������һ��
//
//int main(){
//	int a = 10;
//
//	//���ñ����ڶ���ʱ��ʼ��
//	int& ra = a;
//
//	//һ�����������ж������
//	int& rra = a;
//
//	//����һ��������һ��ʵ��,��������������ʵ��
//	int b = 20;
//	//int& ra = b;
//
//	ra = 100;    //a=100
//	return 0;
//}
////������
//int main(){
//	const int a = 10;
//	//int& ra = a;     //a�ǳ���,��������ʱ�����
//	const int& ra = a;
//
//	return 0;
//}
//
////���õ�ʹ�ó���
//������
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
//������Ϊ��������ֵ,һ�����ܷ��غ���ջ�ϵĿռ�
//���ؽ�����������ڲ��ܺ�������
int ret;
int& ADD(int a, int b){
	//return a + b;  //�ǳ������õĳ�ʼֵ����Ϊ��ֵ
	//int ret=(a + b);
	ret = a + b;
	return ret;
}
int main(){
	int& ret = ADD(1, 2);
	ADD(3, 4);
	printf("%d", ret);  //7
	printf("%d", ret);  //���ֵ,7

	return 0;
}










