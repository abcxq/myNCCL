#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

#define NELEMS(arr) (sizeof(arr) / sizeof(arr[0]))
const int a[6] = {123,145,512,627,800,933};
const int key = 123;


void *binse(const void *key, const void *base, size_t nelem, size_t width, int(*fcmp)(const void *, const void *))
{
	char  *low,*high,*mid;
	low = (char *)base;
	high = (char *)base + (nelem - 1) * width;


	while(low <= high)
	{
		nelem = (high - low) / width + 1;
		printf("nelem is %d",nelem);
		mid = low +  (nelem - 1 ) / 2 * width ; //important
//		printf("low is %d mid is %d\n",*low,*(int *)mid);
		if (fcmp((char *)key,mid) < 0)
		{
			high = mid - width; //important
		}
		else
			if (fcmp((char *)key,mid) > 0)
			{
				low = mid + width; //important
			//	printf("low is %d, high is %d\n",*(int *)low,*(int *)high);
			}	
			else
				return mid;
	}
	
	return NULL;
}
	
int numeric(const void *p1, const void *p2)
{

	return *(int *)p1 - *(int *)p2;
}

int main()
{
	int *itemptr = NULL;
	printf("key is %d \n",(char *)key);	

	itemptr = (int *)binse(&key,a,6,sizeof(int),numeric);
	

	if (itemptr == NULL)
		printf("Not found\n");
	else
		printf("%d is in the table\n",key);

	
	return 0;
}
