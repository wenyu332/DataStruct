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
	cout<<"ɾ���ڵ��ֵΪ��"<<value_delete<<endl;
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
	cout<<"��̬�ڴ����ʧ��"<<endl;
}
else
{
cout<<"���������ڵ�Ĵ�С��";
	cin>>length;
	PNODE pTail=pHead;
	pTail->pNext=NULL;
	for(int i=0;i<length;i++)
	{
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
	cout<<"��̬�ڴ����ʧ�ܡ�";
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
cout<<"������Ϊ��"<<i<<"\n"<<endl;
return i;
}

bool is_empty_list(PNODE pHead)
{
	PNODE p=pHead->pNext;
	if(NULL==p)
	{
	cout<<"����Ϊ�ա�"<<endl;
	return true;
	}
	else
	{
	cout<<"����Ϊ��"<<endl;
	return false;
	}
}

//����λ��Ϊposition,ֵΪvalue
//position��ֵ��1��ʼ
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
cout<<"λ��������󣬲���ʧ��"<<endl;
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
cout<<"Ҫɾ���Ľڵ㲻����"<<endl;
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