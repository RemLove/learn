#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAXN 10001
//存线段和线段个数
int line[MAXN][2];
int n;
//最小堆，和堆里元素个数
int heap[MAXN];
int heapSize;
//交换两个整数的值
static void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//向上调整，维持小根堆
void upAdjust(int i)
{
	while (i > 0 && heap[i] < heap[(i - 1) / 2])//孩子小
	{
		swap(&heap[i], &heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
//向下调整，维持小根堆
void downAdjust(int i)
{
	int l = i * 2 + 1;//左孩子
	while (l < heapSize)
	{
		//如果右孩子存在，并且右孩子小，min为右孩子
		int min = (l + 1 < heapSize && heap[l + 1] < heap[l]) ? (l + 1) : l;
		//较小的孩子，和当前节点比较
		min = (heap[min] < heap[i]) ? min : i;
		if (min == i)//如果当前节点就是最小
		{
			break;
		}
		//当前节点不是最小
		swap(&heap[i], &heap[min]);
		i = min;
		l = i * 2 + 1;
	}
}
//判断堆是否为空
int empty()
{
	return heapSize == 0;//为真返回1，为假返回0
}
//插入元素
void push(int x)
{
	heap[heapSize] = x;
	upAdjust(heapSize);
	heapSize++;
}
//弹出元素
void Pop()
{
	if (heapSize == 0) return;
	swap(&heap[0], &heap[heapSize - 1]);
	downAdjust(0);
	heapSize--;
}
//获取堆顶元素
int top()
{
	return heap[0];
}
//比较器
int compareLine(const void* a, const void* b)
{
	int* lineA = (int*)a;
	int* lineB = (int*)b;
	return lineA[0] - lineB[0];
}

int compute()
{
	// 1. 将所有线段按左端点排序
	qsort(line, n, sizeof(line[0]), compareLine);
	//2.初始化堆
	heapSize = 0;
	//记录重合次数
	int maxcover = 0;
	//3.如果当前线段左端点>=堆顶，弹出，放入当前线段右端点
	for (int i = 0; i < n; i++)
	{
		while (!empty() && line[i][0] >= top())
		{
			Pop();
		}
		push(line[i][1]);
		if (heapSize > maxcover)
		{
			maxcover = heapSize;
		}
	}
	return maxcover;
}