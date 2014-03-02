#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tagbtree
{
	char word[64]; //store the english word
	int count;
	struct tagbtree *l,*r;
};

typedef struct tagbtree  *link;
typedef struct tagbtree btree;

int top = 0;  
char stack[64];

void push( char item)
{
	stack[top++] = item;
}

char pop(void)
{
	return stack[--top];
}

void empty(void)
{
	top = 0;
}


link make_node( char *word)
{
	link new;

	new = (btree *)malloc(sizeof(btree));
	strcpy(new->word,word);
	new->count = 1;
	new->l = NULL;
	new->r = NULL;
	return new;
}	
	

link search(link t, unsigned char key)
{

	return t ;
}

link insert(link t, char *word)
{

	if (!t)
		return  make_node(word);
	if (strcmp(word, t->word ) < 0)
	{
		t->l = insert(t->l,word);
	}
	if (strcmp(word, t->word) > 0)
	{
		t->r = insert(t->r,word);
	}
	if (strcmp(word,t->word) == 0)
	{
		t->count++;
	}
	
	return t;
}
static void free_node(link p)
{
	free(p);
}



link delete(link t,  char *word)
{
	link p;
	if(!t)
		return NULL;

	if(strcmp(t->word,word) > 0) /* delete from left subtree */
	{
		delete(t->l,word);
	}
	if(strcmp(t->word,word) < 0)
	{
		delete(t->r,word);
	}
	if(strcmp(t->word,word) == 0)
	{
		if (t->l == NULL && t->r == NULL)
		{
			free_node(t);
			t = NULL;
			return t;
		}
		if (t->l)
		{
			for (p = t->l; p->r; p = p->r);
			strcpy(t->word,p->word);
			t->count = p->count;
			t->l = delete(t->l, t->word);
		} 
		else 
		{ /* if t has right subtree */
			/* replace t with the leftmost node in right subtree */
			for (p = t->r; p->l; p = p->l);
			strcpy(t->word,p->word);
			t->count = p->count;
			t->r = delete(t->r, t->word);
		}

			
	}
	return t;
}
		

	

void print_tree(link t)
{
	if (t)
	 {
		//printf("(");
		printf("%s is %d times\n", t->word,t->count);
		//printf("%s is ", t->word);
		print_tree(t->l);
		print_tree(t->r);
	//	printf(")");
	} 
	else
	//	printf("()");
		return;

}

void print_max(link t)
{
	if(t)
	{
		printf("word:%s is %d times\n",t->word,t->count);
		return;
	}
	else
		return;
}

link serch_max(link t)
{
	link tmp = NULL;
	link max = NULL;

	
	if(!t)
		return NULL;

	max = (link)malloc(sizeof(btree));
	tmp = (link)malloc(sizeof(btree));
	max = t; //pre order
	tmp = serch_max(t->l);
	if((tmp !=NULL) && (tmp->count > max->count))
		max = tmp;
	
	tmp = serch_max(t->r);
	if((tmp != NULL) && (tmp->count > max->count))
		max = tmp;
	
	return  max;
}	

int main(int argc,char *argv[])
{
	
	
	FILE *fp;
	link root = NULL;
	link max = NULL;

	char c;

	if ( 2 != argc )
	{
		printf("Argument is error\n");
		return 0;
	}

	fp = fopen( argv[1],"rb");

	if ( NULL == fp )
	{
		printf("Open file is error\n");
		return 0;
	}

	while( EOF != (c = fgetc(fp)))
	{
		
		if( (c >= 97 && c <=122)||(c >= 65 && c <=90))
		{	
			push(c);
			continue;
		}
		if ( c == ' ' || c == '\n')
		{
			push('\0');
			root = insert(root,stack);
			empty();
			continue;
		}
				
	}
//	printf("\t\\tree");

	while(root)
	{
		max = serch_max(root);
		print_max(max);
		root = delete(root,max->word);

	}

//	print_tree(root);
		
	fclose(fp);	
	return 0;

}
