#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//选择排序
void SelectionSort(int* arr, int length)
{
	assert(arr != NULL);

	for (int i = 0; i < length - 1; i++)//为啥是length-1呢，因为剩最后一个了，自己和自己交换可以省略了
	{
		int min = i;//找最小的
		for (int j = i + 1; j < length; j++)//先指向i后面
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		//移动一轮了，换位置
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}
//打印
void SortPrint(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//冒泡排序
void BubbleSort(int* arr, int length)
{
	assert(arr);

	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length-1-i; j++)
		{
			if (arr[j] > arr[j+1])//如果大，交换
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//插入排序
void InsertSort(int* arr, int length)
{
	assert(arr);
	for (int i = 1; i < length; i++)
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
		{
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
}
//找num
int FindNum(int* arr, int num, int length)
{
	assert(arr);
	int l = 0;
	int r = length - 1;
	while (l <= r)
	{
		int mid = l + (r-l) / 2;
		if (arr[mid] > num)
		{
			r = mid - 1;
		}
		else if(arr[mid]<num)
		{
			l = mid + 1;
		}
		else//等于  找到了
		{
			return mid;
		}
	}
	return -1;//没找到
}
//有序数组中，找>=num最左的位置
int FindLeft(int* arr, int length,int num)
{
	assert(arr);
	int l = 0;
	int r = length - 1;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (arr[mid] >= num)
		{//向左继续二分
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return ans;
}
//有序数组中，找<=num最右的位置
int FindRight(int* arr, int length, int num)
{
	assert(arr);
	int l = 0;
	int r = length - 1;
	int ans = -1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] > num)
		{
			r = mid - 1;
		}
		else
		{
			ans = mid;
			l = mid + 1;
		}
	}
	//没找到
	return -1;
}
//寻找山峰
int FindPeak(int* arr, int length)
{
	assert(arr);
	if (length == 1)
	{
		return 0;
	}
	//判断0位置
	if (arr[0] > arr[1])
	{
		return 0;
	}
	//判断最后一个位置
	if (arr[length-1]>arr[length-2])
	{
		return length - 1;
	}
	//第一个位置和最后一个位置都不是山峰
	int l = 1;
	int r = length - 2;
	//int ans = -1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] > arr[mid - 1]&&arr[mid]>arr[mid+1])//中点刚好为山峰
		{
			return mid;
		}
		else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])//上升，向右边二分
		{
			l = mid + 1;
		}
		//else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])//下降，向左边二分
		//{
		//	r = mid - 1;
		//}
		else//v字型，左右二分都可以    和下降合一起了
		{
			r = mid - 1;
		}
	}
	//没找到(基本不存在)
	return -1;
}
int main()
{
	int arr[] = { 1,5,4,3,2 };
	int length = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, length);
	SortPrint(arr, length);
	return 0;
}