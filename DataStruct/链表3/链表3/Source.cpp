#include <stdlib.h>
#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct Node 
{
	int value;
	Node *pNext;
}NODE,*PNODE;
PNODE create_list(void);
bool insert_list(PNODE,int ,int);
void traverse_list(PNODE);
int length_list(PNODE);
bool delete_list(PNODE,int ,int*);
void rePrint(PNODE);
int main() 
{
	int value;
	PNODE pHead;
	
	pHead=create_list();
	length_list(pHead);
	for (int i = 1; i <5;i++)
	{
		cin >> value;
		insert_list(pHead, i, value);
	}
	length_list(pHead);
	traverse_list(pHead);
	if (delete_list(pHead,3,&value))
	{
		cout << "删除的值为：" << value << endl;
		traverse_list(pHead);
	}
	insert_list(pHead,1,88);
	traverse_list(pHead);
	cout << "\n";
	rePrint(pHead);
	system("pause");
	return 0;
}

PNODE create_list(void)
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		return NULL;
	}
	pHead->pNext = NULL;
	return pHead;
}

bool insert_list(PNODE pHead,int position,int value)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p&&i < position - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i>position-1||p==NULL)
	{
		cout << "插入失败\n";
		return false;
	}
	else
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->value = value;
		PNODE q=p->pNext;
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		return true;
	}
}

void traverse_list(PNODE pHead) 
{
	if (pHead == NULL)
		return;
	PNODE p = pHead;
	while (NULL != p->pNext)
	{
		p = p->pNext;
		cout << p->value << endl;
		//p=p->pNext;
		
	}
	return;
}

int length_list(PNODE pHead) 
{
	int i = 0;
	if (pHead == NULL)
		return NULL;
	PNODE p = pHead;
	while (p->pNext!=NULL)
	{
		i++;
		p = p->pNext;
	}
	cout << "链表长度：" << i << endl;
	return i;
}

bool delete_list(PNODE pHead,int position,int *value) 
{
	int i = 0;
	if (pHead == NULL)
		return NULL;
	PNODE p = pHead;
	while (p->pNext != NULL&&i < position - 1)
	{
		p = p->pNext;
		i++;
	}
	if (NULL == p->pNext || i > position - 1)
		return false;
	else
	{
		PNODE q = p->pNext;
		p->pNext = p->pNext->pNext;
		*value = q->value;
		free(q);
		return true;
	}

}

void rePrint(PNODE pHead) 
{
		if (pHead != NULL)
		{
			rePrint(pHead->pNext);
			cout << pHead->value << endl;;
		}
	
}