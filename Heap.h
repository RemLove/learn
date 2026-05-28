#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//链表节点
typedef struct Listnode
{
	int val;
	struct Listnode* next;
}Listnode;

typedef struct MinHeap
{
	Listnode** data;//存储节点指针的数组
	int size;//有效个数
	int capacity;//堆数组容量
}MinHeap;
//堆初始化
void MinHeapInit(MinHeap* phead,int InitCapacity);


//建小根堆
void heapifySmall(int* arr, int i, int size);
// 交换数组元素
void swap(int* arr, int i, int j);
//检查堆容量是否够
void CheckHeap(MinHeap* phead);
//堆销毁
void HeapDestroy(MinHeap* phead);
//交换两个节点指针
void swap2(Listnode** a, Listnode** b);
//弹出，堆顶(小根堆，最小值)
Listnode* HeapPop(MinHeap* phead);
//加入数据
void HeapPush(MinHeap* phead, Listnode* node);
//合并k个有序链表
Listnode* MergeKLists(Listnode** arr, int k);