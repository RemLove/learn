#include "Heap.h"

// 交换数组元素
void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//建小根堆,如果当前大，和小孩子交换
void heapifySmall(int* arr, int i, int size)
{
	int l = i * 2 + 1;//左孩子
	while (l < size)//保证左孩子存在
	{
		//如果右孩子存在，并且右孩子小
		int min = ((l+1)<size && arr[l + 1] < arr[l]) ? (l + 1) : l;
	
		min = (arr[min] < arr[i]) ? min : i;
		if (min == i)
		{
			break;
		}
		//i节点不是最小
		swap(arr, i, min);
		i = min;
		l = i * 2 + 1;
	}
}

//堆初始化
void MinHeapInit(MinHeap* phead, int InitCapacity)
{
	if (InitCapacity <= 0)
	{
		InitCapacity = 4;
	}
	phead->capacity = InitCapacity;
	phead->size = 0;
	phead->data =(Listnode**) malloc(sizeof(Listnode*) * phead->capacity);
	if (phead->data == NULL)
	{
		printf("malloc fail!");
		exit(-1);
	}
}
//检查堆容量是否够
void CheckHeap(MinHeap* phead)
{
	assert(phead);

	if (phead->size == phead->capacity)
	{
		int NewCapacity = (phead->capacity) * 2;
		phead->data = (Listnode**)realloc(phead->data, sizeof(Listnode*) * NewCapacity);
		if (phead->data == NULL)
		{
			printf("realloc fail!");
			exit(-1);
		}
		phead->capacity = NewCapacity;
	}
}