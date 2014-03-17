#include <stdio.h>
#include <stdlib.h>

#define NELEMS(arr) (sizeof(arr) / sizeof(arr[0]))
int numarray[] = {123, 145, 512, 627, 800, 933};
const int key = 512;


void *binse(const void *key, const void *base, size_t nelem, size_t width, int(*fcmp)(const void *, const void *))
{
	void *low,*high,*mid;
	low = base;
	high = base + (nelem - 1) * width;

	while(low <= high)
	{
		mid = (high - low)/2;
		
		if (fcmp(key,mid) < 0)
		{
			high = mid + width;
		}
		else
			if (fcmp(key,mid) > 0)
				low = mid + width;	
			else
				return mid;
	}
	
	return NULL;
}
	
int numeric(const int *p1, const int *p2)
{
	printf("p1 is %x,p2 is %x",p1,p2);
			printf("yyy\n");

	return(*p1 - *p2);
}

int main()
{
	int *itemptr = NULL;

	itemptr = (int *)binse(&key,numarray,NELEMS(numarray),sizeof(int),numeric);
	

	if (itemptr == NULL)
		printf("Not found\n");
	else
		printf("%d is in the table\n",key);

	
	return 0;
}
