
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

struct Arr{
int *pBase; //�洢���������һ��Ԫ�صĵ�ַ
int len;	//�����������ɵ����Ԫ�صĸ���
int cnt;	//��ǰ������ЧԪ�صĸ���
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
void inversion_arr();  //��������
int main(void )
{
struct Arr arr;

init_arr(&arr,6);
show_arr(&arr); //ֱ�Ӵ�arrҲ����
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
	pArr->pBase =(int *)malloc(sizeof(int)*length);       //arrָ��ṹ�������pBase��Ա����

	if(NULL==pArr->pBase)
	{
	printf("��̬�ڴ����ʧ��");
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
	printf("����Ϊ��");
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
	printf("��������");
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
printf("��������");
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