
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

struct Arr{
int *pBase; //存储的是数组第一个元素的地址
int len;	//数组所能容纳的最大元素的个数
int cnt;	//当前数组有效元素的个数
};

void init_arr(struct Arr *arr,int length);
bool append_arr(struct Arr *arr,int value);
bool insert_arr(struct Arr *pArr,int position,int value);
bool delete_arr();
int get();
bool is_empty(struct Arr *arr);
bool is_full(struct Arr *arr);
void sort_arr();
void show_arr(struct Arr *arr);
void inversion_arr();  //倒置数组
int main(void )
{
struct Arr arr;

init_arr(&arr,6);
show_arr(&arr); //直接传arr也可以
is_empty(&arr);
append_arr(&arr,1);
append_arr(&arr,15);
append_arr(&arr,231);
show_arr(&arr);

insert_arr(&arr,1,88);
show_arr(&arr);
system("pause");
return 0;

}

void init_arr(struct Arr *pArr,int length)
{
	pArr->pBase =(int *)malloc(sizeof(int)*length);       //arr指向结构体变量的pBase成员变量

	if(NULL==pArr->pBase)
	{
	printf("动态内存分配失败");
	exit(-1);
	}
	else
	{
		pArr->len=length;
		pArr->cnt=0;
	}
	return ;
}

bool is_empty(struct Arr *pArr)
{
if(0==pArr->cnt)
	return true;
else 
	return false;

}
bool is_full(struct Arr *pArr)
{
	if(pArr->cnt==pArr->len)
		return true;
	else
		return false;

}
void show_arr(struct Arr *pArr)
{
	if(is_empty(pArr))
	{
	printf("数组为空");
	}

	else
	{
		for(int i=0;i<pArr->cnt;i++)
		{
			printf("%d",pArr->pBase[i]);
			printf("\n");
			std::cout<<*(pArr->pBase+1)<<std::endl;
		}
	}
	printf("\n");
}

bool append_arr(struct Arr* pArr,int value)
{
	if(is_full(pArr))
	{
	printf("数组已满");
	return false;
	}
	else
	{
		pArr->pBase[pArr->cnt]=value;
		pArr->cnt++;
		return true;
	}
}

bool insert_arr(struct Arr *pArr,int position,int value)
{
if(is_full(pArr))
{
printf("数组已满");
return false;
}

else
{
	for(int i=pArr->cnt-1;i>=position;i--)
	{
		pArr->pBase[i+1]=pArr->pBase[i];
	}
	pArr->pBase[position]=value;
	pArr->cnt++;
return true;
}


}