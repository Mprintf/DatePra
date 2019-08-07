//有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始
//给定两个数int n和int m，同时给定int j和int i，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1
//思路：本题涉及知识点-位运算。想要把n的二进制值插入m的第j位到第i位，只需要把n先左移j位，然后再进行或运算


class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};