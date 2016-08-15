#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
int data;
struct Node * node;
}NODE,*PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);	//遍历输出

bool is_empty(PNODE pHead); //是否为空
int length_list(PNODE pHead); //链表长度
bool insert_list(PNODE pHead,int position,int value); //在Phead链表的第POSTION节点前面插入一个新节点，该值为value
bool delete_list(PNODE pHead,int position,int *value); //删除并返回删除值的地址
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
	printf("删除失败\n");
	}
	traverse_list(pHead);
	system("pause");
	return 0;
}

PNODE create_list(void)
{
	int len; //用来存放有效节点的个数
	int  i;
	int val;//用来临时存放用户输入的节点的值
	PNODE pHead=(PNODE)(malloc(sizeof(NODE)));  //分配了一个不存放有效数据的头结点

	if(NULL==pHead)
	{
	printf("分配失败");
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
	printf("链表为空\n");
		return true;
	}
	else 
	{
		printf("链表不为空\n");
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
 printf("动态内存分配失败\n");
 exit(-1);
 }
 else
 {
	 pNew->data=value;
	 PNODE r=p->node;
	 pNew->node=r;  //当时是这里出错
	 p->node=pNew;
	 printf("插入成功\n");
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