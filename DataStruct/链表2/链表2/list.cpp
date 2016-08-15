#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct Node
{
int data;
Node *pNext;
} NODE,*PNODE;
PNODE create_list();
void traverse_list(PNODE );
int length_list(PNODE);
bool is_empty_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE ,int,int *);
int main(void)
{
	PNODE pHead;
	int value_delete;
	pHead=create_list();
	traverse_list(pHead);
	length_list(pHead);
	is_empty_list(pHead);
	insert_list(pHead,3,888);
	traverse_list(pHead);

	if(delete_list(pHead,2,&value_delete))
	{
	cout<<"删除节点的值为："<<value_delete<<endl;
	}
	//traverse_list(pHead);
	system("pause");
return 0;
}

PNODE create_list()
{
	int length,value;
PNODE pHead;
pHead=(PNODE)malloc(sizeof(NODE));
if(NULL==pHead)
{
	cout<<"动态内存分配失败"<<endl;
}
else
{
cout<<"请输入分配节点的大小：";
	cin>>length;
	PNODE pTail=pHead;
	pTail->pNext=NULL;
	for(int i=0;i<length;i++)
	{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
	cout<<"动态内存分配失败。";
	}
	else
	{
	cin>>value;
	pNew->data=value;
	pTail->pNext=pNew;
	pNew->pNext=NULL;
	pTail=pNew;
	}
	}
}
return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p=pHead->pNext;
while(NULL!=p)
{
	cout<<p->data<<endl;
	p=p->pNext;
}
}

int length_list(PNODE pHead)
{
int i=0;
PNODE p=pHead->pNext;
while(NULL!=p)
{
i++;
p=p->pNext;
}
cout<<"链表长度为："<<i<<"\n"<<endl;
return i;
}

bool is_empty_list(PNODE pHead)
{
	PNODE p=pHead->pNext;
	if(NULL==p)
	{
	cout<<"链表为空。"<<endl;
	return true;
	}
	else
	{
	cout<<"链表不为空"<<endl;
	return false;
	}
}

//插入位置为position,值为value
//position的值从1开始
bool insert_list(PNODE pHead,int position,int value)
{
int i=0;
PNODE p=pHead;
while(NULL!=p&&i<position-1)
{
	p=p->pNext;
	i++;
}
if(i>position-1||NULL==p)
{
cout<<"位置输入错误，插入失败"<<endl;
return false;
}

else
{
PNODE pNew=(PNODE)(malloc(sizeof(NODE)));
pNew->data=value;
PNODE q=p;
pNew->pNext=p->pNext;
p->pNext=pNew;
return true;
}

}

bool delete_list(PNODE pHead,int position,int *value)
{
int i=0;
PNODE p=pHead;
while(NULL!=p->pNext&&i<position-1)
{
	p=p->pNext;
	i++;
}
if(i>position-1||NULL==p->pNext)
{
cout<<"要删除的节点不存在"<<endl;
return false;
}
else
{
	PNODE q=p->pNext;
	*value=q->data;
	p->pNext=q->pNext;
	free(q);
	return true;
}
}