#include "Sort.h"
//传数组下标，交换数组元素
void swap(int arr[],int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
//打印数组元素
void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//1.选择排序
void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				swap(arr, i, j);
			}
		}
	}
}
//2.冒泡排序
void BubbleSort(int arr[], int size)
{
	for (int i = size-1; i >=0; i--)
	{
		for (int j = 0; j <=i; j++)
		{
			if (arr[j] > arr[i])
			{
				swap(arr, i, j);
			}
		}
	}
}
//3.插入排序
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = 0;
		int temp = arr[i];//arr[j]往后移的时候，arr[i]被覆盖了
		for ( j = i - 1; j >=0&& arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j+1] = temp;
		//print(arr, size);
	}
}
//4.归并排序（递归版）
void merge(int arr[], int help[], int l, int m, int r)
{
	int i = l;
	int a = l;
	int b = m + 1;
	while (a <= m && b <= r)
	{
		help[i++] = (arr[a] <= arr[b]) ? arr[a++] : arr[b++];
	}
	while (a <= m) help[i++] = arr[a++];
	while (b <= r) help[i++] = arr[b++];
	for (int k = l; k <= r; k++)
	{
		arr[k] = help[k];
	}
}
void MergeSortRecursive(int arr[], int help[], int l, int r)
{
	if (l == r) return;
	int m = (l + r) / 2;
	MergeSortRecursive(arr, help, l, m);
	MergeSortRecursive(arr, help, m + 1, r);
	merge(arr, help, l, m, r);
}
//5.归并排序（非递归版）
int Min(int a, int b)
{
	return a <= b ? a : b;
}
void MergeSort(int arr[], int help[], int size)
{
	for (int step = 1; step < size; step <<= 1)
	{
		int l = 0;
		while (l < size)
		{
			int m = l + step - 1;
			if (m + 1 >= size)
			{
				break;
			}
			int r = Min(m + step, size - 1);
			merge(arr, help, l, m, r);
			l = r + 1;
		}
	}
}
