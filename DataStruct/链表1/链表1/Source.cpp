
#include <iostream>
using namespace std;
typedef struct Node 
{
	int value;
	struct Node * pNext;
}NODE,*PNODE;

PNODE create_list(void);
void traverse_list(PNODE);
int length_list(PNODE);
bool insert_list(PNODE,int ,int);
bool delete_list(PNODE,int,int *);
int main() 
{
	int value;
	PNODE pHead;
	pHead = create_list();
	traverse_list(pHead);
	length_list(pHead);
	insert_list(pHead,2,888);
	traverse_list(pHead);
	delete_list(pHead,2,&value);
	cout << value << endl;
	system("pause");
	return 0;
}


//��ʼ������
PNODE create_list(void) 
{
	int length;
	int value;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		cout << "��̬�ڴ����ʧ��\n" << endl;
	}

	else 
	{
		cout << "�������ʼ���ڵ�ĸ���:\n" << endl;
		cin >> length;
		PNODE pTail = pHead;
		pTail->pNext = NULL;
		for (int i = 0; i < length; i++)
		{
			cin >> value;
			PNODE pNew = (PNODE)malloc(sizeof(NODE));
			if (NULL == pNew)
			{
				cout << "��̬�ڴ����ʧ��\n" << endl;
			}
			else 
			{
				pNew->value = value;
				pTail->pNext = pNew;
				pTail = pNew;
				pTail->pNext = NULL;
			}
		}
	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p= pHead->pNext;
	while (NULL != p)
	{
		cout << p->value << "  "<<endl;
		p = p->pNext;
	}
	cout << "\n";
}
int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int i = 0;
	while (NULL!=p) 
	{
		i++;
		p = p->pNext;
	}
	cout << "�ڵ����Ϊ:" << i << "\n";
	return i;
}

bool insert_list(PNODE pHead,int position,int value)
{
	int i = 0;
	PNODE p = pHead;
	while (p != NULL&&i < position - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > position - 1 || NULL == p)
	{
		cout << "����ʧ��\n";
		return false;
	}
	else 
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL==pNew)
		{
			cout << "��̬�ڴ����ʧ��\n";
		}
		else
		{
			pNew->value = value;
			PNODE q = p->pNext;
			pNew->pNext = q;
			p->pNext = pNew;
			
		}
		return true;
	}
	
}

bool delete_list(PNODE pHead,int position,int *value) 
{
	PNODE p = pHead;
	int i = 0;
	while (NULL!=p->pNext&&i<position-1)
	{
		p = p->pNext;
		i++;
	}
	if (i > position - 1||NULL==p->pNext)
	{
		cout << "Ҫɾ���Ľڵ㲻����\n";
		return true;
	}
	else 
	{
	
		PNODE q = p->pNext;
		*value = q->value;
		p->pNext = p->pNext->pNext;
		free(q);
		
		return true;
	
	}


}