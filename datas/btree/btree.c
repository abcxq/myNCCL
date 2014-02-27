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
		//printf("t->r->item is %c",t->r->item);
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
		printf("(");
		printf("%c,%d", t->item,t->count);
		print_tree(t->l);
		print_tree(t->r);
		printf(")");
	} 
	else
		printf("()");

}

void print_treexq(link t)
{
	if (t)
	{
		printf("%d", t->item);
		print_treexq(t->l);
		print_treexq(t->r);
	}
	else
		printf(" ");
}
		


int main(int argc,char *argv[])
{
	
	
	FILE *fp;
	link root = NULL;

	char c;

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

	while( EOF != (c = fgetc(fp)))
	{
		if ( c == ' ' || c == '\n' )
		{
			continue;
		}
		else
		{
			root = insert(root,c);
			continue;
		}
	}
	printf("The tree is ");

	print_tree(root);
		
	fclose(fp);	
	return 0;

}
