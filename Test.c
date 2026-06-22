#include "Sort.h"

int main()
{
	int arr[] = { 1,2,0,5,4,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int help[100];
	//1.选择排序
	//SelectSort(arr, size);
	//2.冒泡排序
	//BubbleSort(arr, size);
	//3.插入排序
	//InsertSort(arr, size);
	//4.1归并排序（递归版）
	//MergeSort1(arr, help, 0, size - 1);
	//4.2归并排序（非递归版）
	//MergeSort2(arr, help, size);
	//5.随机快排
	//QuickSort(arr, size);
	//6.堆排
	HeapSort2(arr, size);
	print(arr, size);
}
