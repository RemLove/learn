#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int TypedefData;
typedef struct ListNode
{
	TypedefData val;
	struct ListNode* next;

}Listnode;

//1.返回无环链表相交的第一个节点
Listnode* getIntersectionNode(Listnode* h1, Listnode* h2)
{
	Listnode* a = h1;
	Listnode* b = h2;
	//如果为空或者刚开始就相等
	if (h1==NULL||h2==NULL)
	{
		return NULL;
	}
	//看谁长，把长的走几步
	int diff = 0;
	while (a->next != NULL)
	{
		a = a->next;
		diff++;
	}
	while (b->next != NULL)
	{
		b = b->next;
		diff--;
	}
	//ab走到末尾
	if (a != b)
	{
		return NULL;
	}
	if (diff >= 0)//h1长
	{
		a = h1;
		b = h2;
	}
	else//h2长
	{
		a = h2;
		b = h1;
	}
	diff = abs(diff);
	while (diff > 0)
	{
		a = a->next;
		diff--;
	}
	//ab位置一样了
	while (a != b)
	{
		a = a->next;
		b = b->next;
	}
	return a;
}