
#include <iostream>
using namespace std;
void traverse_arr(int *,int);
int main() 
{
	int length = 0;
	cin >> length;
	int *pArr = (int *)malloc(sizeof(int)*length);
	*pArr = 0;
	*(pArr + 1) = 1;
	*(pArr + 2) = 2;
	*(pArr + 3) = 3;
	*(pArr + 4) = 4;
	traverse_arr(pArr,length);
	system("pause");
	return 0;
}

void traverse_arr(int *pArr,int length) 
{
	if (pArr==NULL)
	{
		cout << "空指针\n";
		return;
	}
	else 
	{
		if (length == 0)
		{
			cout << "数组为空\n";
			return;
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				cout << pArr[i]<<endl;
			}
			return;
		}
	}

}