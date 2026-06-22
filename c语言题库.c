#include"stdio.h"
#include"math.h"
//1.求圆的周长和面积
void C(float r)
{
	float pi = 3.14f;
	float c = pi * r * 2;
	printf("%.2f\n", c);
}
void S(float r)
{
	float pi = 3.14f;
	float s =pi * r * r;
	printf("%.2f\n",s);
}
//2.求一到一百的值
void test02()
{
	int nums = 0;
	for (int i = 1; i <= 100; i++)
	{
		nums += i;
	}
	printf("%d\n", nums);
}
//3.求年增长 倍数
void test03()
{
	float r = 0.07;
	int p = 1;
	for (int i = 0; i < 10; i++)
	{
		p *= (1 + r);
	}
	printf("%d ", p);
}
//4.输入两个数，输出最大
void test04(int m, int n)
{
	scanf("%d %d",&m,&n);
	if (m > n)
	{
		printf("%d\n", m);
	}
	else if(n>m)
	{
		printf("%d\n", n);
	}
	else
	{
		printf("相等");
	}
}
//5.输入两个数，输出最大公约数
void test05(int a, int b)
{
	scanf("%d %d", &a, &b);
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	printf("%dn", a);
}
//6.求斐波那契数列前20个数
void test06()
{
	int arr[20] = { 0 };
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 0; i < 20; i++)
	{
		if (i >= 2)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//7.一到一千除三余一，除五余2，除七余三，输出
void test07()
{
	for (int i = 1; i <= 1000; i++)
	{
		if (i % 3 == 1 && i % 5 == 2 && i % 7 == 3)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
//8.计算年利率
void test08()
{
	float a = 1000.00;
	float test01 = a * (1 + 0.0036);
	float test02 = a * (1 + 0.0225);
	float test03 = a * (1 + 0.0198 / 2) * (1 + 0.0198 / 2);
	printf("%.2f ", test01);
	printf("%.2f ", test02);
	printf("%.2f \n", test03);
}
//9.输入x，返回y
void test09()
{
	int x;
	scanf("%d", &x);
	if (x < 1)
	{
		printf("%d ", x);
	}
	else if (x >= 1 && x < 10)
	{
		printf("%d ", 2 * x - 1);
	}
	else
	{
		printf("%d \n", 3 * x - 11);
	}
}
//10.求方程的根
void test10()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (b * b - 4 * a * c > 0 && a != 0)
	{
		float x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		float x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("%f ,%f", x1, x2);
	}
}
//11.输入一个三位正整数，求该数字各位之和
void test11()
{
	int m;
	scanf("%d", &m);
	int a = m / 100;
	int b = m / 10 % 10;
	int c = m % 10;
	int sum = a + b + c;
	printf("%d \n", sum);
}
//12.求圆柱体表面积和体积
void test12()
{
	float r = 3.0f;
	float h = 10.0f;
	float pi = 3.14f;
	//底面积*高
	float v = (pi * r * r) * h;
	//上下两个圆面积和 侧面积（底周长*高）
	float s = 2 * (r * pi * r) + (2 * pi * r) * h;
	printf("%.2f\n", v);
	printf("%.2f\n", s);
}
//13小写转大写
void test13()
{
	char arr[11];
	scanf("%s", arr);
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] -= 32;
		}
	}
	printf("%s\n", arr);
}

//14求和
void test14()
{
	int a = 1;
	int sum = 0;
	while (a <= 112)
	{
		sum += a;
		a += 3;
	}
	printf("%d \n", sum);
}
//15.输入10个数，求最大输出
void test15()
{
	int arr[10];
	int max = arr[0];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	printf("%d\n", max);
}
//16
void test16()
{
	for (int i = 200; i <= 300; i++)
	{
		int a = i / 100;
		int b = i / 10 % 10;
		int c = i % 10;
		if (a * b * c == 42 && (a + b + c) == 12)
		{
			printf("%d\n", i);
		}
	}
}
//17求梯形面积
void test17()
{
	float a, b, h;
	scanf("%f %f %f", &a, &b, &h);
	float s = (a + b) * h / 2;
	printf("%.2f", s);
}
//18求除去最大值和最小值平均数
void test18()
{
	int arr[10] = { 0 };
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = arr[0];
	int min = arr[0];
	for (int j = 0; j < 10; j++)
	{
		if (arr[j] > max)
		{
			max = arr[j];
		}
		if (arr[j] < min)
		{
			min = arr[j];
		}
		sum += arr[j];
	}
	sum = sum - max - min;
	printf("%.2f\n", sum/8.0f);
}
//19.求能被3,5,7，同时整除的数
void test19()
{
	for (int i = 1; i <= 1000; i++)
	{
		if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
//20
void test20()
{
	int t = 560;
	int h = 560 / 60;
	int m = 560 % 60;
	printf("%d小时 %d分钟", h, m);
}