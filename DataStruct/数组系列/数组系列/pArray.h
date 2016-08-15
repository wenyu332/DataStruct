#pragma once
#include <iostream>
using namespace std;
typedef struct Array 
{
	int *pBase;
	int length;
	int cnt;
}ARRAY,*PARRAY;
int* init_array(PARRAY);
bool array_is_empty(PARRAY);
bool array_is_full(PARRAY);
bool insert_array(PARRAY,int,int);
void traverse_array(PARRAY);
int* init_array(PARRAY pArray) 
{
	cin>>pArray->length;
	pArray->pBase = (int *)malloc(sizeof(int)*pArray->length);
	pArray->cnt = 0;
	return pArray->pBase;
}
bool array_is_empty(PARRAY pArray) 
{
	if (0==pArray->cnt)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool array_is_full(PARRAY pArray) 
{
	if (pArray->cnt==pArray->length)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool insert_array(PARRAY pArray,int position,int value) 
{
	if (pArray==NULL)
	{
		cout << "空指针\n";
		exit(-1);
	}
	else
	{
		if (array_is_full(pArray))
		{
			cout << "数组已满\n";
			return false;
		}
		else
		{
			if (position<0||position>pArray->cnt)
			{
				cout << "插入位置错误\n";
				return false;
			}
			else
			{
				for (int i = pArray->cnt; i >position; i--)
				{
					int temp = pArray->pBase[i];
					pArray->pBase[i] = pArray->pBase[i-1];
					pArray->pBase[i - 1] = temp;
				}
				pArray->pBase[position] = value;
				pArray->cnt++;
			}
		}
	}
}
void traverse_array(PARRAY pArray) 
{
	if (array_is_empty(pArray))
	{
		cout << "数组为空\n";
	}
	else
	{
		for (int i = 0; i < pArray->cnt; i++)
		{
			cout << pArray->pBase[i]<<"  ";
		}
		cout << endl;
	}
}