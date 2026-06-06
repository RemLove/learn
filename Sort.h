#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
//传数组下标，交换数组元素
void swap(int arr[], int a, int b);
//打印数组元素
void print(int arr[], int size);
//1.选择排序
void SelectionSort(int arr[], int size);
//2.冒泡排序
void BubbleSort(int arr[], int size);
//3.插入排序
void InsertSort(int arr[], int size);
//4.归并排序（递归版）
void MergeSortRecursive(int arr[], int help[], int l, int r);
//5.归并排序（非递归版）
void MergeSort(int arr[], int help[], int size);
//6.随机快排
void QuickSort(int arr[], int l, int r);
//封装一下
void Quick_Sort(int arr[], int size);
//7.堆排序(封装好的)
//从上往下建堆
void heapSort1(int arr[],int size);
//从下往上建堆
void heapSort2(int arr[],int size);