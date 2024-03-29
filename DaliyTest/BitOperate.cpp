//编写一个函数，将两个数字相加。不得使用+或其他算数运算符
//本题可以通过位运算实现，具体实现如下：
//1. 二进制位异或运算相当于对应位相加，不考虑进位
//比如： 1 ^ 1 = 0 ---> 1 + 1 = 0 (当前位值为0，进一位)
//1 ^ 0 = 1 ---> 1 + 0 = 1 (当前位值为1)
//0 ^ 0 = 0 ---> 0 + 0 = 0 (当前位值为0)
//2. 二进制位与运算相当于对应位相加之后的进位
//比如： 1 & 1 = 1 ---> 1 + 1 = 0 (当前位的值进一位)
//1 & 0 = 0 ---> 1 + 0 = 1 (当前位的值不进位)
//0 & 0 = 0 ---> 0 + 0 = 0 (当前位的值不进位)
//3. 两个数相加：对应二进制位相加的结果 + 进位的结果
//比如：3 + 2 --> 0011 + 0010 --> 0011 ^ 0010 + ((0011 & 0010) << 1)
//---> (0011 ^ 0010) ^ ((0011 & 0010) << 1)， 当进位之后的结果为0时，相加结束
class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum, carry;
		while (B != 0){
			sum = A^B;
			carry = (A&B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};