#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
int data;
struct Node * node;
}NODE,*PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);	//�������

bool is_empty(PNODE pHead); //�Ƿ�Ϊ��
int length_list(PNODE pHead); //������
bool insert_list(PNODE pHead,int position,int value); //��Phead����ĵ�POSTION�ڵ�ǰ�����һ���½ڵ㣬��ֵΪvalue
bool delete_list(PNODE pHead,int position,int *value); //ɾ��������ɾ��ֵ�ĵ�ַ
int main(void)
{
	int val;
	PNODE pHead=NULL;
	pHead=create_list();
	//traverse_list(pHead);
	is_empty(pHead);
	length_list(pHead);
	insert_list(pHead,3,45);
	traverse_list(pHead);
	if(delete_list(pHead,3,&val))
	{
	printf("%d\n",val);
	}
	else
	{
	printf("ɾ��ʧ��\n");
	}
	traverse_list(pHead);
	system("pause");
	return 0;
}

PNODE create_list(void)
{
	int len; //���������Ч�ڵ�ĸ���
	int  i;
	int val;//������ʱ����û�����Ľڵ��ֵ
	PNODE pHead=(PNODE)(malloc(sizeof(NODE)));  //������һ���������Ч���ݵ�ͷ���

	if(NULL==pHead)
	{
	printf("����ʧ��");
	exit(-1);
	}

	PNODE pTail=pHead; //
	pTail->node=NULL;
	scanf("%d",&len);

	for(i=0;i<len;i++)
	{
	scanf("%d",&val);
	PNODE pNew=(PNODE)malloc(sizeof(NODE));
	pNew->data=val;
	pTail->node=pNew;
	pNew->node=NULL;
	pTail=pNew;
	}

	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p=pHead->node;
	while(NULL!=p)
	{
		printf("%d\n",p->data);
		p=p->node;
	}
	
	return;
}

bool is_empty(PNODE pHead)
{
	if(NULL==pHead->node)
	{
	printf("����Ϊ��\n");
		return true;
	}
	else 
	{
		printf("����Ϊ��\n");
		return false;
	}
}
int length_list(PNODE pHead)
{
	PNODE p=pHead->node;
	int i=0;
	while(NULL!=p)
	{
	i++;
	p=p->node;
	}
	printf("%d",i);
	return i;
}

bool insert_list(PNODE pHead,int position,int value)
{
 int i=0;
 PNODE p=pHead;
 while(NULL!=p&&i<position-1)
 {
	 p=p->node;
	 i++;
 }
 if(NULL==p||i>position-1)
	 return false;
 else
 {
 PNODE pNew=(PNODE)malloc(sizeof(NODE));
 if(NULL==pNew)
 {
 printf("��̬�ڴ����ʧ��\n");
 exit(-1);
 }
 else
 {
	 pNew->data=value;
	 PNODE r=p->node;
	 pNew->node=r;  //��ʱ���������
	 p->node=pNew;
	 printf("����ɹ�\n");
	 return true;
 }
 
 }

}

bool delete_list(PNODE pHead,int position,int *value)
{
	int i=0;
PNODE p=pHead;
while(NULL!=p->node&&i<position-1)
{
	p=p->node;
	i++;
}
if(NULL==p->node||i>position-1)
{
return false;
}
else
{
	PNODE r=p->node;
	*value=r->data;
	p->node=r->node;
	free(r);
	r=NULL;
	return true;
}

}