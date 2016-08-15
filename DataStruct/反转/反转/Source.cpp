#include <iostream>
using namespace std;

typedef struct Node 
{
	int value;
	Node *pNext;
}NODE,*PNODE;
PNODE create_list();
void append_list(PNODE,int);
void traverse_list(PNODE);
PNODE opposition_list(PNODE);
int length_list(PNODE);
int main() 
{
	PNODE pHead=create_list();
	append_list(pHead,1);
	append_list(pHead,2);
	append_list(pHead,3);
	append_list(pHead,4);
	append_list(pHead,5);
	append_list(pHead,6);
	append_list(pHead,7);
	traverse_list(pHead);
	cout << length_list(pHead) << endl;
	PNODE pOpp = opposition_list(pHead);
	//cout << pOpp << endl;
	cout << length_list(pOpp)<<endl;
	traverse_list(pOpp);
	system("pause");
	return 0;
}
PNODE create_list() 
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		cout << "内存溢出\n";
		exit(-1);
	}
	pHead->pNext = NULL;
	pHead->value = NULL;
	return pHead;
}
void append_list(PNODE pHead,int data) 
{
	PNODE p = pHead;
	if (pHead == NULL)
	{
		cout << "空指针异常\n";
		exit(-1);
	}
	else
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->value = data;
		//pNew->pNext == NULL;
		while (p->pNext!=NULL) 
		{
			p = p->pNext;
		}
		p->pNext = pNew;
		pNew->pNext = NULL;
	}
}

void traverse_list(PNODE pHead) 
{
	PNODE p = pHead;
	//cout << "开始遍历链表\n";
	if (p==NULL)
	{
		cout << "空指针异常\n";
		exit(-1);
	}
	while (p != NULL)
	{
		cout << p->value;
		p = p->pNext;
		//cout << p->value;
	}
	cout << endl;
}

PNODE opposition_list(PNODE pHead) 
{
	
	if (pHead==NULL)
	{
		cout << "空指针异常\n";
		exit(-1);
	}
	else
	{
		PNODE p1 = pHead;
		PNODE p2 = p1->pNext;
		p1->pNext = NULL;
		PNODE p3 = NULL;
		while (p2!=NULL)
		{
			p3 = p2->pNext;
			p2->pNext =p1;
			p1 = p2;
			p2 = p3;
			//cout << "一个测试用例\n";
		}
		return p1;
	}
}
int length_list(PNODE pHead)
{
	int length = 0;
	pHead = pHead->pNext;
	while (pHead!=NULL) 
	{
		length++;
		pHead = pHead->pNext;
	}
	return length;
}
