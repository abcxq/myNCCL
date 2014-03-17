#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h> 

#define MAXLINES 5500  /* max #lines to be sorted */

void swap(char *p, char *q, size_t width)
{

	char tmp;
	if (p != q)
	{
		while(width--)
		{	
			tmp = *p;
			*p++ = *q;
			*q++ = tmp;
		}
	}

	return; 	
}

void xqsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
	char  *i;
	char *lo, *hi;
	char *last,*mid;
	size_t size,lsize,rsize;

	if (nel < 2 || width == 0)
		return;

	
	lo = base; 
	hi = (char *)base + (nel - 1)*width;
	
	size = (hi - lo) / width + 1;  /* number of elements to sort */ 

	mid = lo + (size / 2) * width;      /* find middle element */  
	
	swap(lo,mid,width);
//	printf("lo is %d,mid is %d\n",*lo,*mid);
	last = lo;
	i = base + width;
//	for(i = base + width;i <= hi;i + width)
	while(i <= hi )
	{
		if (compar(lo,i) > 0)
		{
		//	printf("bswap i is %d,last is %d\n",*i,*last);
			last = last + width;
			swap(i,last,width);
		//	printf("aswap i is %d,last is %d\n",*i,*last);
		}	
		i = i + width;
	}

	swap(lo,last,width);
	lsize = (last - lo) / width ;  /* number of left elements  */ 
	rsize = (hi - last) / width ;  /* number of right elements  */ 
	xqsort(lo,lsize ,width,compar);
	xqsort(last + width,rsize ,width,compar);		

	return;
}


int (*pfsort)(const void *p1,const void *p2);


int compn(const void *p1,const void *p2) 
{
	return *(int *)p1 - *(int *)p2;
}
	
int main()
{
	int buf[5] = {3,1,4,5,9};
	int i = 5;

	xqsort(buf,5,sizeof(int),compn); 

	while(i)
		printf("buf is %d\n",buf[--i]);

	return 0;
	
	
}


