
#include "Heap.h"
#define MAX 501
//归并过程,把两个有序的子数组合并成一个有序的大数组
int arr[MAX];
int help[MAX];
int n;
void Merge(int l,int m,int r)
{
	int i = l;
	int j = m + 1;
	int k = l;
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			help[k++] = arr[i++];
		}
		else
		{
			help[k++] = arr[j++];
		}
	}
	//有一个已经为空了
	while(i<=m) help[k++] = arr[i++];
	while (j <= r) help[k++] = arr[j++];
	for (int p = l; p <= r; p++)
	{
		arr[p] = help[p];
		
	}
}
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
//归并排序 递归版
void MergeSort(int l, int r)
{
	if (l == r)
	{
		return;
	}
	int m = (l + r) / 2;
	MergeSort(l, m);
	MergeSort(m + 1, r);
	Merge(l, m, r);
}
//归并排序，非递归
void MergeSort2()
{
	for (int step = 1; step < n; step <<= 1)
	{
		int l = 0;
		int m;
		int r;
		while (l < n)
		{
			m = l + step - 1;
			if (m + 1 >= n)//右边为空
			{
				break;
			}
			//右边不为空
			//分为右边完全和不完全两种情况
			if (m + 1 + step - 1 >= n)
			{
				r = n - 1;
			}
			else//右边完全
			{
				r = m + 1 + step - 1;
			}
			Merge(l, m, r);
			l = r + 1;//移动到下一组
		}
	}
}
//经典 partition
int  partition1(int l, int r, int x)
{
	int a = l;
	int xi = 0;
	for (int i = l; i <= r; i++)
	{
		if (arr[i]<x)
		{
			swap(arr,a, i);
			if (arr[a] == arr[i])
			{
				xi = i;
			}
			a++;
		}
	}
	//i走到r的位置了，走到尽头了
	swap(arr,xi, a - 1);
	return a - 1;
}
//优化partition,荷兰国旗问题
int first;
int last;
void partition(int l, int r, int x)
{
	first = l;
	last = r;
	for (int i = l; i <= last; i++)
	{
		if ( arr[i]<x)
		{
			swap(arr,first, i);
			first++;
		}
		else if (arr[i] > x)
		{
			swap(arr,last, i);
			last--;
			i--;
		}

	}
}
//随机快排
void quickSort(int l, int r)
{
	if (l == r)
	{
		return;
	}
	int x = arr[l + rand() % (r - l + 1)];
	int mid = partition1(l, r, x);
	quickSort(l, mid - 1);
	quickSort(mid + 1, r);
}
//随机选择算法，返回下标i的元素
int randomizedSelect(int l, int r, int i)
{
	int ans = 0;
	while (l <= r)
	{
		int randIdx = l + rand() % (r - l + 1);
		int point = arr[randIdx];
		partition(l, r, point);
		if (i<first)
		{
			r = first - 1;
		}
		else if (i > last)
		{
			l = last + 1;
		}
		else //命中
		{
			ans = arr[i]; break;
		}
	}
	return ans;
}
//向上调整(用于从顶向低建堆)
void heapIsert(int* arr, int i)
{
	while (arr[i] > arr[(i - 1) / 2])//只要当前节点大于父节点
	{
		swap(arr,i, (i - 1) / 2);
		i = (i - 1) / 2;
	}

}
//向下调整(用于从低向顶建堆)
void heapifyHigh(int*arr,int i,int size)
{
	int l = (i * 2) + 1;//左孩子
	while (l < size)//保证有左孩子
	{
		//如果右孩子存在并且右孩子大       =r  否则=l
		int max = (l+1<size && arr[l+1]>arr[l]) ? l+1 : l;
		//再比较当前节点和大的孩子
		max = (arr[i] > arr[max]) ? i : max;
		if (max == i)
		{
			break;
		}
		//如果max不是当前节点i
		swap(arr,i, max);//i和max节点的值交换
		i = max;//看是否还需要再向下调整
		l= (i * 2) + 1;
	}
}
//堆排序1，从上到下建堆+排序
void heapSort1(int* arr, int n)
{
	for (int i = 0; i < n; i++)//从低到顶建堆
	{
		heapifySmall(arr, i, n);
	}
	//排序
	int size = n;
	while (size > 1)
	{
		swap(arr,0, n);
		n--;
		heapifySmall(arr, 0, n);
	}
}
//堆排序2，从下到上建堆+排序
void heapSort2(int* arr, int n)
{
	for (int i = n-1; i >=0; i--)
	{
		heapifySmall(arr, i, n);
	}
	int size = n;
	while (size > 1)
	{
		swap(arr,size, 0);
		size--;
		heapifySmall(arr, 0, n);
	}
}
int main()
{
	int sum = 0;

	for (int i = 0; i < 100; i++, i++)
	{
		sum++;
		printf("%d \n", sum);
	}
	return 0;
}


