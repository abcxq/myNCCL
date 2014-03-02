#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node *nodeptr;
typedef struct node {
	char *symblic;
	char *address;
	nodeptr next;
} node;

#define NHASH 29989
#define MULT 31
nodeptr bin[NHASH];

unsigned int hash(char *str)
{ 
	unsigned int h = 0;
	unsigned char * p;

	for (p = (unsigned char *)str ; *p != '\0'; p++)
		h = MULT * h + *p;

	return h % NHASH;
}

void insertsym(char *address,char *symblic)
{
	int h;
	nodeptr p;

	h = hash(symblic);

/*	for(p = bin[h]; p != NULL; p = p->next)
		if(strcmp(p->word,str) == 0)
		{
			p->count++;
			return;
		} */

	p = (nodeptr)malloc(sizeof(node));

	if(p != NULL)
	{
		p->address = (char *)malloc(strlen(address)+1);
		p->symblic = (char *)malloc(strlen(symblic)+1);
		strcpy(p->address,address);
		strcpy(p->symblic,symblic);
		p->next = bin[h];
		bin[h] = p;
	}
	return;
}


char *substr(char *s,int start,int end)
{
	char *tmp;
	int i,j;

	if(start > end)
	{
		printf("argument error\n");
		return NULL;
	}
	if(start <= 0 || end <= 0)
	{
		printf("argument error\n");
		return NULL;
	}

	tmp = (char *)malloc((end-start+1)*sizeof(char));
	
	for(i = start - 1,j = 0 ;i < end ;i++,j++)
	{
		*(tmp + j) = *(s + i);		
	}

		*(tmp + j) = '\0';

	return tmp;
}

int main(int argc,char *argv[])
{

	FILE *fp;
	char buf[256];
	char address[9],symlic[32];
	char addr[256];
	nodeptr p;
	int i,h;

	
	if (3 != argc)
	{
		printf("Argument is error\n");
		return 0;
	}

	fp = fopen(argv[2],"rb");

	if (NULL == fp)
	{
		printf("Open file error\n");
		return 0;
	}

	for (i = 0; i < NHASH; i++)
		bin[i] = NULL;

	while(fgets(buf,256,fp))
	{
		if (strncmp(buf,"        ",8) != 0)
		{
			strcpy(address,substr(buf,1,8));
			strcpy(symlic,substr(buf,12,strlen(buf)-1));
		}
		else
		{
			strcpy(symlic,substr(buf,12,strlen(buf)-1));
		} 
		insertsym(address,symlic);
		
	}
		
	h = hash(argv[1]); //get the hash value of input argument
	
	for(p = bin[h]; p != NULL; p = p->next)
	{
		if (strcmp(p->symblic,argv[1]) == 0)
			printf(" %s address is %s",argv[1],p->address);
		fclose(fp);
		return 0;
	}
	
	printf("%s not found\n",argv[1]);
	
	
	fclose(fp);
	return 0;
}
