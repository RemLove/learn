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
		for (int j = 0; j <i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr, j+1, j);
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
//6.随机快排
int first = 0;//等于  x   的最左边
int last = 0;//等于  x   的最右边
//荷兰国旗问题核心逻辑
void partition(int arr[], int l, int r, int x)
{
	first = l;
	last = r;
	int i = l;
	while (i <= last)
	{
		if (arr[i]<x)
		{
			swap(arr, first, i);
			first++;
			i++;
		}
		else if (arr[i]==x)
		{
			i++;
		}
		else//>x
		{
			swap(arr, i, last);
			last--;
		}
	}
}
void QuickSort(int arr[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int randIdx = l + rand() % (r - l + 1);
	int x = arr[randIdx];
	partition(arr, l, r, x);
	QuickSort(arr, l, first-1);
	QuickSort(arr, last + 1, r);
}
//封装一下
void Quick_Sort(int arr[], int size)
{
	//初始化随机种子
	srand((unsigned)time(NULL));
	QuickSort(arr, 0, size - 1);
}
//7.堆排序
//#1. arr[i]=x   x是新来的数，向上调整（大根堆），直到不比他的父亲大或者到达0位置停止
void heapIsert(int arr[], int i)
{
	while (arr[i] > arr[(i - 1) / 2])//只要大于父节点
	{
		swap(arr, i, (i - 1) / 2);
		i = (i - 1) / 2;
	}
}

//#2. i位置的数改变了，又要维持大根堆，向下调整大根堆，数组长度是size
void heapify(int arr[],int size, int i)
{
	int l = i * 2 + 1;
	while (l < size)//保证左孩子存在
	{
		//右孩子存在且大于左孩子，best等于右孩子，否则等于左孩子
		int best = (l + 1 < size && arr[l + 1] > arr[l]) ? l + 1 : l;
		//比较较大的孩子和当前节点哪个大
		best = arr[i] > arr[best] ? i : best;
		//如果当前节点就是最大的
		if (best == i)
		{
			break;
		}
		//当前节点不是最大的
		swap(arr, i, best);
		i = best;
		l = i * 2 + 1;
	}
}
//#1.堆排序，从上往下建堆   就是把数组建成完全二叉树
void heapSort1(int arr[],int size)
{
	//从上往下建堆
	for (int i = 0; i < size; i++)
	{
		heapIsert(arr, i);
	}
	int last = size;
	while (last)
	{
		swap(arr, last-1, 0);
		last--;
		heapify(arr, last, 0);
	}
}
//#2.堆排序，从下往上建堆
void heapSort2(int arr[], int size)
{
	int n = size;
	for (int i = size - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	while (n)
	{
		swap(arr, n-1, 0);
		n--;
		heapify(arr, n, 0);
	}
}
