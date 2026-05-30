#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//位运算练习1
//1.用异或运算交换两数的值
void SwapExclusiveOr(int* a, int* b)
{
	*a = (*a) ^ (*b);
	*b = *a ^ *b;
	*a = *a ^ *b;
	//数组中交换，a==b时，会出错
}
//2.不用任何判断语句和比较操作，返回两个数的最大值
//反转1->0,0->1
int flip(int x)
{
	return (x ^ 1);
}
//取数字符号
int sign(int x)
{
	return flip(x >> 31);
}
//有溢出风险
int GetMaxWithoutJudge1(int a, int b)
{
	int c = a - b;
	int returnA = sign(c);//a大，c就正；a小，c就负
	int returnB = flip(returnA);
	return a * returnA + b * returnB;
}
//没有溢出风险
int GetMaxWithoutJudge2(int a, int b)
{
	int c = a - b;
	//a的符号
	int sa = sign(a);
	//b的符号
	int sb = sign(b);
	//c的符号
	int sc = sign(c);
	//判断ab符号是否相同    如果ab符号不同为1  相同为0
	int differ = sa ^ sb;
	//如果ab符号相同为1，不同为0
	int same = flip(differ);
	//两张情况return A   1.ab符号不同，a为非负(如果a是负，这时returnA为0，应返回b) 2.ab符号相同，c为非负
	int returnA = differ * sa + same * sc;
	int returnB = flip(returnA);
	return a * returnA + b * returnB;
}
//3.找到缺少的数字
int missingNumber(int arr[], int size)
{
	int all = 0;
	int has = 0;
	for (int i = 0; i < size; i++)
	{
		all ^= i;
		has ^= arr[i];
	}
	all ^= size;
	return all ^ has;
}
//4.一个数组中，其他数都出现了偶数次，只有一个数出现了奇数次，返回出现奇数次的数
int singleNumber(int arr[],int size)
{
	int x = 0;
	for (int i = 0 ; i < size; i++)
	{
		x ^= arr[i];
	}
	return x;
}
//5.找唯二出现奇数次的数
int* DoubleNumber(int arr[], int size,int brr[])
{
	int eor1 = 0;
	for (int i = 0; i < size; i++)
	{
		eor1 ^= arr[i];
	}
	//现在eor1为a^b
	//拿到1的位置
	int rightone = eor1 & (-eor1);
	int eor2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (rightone & arr[i] == 0)
		{
			eor2 ^= arr[i];
		}
	}
	brr[0] = eor2;
	brr[2] = eor1 ^ eor2;
	return brr;
}
//6.找唯一出现少于m次数的数
int find(int arr[], int n, int m)
{
	//统计各数各位置一的个数
	int conts[32] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int nums = arr[i];
		for (int j = 0; j < 32; j++)
		{
			conts[j] += (nums >> j) & 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (conts[i] % m != 0)
		{
			ans |= (1 << i);
		}
	}
	return ans;
}
int main2()
{
	int a = 1;
	int b = 2;
	SwapExclusiveOr(&a, &b);
	printf("%d \n", a);
	printf("%d \n", b);
	return 0;
}