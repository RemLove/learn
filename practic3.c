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
//2.按组反转链表
//判断够不够k个，如果够返回尾节点，不够返回NULL
Listnode* End(Listnode* phead, int k)
{
	Listnode* head = phead;
	while (k-1 > 0)
	{
		//不足k个
		if (phead == NULL)
		{
			return NULL;
		}
		phead = phead->next;
		k--;
	}
	return phead;
}
//反转s到e内的所有节点，返回新头节点
void Reverse(Listnode* s, Listnode* e)
{
	assert(s && e);
	Listnode* NextGroup = e->next;//下一组的头
	Listnode* pcur = s->next;
	Listnode* pre = s;//记录头
	Listnode* next = s->next;
	//找到e节点
	while (pcur != e)
	{
		pcur = pcur->next;
		next->next = pre;
		pre = next;
		next = pcur;
	}
	s->next = NextGroup;
	pcur->next = pre;//上一个
}

Listnode* ReverseLists(Listnode* head, int k)
{
	//如果链表为空或者k==1
	if (head == NULL || k == 1)
	{
		return head;
	}
	//处理第一次分组
	Listnode* start = head;
	Listnode* end = End(start, k);
	if (end == NULL)
	{
		return head;
	}
	Reverse(start, end);
	head = end;
	Listnode* LastTeamEnd = start;
	while (LastTeamEnd->next != NULL)
	{
		start = LastTeamEnd->next;
		end = End(start, k);
		if (end == NULL)
		{
			return head;
		}
		Reverse(start, end);
		LastTeamEnd->next = end;
		LastTeamEnd = start;

	}
	return head;
}
//3.复制带随机指针的链表
typedef struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
}Node;
Node* copyRandomList(Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//1->1'->2->2'->3->3'->null
	Node* pcur = head;
	Node* next = NULL;
	while (pcur != NULL)
	{
		next = pcur->next;
		//创建新节点
		Node* copy = (Node*)malloc(sizeof(Node));
		//初始化
		copy->val = pcur->val;
		copy->random = NULL;
		copy->next = NULL;
		//连接新节点和老节点
		copy->next = next;
		pcur->next = copy;
		//往下走
		pcur = next;
	}
	//设置random
	Node* cur = head;
	while (cur != NULL)
	{
		next = cur->next->next;
		Node* copy = cur->next;
		
		if (cur->random != NULL)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = next;
	}
	//分离新老链表
	Node* ans = head->next;
	cur = head;
	while (cur != NULL)
	{
		next = cur->next->next;
		Node* copy = cur->next;
		//连接老链表
		cur->next = next;
		if (next)
		{
			copy->next = next->next;
		}
		else
		{
			copy->next = NULL;
		}
		cur = next;
	}
	return ans;
}
//4.判断链表是否是回文结构,是回文结构返回1，否则返回0
int  Code04_PalindromeLinkedList(Listnode* head)
{
	if (head==NULL||head->next == NULL)
	{
		return 1;
	}
	//1.slow到中点
	Listnode* slow = head;
	Listnode* fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	//2.反转后面链表
	Listnode* pre = slow;
	Listnode* cur = slow->next;
	Listnode* next = NULL;
	slow->next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	//3.开始对比
	int ans = 1;
	Listnode* left = head;
	Listnode* right = pre;
	while (left && right)
	{
		if (left->val != right->val)
		{
			ans = 0;
			break;
		}
		left = left->next;
		right = right->next;
	}
	//4.复原链表
	cur = pre->next;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return ans;

}
// 5.寻找链表环的入口节点，无环返回 NULL
Listnode* detectCycle(Listnode* head)
{
	//小于三个不可能是环
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return NULL;
	}
	Listnode* slow = head->next;
	Listnode* fast = head->next->next;
	while (slow != fast)
	{
		if (fast->next == NULL || fast->next->next == NULL)
		{
			return NULL;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	//第一次已经相遇了
	fast = head;
	while (slow != fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	//第二次已经相遇了
	return fast;
}
//6.返回有序链表
Listnode* start = NULL;
Listnode* end = NULL;
Listnode* FindEnd(Listnode* s, int k)
{
	while (s->next != NULL && --k != 0)
	{
		s = s->next;
	}
	return s;
}
//归并排序merge
void Merge(Listnode* l1, Listnode* r1, Listnode* l2, Listnode* r2)
{
	Listnode* pre = NULL;
	//判断第一次
	if (l1->val <= l2->val)
	{
		start = l1;
		pre = l1;
		l1 = l1->next;
	}
	else
	{
		start = l2;
		pre = l2;
		l2 = l2->next;
	}
	//处理后续,双指针归并
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			pre->next = l1;
			pre = l1;
			l1 = l1->next;
		}
		else
		{
			pre->next = l2;
			pre = l2;
			l2 = l2->next;
		}
	}
	if (l1 != NULL)
	{
		pre->next = l1;
		end = r1;
	}
	else
	{
		pre->next = l2;
		end = r2;
	}
}
Listnode* sortList(Listnode* head)
{
	Listnode* l1, * r1, * l2, * r2, * next, * LastTeamEnd;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	//看看链表的长度，方便写步长
	int n = 0;
	Listnode* cur = head;
	while (cur)
	{
		cur = cur->next;
		n++;
	}
	for (int step = 1; step < n; step <<= 1)
	{
		//先处理第一组
		l1 = head;
		r1 = FindEnd(l1, step);
		l2 = r1->next;
		r2 = FindEnd(l2, step);

		next = r2->next;
		r1->next = NULL;
		r2->next = NULL;
		Merge(l1, r1, l2, r2);
		head = start;
		LastTeamEnd = end;
		while (next)
		{
			l1 = next;
			r1 = FindEnd(l1, step);
			l2 = r1->next;
			if (l2 == NULL)
			{
				LastTeamEnd->next = l1;
				break;
			}
			r2 = FindEnd(l2, step);
			next = r2->next;
			r1->next = NULL;
			r2->next = NULL;
			Merge(l1, r1, l2, r2);
			LastTeamEnd->next = start;
			LastTeamEnd = end;
		}
	}
	return head;
}