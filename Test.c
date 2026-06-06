#include "Sort.h"

int main()
{
	int arr[] = { 1,2,0,5,4,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//1.选择排序
	//SelectionSort(arr, size);
	//2.冒泡排序
	BubbleSort(arr, size);
	//3.插入排序
	//InsertSort(arr, size);
	//4.归并排序(递归版)
	int help[100];
	//MergeSortRecursive(arr, help, 0, size-1);
	//5.归并排序（非递归版）
	//MergeSort(arr, help, size);
	//6.随机快排
	//Quick_Sort(arr, size);
	print(arr, size);
}
