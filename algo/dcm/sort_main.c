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
	last = lo;
	i = base + width;
        while( i <= hi )
        {
                if (compar(lo,i) > 0)
		{
			last = last + width;
			swap(i,last,width);
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


int compo(const void *p1,const void *p2) 
{
	return strcmp(*(char **)p1,*(char **)p2); 
}


int compr(const void *p1,const void *p2) 
{
	return strcmp(*(char **)p2,*(char **)p1); 
}


int compn(const void *p1,const void *p2) 
{
	return *(int *)p1 - *(int *)p2;
}
	
static struct sort_type
{
        char type[3];
        int (*pf)(const void *p1,const void *p2);
}sort_op[] =
{
        { "-n",compn},
	{ "-o",compo},
        { "-r",compr}
//        { "-u",compu}
};
int sort(int argc ,char * argv[])
{
	FILE *fp;
	char *lineptr[MAXLINES];  /* pointers to text lines */
	char *tmp;
	int i = 0;
	int j = 0;
	int lines = 0;
	char buf[256];
	char sort_type[3];

	if( argc == 2)
		strcpy(sort_type,"-o");
	else
		strcpy(sort_type,argv[2]);


	fp = fopen(argv[1],"a+");

	if ( NULL  == fp)
	{
		printf("File does not exists\n");
		return -1;
	}

	while( fgets(buf,256,fp))
	{
		tmp = (char *)malloc(strlen(buf)*sizeof(char));
		strcpy(tmp,buf);
		lineptr[lines] = tmp;
		lines++;
	}

	for ( i = 0; i<sizeof(sort_op)/sizeof(sort_op[0]);i++)
        {
                if ( strcmp(sort_type,sort_op[i].type) == 0)
                {
			printf("type is %s\n",sort_op[i].type);
                        pfsort = sort_op[i].pf;
			xqsort(lineptr, lines, sizeof(char *), pfsort); 
                        break;
                }
        }






	fputs("--- after sort --- \n",fp);
	while(lines)
	{
		fputs(lineptr[j],fp);
		lines--;
		j++;
	} 

	fclose(fp);
	return 0;
	
	
}
	


int main(int argc,char * argv[])
{
	sort(argc,argv);
	return 0;
}
