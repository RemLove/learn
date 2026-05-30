#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//位运算练习2
//1.判断是不是二的幂
//思路：2的幂满足，二进制只有一个一，把最右侧1状态提取出来，看是否等于n
int PowerOfTwo(int n)
{
	if (n == (n & -n))
	{
		return n;
	}
	else
	{
		return - 1;
	}
}
//2.判断是不是三的幂
//思路：求出在int类型范围下，3的最大次幂的数，在除以3看是否能除尽
int PowerOfThree(int n)
{
	if (n>0&&1162261467 % n == 0)
	{
		return n;
	}
	else
	{
		return -1;
	}
}
//3.找大于等于n最小的2的次幂
int Near2Power(int n)
{
	if (n <= 0)
	{
		return -1;
	}
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	return n + 1;
}
//4.范围呢所有&的结果
int rangeBitwiseAnd(int left, int right)
{
	while (left < right)
	{
		right = right - (right & -right);
	}
	return right;
}
//5.逆序二进制的状态
int ReverseBits(int n)
{
	n = (n & 0xaaaaaaaa >> 1) | (n & 0x55555555 << 1);
	n = (n & 0xcccccccc >> 2) | (n & 0x33333333 << 2);
	n = (n & 0xf0f0f0f0 >> 4) | (n & 0x0f0f0f0f << 4);
	n = (n & 0xff00ff00 >> 8) | (n & 0x00ff00ff << 8);
	n = (n >> 16) | (n << 16);
	return n;
}
//位运算实现加法
int add(int a, int b)
{
	int ans = 0;
	while (b != 0)//只要进位信息不是0
	{
		ans = a ^ b;
		b = (a & b) << 1;
		a = ans;
	}
	return ans;
}
//位运算实现减法
int  minus(int a, int b)
{
	return add(a, add(~b, 1));//return add(a, add(~b, 1));
}
//位运算实现乘法
int multiply(int a, int b)
{
	int ans = 0;
	while (b != 0)
	{
		if (b & 1 != 0)
		{
			ans = add(a, ans);
		}
		b >>= 1;
		a <<= 1;
	}
	return ans;
}