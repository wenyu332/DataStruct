#include <iostream>
using namespace std;
typedef struct Arr 
{
	int *pBase;
	int length;
	int cnt;
}ARR,*PARR;
void create_arr(PARR,int);
void traverse_arr(PARR);
bool is_empty_arr(PARR);
bool is_full_arr(PARR);
bool append_arr(PARR,int,int);
int main() 
{
	ARR  arr;
	int length = 0;
	int i = 0;
	cin >> length;
	create_arr(&arr,length);
	traverse_arr(&arr);
	while (i<length)
	{
		int value;
		cin >> value;
		append_arr(&arr, i, value);
		i++;
	}
	traverse_arr(&arr);
	system("pause");
	return 0;
}

void create_arr(PARR pArr,int length) 
{
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		cout << "��������ʧ��\n";
		return;
	}
	else
	{
		pArr->length = length;
		pArr->cnt = 0;
			return;
	}
}

void traverse_arr(PARR pArr) 
{
	if (is_empty_arr(pArr)) 
	{
		cout << "����Ϊ��\n";
		return;
	}
	else
	{
		for (int i = 0; i < pArr->cnt;i++) 
		{
			cout << "ѭ������i==" << i << "cnt==" << pArr->cnt << endl;
			cout << *(pArr->pBase + i) << endl;
		}
	}
}

bool is_empty_arr(PARR pArr) 
{
	if (0 == pArr->cnt)
	{
		return true;
	}
	else
		return false;
}
bool is_full_arr(PARR pArr) 
{
	if (pArr->cnt == pArr->length)
	{
		cout << "��������\n";
		return true;
	}
	else
		return false;

}

bool append_arr(PARR pArr,int position,int value)
{
	if (position<0 || position>pArr->length - 1)
	{
		cout << "����λ�ô���\n";
		return false;
	}
	else
	{
		for (int i = pArr->cnt; i > position; i--)
		{
			*(pArr->pBase+i) = *(pArr->pBase+(i-1));
		}
		*(pArr->pBase+position) = value;
		pArr->cnt++;
		cout << "�������Ϊ:"<<*(pArr->pBase + position) << endl;
		return true;
	}
}