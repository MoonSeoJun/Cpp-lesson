#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int value[] = { 88,56,100,2,25 };

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main() 
{
	int n;

	printf("Before sorting the list is : \n");

	for (n = 0; n < 5; n++)
	{
		printf("%d ", value[n]);
	}

	qsort(value, 5, sizeof(int), cmpfunc);

	printf("\nAfter sorting the list is: \n");

	for (n = 0; n < 5; n++)
	{
		printf("%d ", value[n]);
	}
	
	return 0;
}