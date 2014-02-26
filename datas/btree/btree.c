#include <stdio.h>
#include <stdlib.h>

struct tagbtree
{
	unsigned char item;
	int count;
	struct tagbtree *l,*r;
};

typedef struct tagbtree  *link;
typedef struct tagbtree btree;

link make_node( char key)
{
	link new;

	new = (btree *)malloc(sizeof(btree));
	new->item = key;
	new->count = 1;
	new->l = NULL;
	new->r = NULL;
	return new;
}	
	

link search(link t, unsigned char key)
{

	return t ;
}

link insert(link t, unsigned char key)
{

	if (!t)
		return  make_node(key);
	if ( key < t->item )
	{
		t->l = insert(t->l,key);
	}
	if ( key > t->item)
	{
		t->r = insert(t->r,key);
	}
	if ( key == t->item)
	{
		t->count++;
	}
	
	return t;
}
link delete(link t, unsigned char key)
{

	return t;

}
void print_tree(link t)
{
	if (t)
	 {
	//	printf("(");
		printf("%c is %d times\n", t->item,t->count);
		print_tree(t->l);
		print_tree(t->r);
//		printf(")");
	} 
	else
	//	printf("()");
		return;

}


int main(int argc,char *argv[])
{
	
	
	FILE *fp;
	link root = NULL;

	char buf[256];
	char *bufp;

	if ( 2 != argc )
	{
		printf("Argument is error\n");
		return 0;
	}

	fp = fopen ( argv[1],"rb");

	if ( NULL == fp )
	{
		printf("Open file is error\n");
		return 0;
	}

	while( NULL != fgets(buf,256,fp))
	{
		
		bufp = buf;
		while( *bufp )
		{
			if( *bufp != ' ' || *bufp != '\n')
			{	
				root = insert(root,*bufp);
				bufp++;
				continue;
			}
			else
				bufp++;
		}
	}
//	printf("\t\\tree");

	print_tree(root);
		
	fclose(fp);	
	return 0;

}
