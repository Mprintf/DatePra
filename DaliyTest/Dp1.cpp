#include<iostream>
#include<vector>
using namespace std;

//һ�������� N ��Ԫ�أ������������������
//���͵�DP����
//״̬����:F(i)=max(F(i-1)+A(i),A(i))
int main(){
	int size;
	cin >> size;
	vector<int> nums(size);

	for (int i = 0; i<size; i++){
		cin >> nums[i];
	}
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i<nums.size(); i++){
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2>result)
			result = sum2;
		if (sum2<0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	return 0;
}