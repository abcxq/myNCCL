#include "array.h"

Array array_new(void)
{
	node *new;
	
	new  = (node *) malloc(sizeof(node));

	new->next = NULL;

	return new;//That mean new is name which is the start address
}


Item array_first(Array name)
{
	
	return name->next;
}

Item array_last(Array name)
{
	node *p;

	p = name;

	while( p->next )//p的下一个不为空的话就赋值
	{
		p = p->next;
	}
	 return p;
}

int array_length(Array name)
{
	node *p;
	int i = 0;

	p = name;
	
	while (p -> next)
	{
		p = p->next;
		i++;
	}
	
	return i;
}


void array_insert(Array name, int index, char data)
{
	node *p,*newitem;
	int length = 0,j = 0;
	
	p = name;
	length = array_length( name );
	
	printf("length is %d\n",length);
	printf("index is %d\n",index);

		
	if ( -1 == index || index == length)//append the link
	{
		newitem = (node *)malloc(sizeof(node));
		newitem->item = data;
		newitem->next = NULL;
		array_last(name)->next = newitem;
		return ;
	}

	if ( index < length )
	{
			printf("yyy\n");
		while (j < index )
		{
			p = p -> next;
			j++;
		}
		
		newitem = (node *)malloc(sizeof(node));
		newitem->item = data;
		newitem->next = p ->next;
		p ->next = newitem;
		return ;
	}
	else
	{
		while( length < index )
		{
			array_insert(name,-1,'n');
			length = array_length(name);
		}
		array_insert(name,-1,data);
	}

	return ;
}

	
Item array_list(Array name,int index)
{
	int length = 0;
	int i = 0;
	node *p;
	
	p = name;

	length = array_length(name);

	if ( index >= length )
	{
		printf("index is out of rage\n");
		exit(1);
	}

	for (i = 0;i <= index ;i++)
	{
		p = p->next;
	}

	
	return p;
}

		
void  array_delete_at(int index, Array name)
{

	node *p;
	node *tmp;

	if (0 == index)
	{
		tmp = name->next;
		name->next = tmp->next;
		free(tmp); 
		
	}
	else
	{

		p = array_list(name,index-1);
		tmp = p->next;
		p->next = tmp->next;	
		free(tmp);
	}
}

void  array_clear(Array name)
{
	int i;
	int length = 0;
	node *p,*tmp;

	p = name;

	name->next = NULL;

	while ( p ->next)
	{
		tmp = p->next;
		p = p->next;
		free (tmp);
	}
	
	return ;
}


int array_index(Array name,char data)
{
	node *p;
	int index = -1;
	p = name->next;
	
	while ( p)
	{
		index++;
		if( data == p->item)
		{
			break;
		}
		p = p -> next;
	}

	return index;
}

Array array_reverse(Array name)
{
	node *new;
	node *p;
	int length = 0,i,j = 0;
	
	length = array_length(name);

	if( 0 == length)
		return name;
	
	new = array_new();
	
	for ( i = 0,j = length - 1 ;i < length ;i++,j--)
	{
	        p = array_last(name); //get the last one 
		array_insert(new,i, p -> item);//insert into new
		array_delete_at(j,name);//delete the last one
	}

	return new;
}

Array array_sort(Array name, int (*compar)(Item n1, Item n2))
{

	return ;

}



int main()
{
        Array node,p,versp;
	int i,length = 0;
	int index = 0;

        node = array_new();

	array_insert(node,0,'a');
	array_insert(node,1,'b');
//	array_insert(node,1,'t');
//	array_insert(node,-1,'c');
	array_insert(node,4,'y');
//	array_delete_at(0,node);
//	array_clear(node);

	index = array_index(node,'y');
	length = array_length(node);
	printf("first is %c\n",array_first(node)->item);
	printf("last is %c\n",array_last(node)->item);
	printf("length is %d\n",length);
	printf("a is %d\n",index);

	versp = array_reverse(node);

	for(i = 0;i<length  ;i++)
	{
		p = array_list(versp,i);
		printf("Array(%d)is %c\n",i, p->item);
	} 


        return 0;

}
