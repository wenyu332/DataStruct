#include <iostream>
//#include <>
using namespace std;
typedef struct Arr 
{
	int *pBase;
	int length;
	int cnt;
}ARR,*PARR;
void create_arr(PARR,int);
void append_arr(PARR,int);
void traverse_arr(PARR);
bool insert_arr(PARR,int,int);
void main() 
{
	int length;
	ARR arr;
	cin >> length;
	create_arr(&arr,length);
	append_arr(&arr, 11);
	append_arr(&arr, 22);
	append_arr(&arr, 33);
	append_arr(&arr, 44);
	traverse_arr(&arr);
	system("pause");
}
void create_arr(PARR pArr,int length) 
{
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if (pArr->pBase == NULL)
	{
		cout << "数组初始化失败\n";
		return;
	}
	else
	{
		pArr->cnt = 0;
		pArr->length = length;
		return;
	}
}

void append_arr(PARR pArr,int value) 
{
	if (pArr->cnt==pArr->length)
	{
		cout << "数组已满，无法追加\n";
		return;
	}
	else
	{
		*(pArr->pBase + pArr->cnt) = value;
		pArr->cnt++;
	}
}

void traverse_arr(PARR pArr) 
{
	if (pArr->cnt==0)
	{
		cout <<"数组为空\n" ;
		return;
	}
	else
	{
		for (int i = 0; i < pArr->cnt; i++)
		{
			cout << "第" << i << "个数为：" << pArr->pBase[i] << endl;
			
		}
		return;
	}
}

bool insert_arr(PARR pArr,int position,int value) 
{
}