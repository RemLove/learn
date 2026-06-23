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
//21.三位数求各位数字之和
void test21()
{
	int m;
	scanf("%d", &m);
	int a = m / 100;
	int b = m / 10 % 10;
	int c = m % 10;
	int sum = a + b + c;
	printf("%d\n", sum);
}
//22
void test22()
{
	float sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += (1.0 / i);
	}
	printf("%.4f\n", sum);
}
//23水仙花
void test23()
{
	for (int i = 100; i <= 999; i++)
	{
		int a = i / 100;//百位
		int b = i / 10 % 10;//十位
		int c = i % 10;//个位
		int sum = a * a * a + b * b * b + c * c * c;
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
}
//24小写字母转大写字母
void test24()
{
	char m;
	scanf("%c", &m);
	m -= 32;
	printf("%c\n", m);
}
//25排序
void test25()
{
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &arr[i]);
	}
	//冒泡              n-1
	for (int i = 0; i < 4-1; i++)
	{
		for (int j = 0; j < 4-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	//输出
	for (int m = 0; m < 4; m++)
	{
		printf("%d ", arr[m]);
	}
	printf("\n");
}
//26.求圆周率前五位
void test26()
{
	float a = 355.0;
	float b = 113.0;
	printf("%.5f\n", a / b);
}
//27.输入x输出y
void test27()
{
	int x;
	int y;
	scanf("%d", &x);
	if (x < 0)
	{
		y = -1;
	}
	else if (x == 0)
	{
		y = 0;
	}
	else
	{
		y = 1;
	}
	printf("%d\n", y);
}
//28.求最小公倍数
void test28()
{
	int a;
	int b;
	scanf("%d %d", &a, &b);
	int m = a;
	int n = b;
	int temp;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	int c = m * n / a;
	printf("%d\n", c);
}
//29.输入十个数，求最大值
void test29()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	//冒泡
	for (int i = 0; i < 10-1; i++)
	{
		for (int j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("%d\n", arr[9]);
}
//30输入英文字母，输出ASCII编码值
void test30()
{
	char a;
	scanf("%c", &a);
	printf("%d\n", a);
}
//31.输入票数，输出金额
void test31()
{
	int a = 25;
	int b = 20;
	int m;
	int sum;
	scanf("%d", &m);
	if (m < 30)
	{
		 sum = a * m;
	}
	else
	{
		sum = b * m;
	}
	printf("%d", sum);
}
//32
void test32()
{
	for (int i = 200; i <= 300; i++)
	{
		int a = i / 100;
		int b = i / 10 % 10;
		int c = i % 10;
		if (a * b * c == 36)
		{
			printf("%d", i);
		}
	}
}
//33.输入字符串，统计个数
void test33()
{
	char arr[1000];
	scanf("%s", arr);
	int sum = 0;
	while (arr[sum] != '\0')
	{
		sum++;
	}
	printf("%d\n", sum);
}
//34计算两个数和差积商
void test34()
{
	float m, n;
	scanf("%f %f", &m, &n);
	float a = m + n;
	float b = m - n;
	float c = m * n;
	float d = m / n;
	printf("%.2f %.2f %.2f %.2f\n", a, b, c, d);
}
//35输入一个五位数，倒序输出各个位数字
void test35()
{
	int m;
	scanf("%d", &m);
	int a = m / 10000;//万
	int b = m / 1000 % 10;//千
	int c = m / 100 % 10;//百12345
	int d = m / 10%10;//十12345
	int f = m % 10;//个
	printf("%d\n", f);
	printf("%d\n", d);
	printf("%d\n", c);
	printf("%d\n", b);
	printf("%d\n", a);
}
//36.求n的阶乘
void test36()
{
	int n;
	long long sum = 1;
	scanf("%d", &n);
	while (n != 1)
	{
		sum *= n;
		n--;
	}
	printf("%lld\n", sum);
}
//37
void test37()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	int sum = 0;
	for (int j = 0; j < 5; j++)
	{
		if (j % 2 == 0)
		{
			sum += arr[j];
		}
	}
	printf("%d\n", sum);
}
//38.输入两个数求平方和
void test38()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a * a + b * b;
	printf("%d\n", sum);
}
//39.分段函数，输入x输出y
void test39()
{
	int x,y;
	scanf("%d", &x);
	if (x > 0)
	{
		y = 18;
	}
	else if (x == 0)
	{
		y = 0;
	}
	else
	{
		y = -10;
	}
	printf("%d\n", y);
}
//40.输入三个数，找最大值
void test40()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int max = a;
	max = (max > b) ? max : b;
	max = (max > c) ? max : c;
	printf("%d\n", max);
}
//41.输入10个数，逆序打印
void test41()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int j = 9; j >= 0; j--)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}
//42.转换摄氏度
void test42()
{
	int f;
	scanf("%d", &f);
	float c = 5.0 / 9 * (f - 32);
	printf("%.2f", c);
}
//43.输入三个数从小到大输出
void test43()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int a, b, c;
	//a最大
	a = (x > y) ? x : y;
	a = (a > z) ? a : z;
	//c最小
	c = (x < y) ? x : y;
	c = (c < z) ? c : z;
	//b中
	b = x + y + z - a - c;
	printf("%d %d %d\n", a, b, c);
}
//44.求600-800奇数和
void test44()
{
	int sum = 0;
	for (int i = 600; i <= 800; i++)
	{
		if (i % 2 != 0)
		{
			sum += i;
		}
	}
	printf("%d\n", sum);
}
//45.输入10个数，去掉最大的，求其余九个数的平均数
void test45()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	float sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum += arr[i];
	}
	printf("%.2f\n", sum / 9);
}
//46.输入三个数，计算和和平均数
void test46()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int sum = a + b + c;
	float p = sum / 3.0;
	printf("%d %.2f", sum, p);
}
//47.求一天有多少分钟
void test47()
{
	int sum = 24 * 60 ;
	printf("%d\n", sum);
}
//48.合并字符串
void test48()
{
	char arr[100];
	char brr[100];
	scanf("%s %s", arr, brr);
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	int j = 0;
	while (brr[j] != '\0')
	{
		arr[i] = brr[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	printf("%s\n", arr);
}
//49
//50.