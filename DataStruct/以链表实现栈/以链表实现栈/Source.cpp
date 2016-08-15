#include<iostream>
using namespace std;
typedef struct Node 
{
	int val;
	struct Node *pNext;
}NODE,*PNODE;
typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;
void create_stack(PSTACK);
void push(PSTACK,int);
void traverse(PSTACK);
bool is_empty_stack(PSTACK);
bool pop(PSTACK);
int main() 
{
	STACK stack;
	create_stack(&stack);
	push(&stack,11);
	push(&stack, 22);
	push(&stack, 33);
	push(&stack, 44);
	push(&stack, 55);
	traverse(&stack);

	pop(&stack);
	pop(&stack);
	pop(&stack);
	pop(&stack);
	pop(&stack);
	traverse(&stack);
	system("pause");
	return 0;
}

void create_stack(PSTACK pStack) 
{
	pStack->pBottom = (PNODE)malloc(sizeof(NODE));
	if (NULL == pStack->pBottom)
	{
		cout << "ÄÚ´æÒÑÂú£¬³õÊ¼»¯Ê§°Ü\n";
		exit(-1);
	}
	else
	{
		pStack->pTop = pStack->pBottom;
		pStack->pBottom->pNext = NULL;
	}
}

void push(PSTACK pStack,int value) 
{
	if (NULL==pStack)
	{
		cout << "¿ÕÖ¸Õë\n";
		return;
	}
	else
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew) 
		{
			cout << "ÄÚ´æÒÑÂú£¬³õÊ¼»¯Ê§°Ü\n";
			exit(-1);
		}
		else
		{
			pNew->val = value;
			pNew->pNext = pStack->pTop;
			pStack->pTop = pNew;
		}
	}
}

void traverse(PSTACK pStack) 
{
	if (NULL == pStack)
	{
		cout << "¿ÕÖ¸Õë\n";
		return;
	}
	else
	{
		if (is_empty_stack(pStack))
		{
			cout << "Õ»Îª¿Õ\n";
			return;
		}
		else
		{
			PNODE p = pStack->pTop;
			while (p->pNext!=NULL) 
			{
				cout << p->val<<endl;
				p = p->pNext;
			}
		}
		
	}
}
bool is_empty_stack(PSTACK pStack) 
{
	if (NULL== pStack)
	{
		cout << "¿ÕÖ¸Õë\n";
		return false;
	}
	else
	{
		if(pStack->pBottom==pStack->pTop)
			{
				return true;
		}
		else
		{
			return false;
		}
	}
}

bool pop(PSTACK pStack) 
{
	if (NULL== pStack)
	{
		cout << "¿ÕÖ¸Õë\n";
		return false;
	}
	else
	{
		if (is_empty_stack(pStack))
		{
			cout << "Õ»Îª¿Õ\n";
			return false;
		}
		else
		{
			PNODE p = pStack->pTop;
			//cout << p->val << endl;
			pStack->pTop = p->pNext;
			free(p);

		}
	}
}