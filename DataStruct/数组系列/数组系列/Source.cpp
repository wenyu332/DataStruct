#include "pArray.h"
int main() 
{
	ARRAY array;
	init_array(&array);
	insert_array(&array,0,1);
	insert_array(&array, 1, 2);
	insert_array(&array, 2, 3);
	insert_array(&array, 3, 4);
	traverse_array(&array);
	if (array_is_empty(&array))
	{
		cout << "Êı×éÎª¿Õ\n";
	}
	system("pause");
	return 0;
}