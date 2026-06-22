/*#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdint.h>

#define MAXN 10001
static long long heap[MAXN];
static int size;
//交换
static void swap(int i, int j)
{
	long long temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}
//大根堆  heapify,向下
static void heapify(int i)
{
	int l = (i * 2) + 1;
	//右孩子存在，且右孩子大，
	while (l < size)
	{
		int max = ((l + 1)<size && heap[l + 1] > heap[l]) ? (l + 1) : l;
		max = (heap[max] > heap[i]) ? max : i;
		if (max == i)
		{
			break;
		}
		swap(i, max);
		i = max;
		l = i * 2 + 1;
	}
}
int halveArray(int* nums, int numsSize)
{
	size = numsSize;
	long long sum = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		heap[i] = (long long)nums[i] << 20;
		sum += heap[i];
		heapify(i);
	}
	int ans = 0;
	long long target = sum / 2;
	for (long long minus = 0; minus < target; ans++)
	{
		heap[0] /= 2;
		minus += heap[0];
		heapify(0);
	}
	return ans;
}*/