#include <stdio.h>
#include "clist.h"
#include <malloc.h>


void clist_print(link cur, void (*pf)(void *))
{

	if ( NULL == cur )
		printf("NULL\n");
	else
		pf( cur->data);

	return;
}

void print_int_data(void *data)
{
	printf("data is %d\n",*(int *)data);
	return;
	
}

int *make_data(int data)
{
	int *p = NULL;

	p =(int *)malloc(sizeof(int)); //why ?
	*p = data;
	
	return p;	

}

link make_node(void *data)
{
	node *new_node;

	new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = new_node;
	
	return new_node;
}

link clist_insert_after(link cur, link item)
{

	if ( NULL == cur)
	{
		cur = item;
		return cur;
	}

/*	link tmp;
	tmp = cur;
	
	cur->next = item;
	item ->next = tmp->next; */

	item->next = cur->next;
	cur-> next = item;
	return item;

}


int clist_length(link cur)
{

	if ( NULL == cur)
		return 0;

	int i = 1;

	link p;
	p = cur;
	p = p-> next;

	while(p != cur)
	{
		i++;
		p = p-> next;
	}

	return i;
}

link clist_delete(link cur, link item)
{
	
	link  p;
	p = cur;

	if( p ->next == p) //That's mean only  one node left;
	{
		free(p);
		return NULL;
	}


	while(1)
	{
		if( p->next == item) //find a previous one before item
			break;

		p = p -> next;
	}
	
	cur = item ->next;
	p -> next = item -> next;

	free(item);
	return cur;
}
	

int main(void)
{
    link cursor = NULL;
    int i = 0;
    link item;
    int *p;

    clist_print(cursor, print_int_data);

    for (i = 0; i < 10; i++)
    {
        p = make_data(i+1);
        item = make_node(p);
        cursor = clist_insert_after(cursor, item);
    }

    cursor = cursor->next;
    clist_print(cursor, print_int_data);
    printf("ring list length = %d\n", clist_length(cursor));

    int step = 0;
    while (cursor != NULL)
    {
        print_int_data(cursor->data);
        step++;

        if (step == 3)  
        {
            printf("-> %d out\n", *(int *)(cursor->data));
            cursor = clist_delete(cursor, cursor);
            printf("length = %d\n", clist_length(cursor));
            step = 0;
        }
        else
            cursor = cursor->next;
    } 

    return 0;
}


