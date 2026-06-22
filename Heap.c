/*#include "Heap.h"

// 交换数组元素
void swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//建小根堆,如果当前大，和小孩子交换,插入堆，如果小就上浮
void heapifySmall(MinHeap* heap, int i, int size)
{
	int l = i * 2 + 1;//左孩子
	while (l < size)//保证左孩子存在
	{
		//如果右孩子存在，并且右孩子小
		int min = ((l+1)<size && heap->data[l + 1]->val < heap->data[l]->val) ? (l + 1) : l;
	
		min = (heap->data[min]->val < heap->data[i]->val) ? min : i;
		if (min == i)
		{
			break;
		}
		//i节点不是最小
		swap2(&heap->data[i],&heap->data[min]);
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
//堆销毁
void HeapDestroy(MinHeap* phead)
{
	free(phead->data);
	free(phead);
}
//交换两个节点指针
void swap2(Listnode** a, Listnode** b)
{
	Listnode* temp = *a;
	*a = *b;
	*b = temp;
}
//弹出，堆顶(小根堆，最小值)
Listnode* HeapPop(MinHeap* phead)
{
	if (phead->size == 0) return NULL;
	Listnode* top = phead->data[0];
	phead->data[0] = phead->data[phead->size - 1];
	phead->size--;
	heapifySmall(phead, 0, phead->size);
	return top;
}
//加入数据
void HeapPush(MinHeap* phead, Listnode* node)
{
	assert(node);
	CheckHeap(phead);
	int i = phead->size;
	phead->data[phead->size] = node;
	phead->size++;
	while (i>0&&phead->data[i]->val < (phead->data[(i - 1) / 2]->val))//i存在并且小
	{
		swap2(&phead->data[i], &phead->data[(i-1)/2]);
		i = (i - 1) / 2;
	}

}
//合并k个有序链表
//存放链表头节点的指针数组，k：数组长度
Listnode* MergeKLists(MinHeap*heap, Listnode** arr, int k)
{
	assert(heap);
	MinHeapInit(heap, k);
	for (int i = 0; i < k; i++)
	{
		if (arr[i] != NULL)
		{
			//如果链表头节点不为空，就压入堆中
			HeapPush(heap, arr[i]);
		}
	}
	//如果堆是空
	if (heap->size == 0)
	{
		free(heap);
		return NULL;
	}

	Listnode* head = HeapPop(heap);
	Listnode* pre = head;
	if (pre->next)
	{
		HeapPush(heap, pre->next);
	}
	while (heap->size > 0)//只要堆中有元素
	{
		Listnode* pcur = HeapPop(heap);
		pre->next = pcur;
		pre = pcur;
		if (pcur->next)
		{
			HeapPush(heap, pcur->next);
		}
	}
	free(heap->data);
	free(heap);
	return head;
}*/