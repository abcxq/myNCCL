#include<stdio.h>
#include<malloc.h>

#define stack_size 100

typedef struct node
{
	char *base;
	char *top;
}sqstack;

int  initstack(sqstack *s)
{
	s->base = (char *)malloc(stack_size*sizeof(char));
	s->top = s->base;
	return 0;
}

int push(sqstack *s,char data)
{
		*s->top++ = data;
		
	return 0;
}

int  gettop(sqstack *s,char *top_item)
{
	if(s->base == s->top)
		return -1;
	else 
		*top_item = *(s->top - 1);

		return 0;
}

int  pop(sqstack *s,char *item)
{
	if(s->base == s->top)
		return -1;
	else 
		*item = *(--s->top);
	return 0;
}

int getvalue(char ch)
{
	int k = 10;
	switch(ch)
	{
		case '+':k=0;break;
		case '-':k=1;break;
		case '*':k=2;break;
		case '/':k=3;break;
		case '(':k=4;break;
		case ')':k=5;break;
		case '#':k=6;break;
	}
	return k;
}

char sign(char ch1,char ch2)
{
	int i,j;
	char sign;
	char a[7][7]={

		{'>','>','<','<','<','>','>'},

		{'>','>','<','<','<','>','>'},

		{'>','>','>','>','<','>','>'},

		{'>','>','>','>','<','>','>'},

		{'<','<','<','<','<','=',' '},

		{'>','>','>','>',' ','>','>'},

		{'<','<','<','<','<',' ','='}

		};
	i = getvalue(ch1);
	j = getvalue(ch2);

//	sign = a[i][j];
	return a[i][j];
}

char count(char op1,char op2,char op)
{
	int l;
	switch(op)
	{
		case '+':l=(op1-'0')+(op2-'0');break;
		case '-':l=(op1-'0')-(op2-'0');break;
		case '*':l=(op1-'0')*(op2-'0');break;
		case '/':l=(op1-'0')/(op2-'0');break;
	}
	return(l+'0');
}

int  main(void)
{
	char result,n;
	char *inputc;
	char buf[64];
	char top_item = '0';
	char op1 = '1',op2 = '2',op = '+';
	char e='z';
	sqstack optr,opnd;

	initstack(&optr);
	push(&optr,'#');
	initstack(&opnd);

	printf("请输入表达式\n");

	fgets(buf,64,stdin);
	
	inputc = buf;

	while(1)    
	{
		if (*inputc == '\n')
		{
			pop(&optr,&op);
                        pop(&opnd,&op2);
                        pop(&opnd,&op1);
                        n = count(op1,op2,op);
                        push(&opnd,n);
                        break;
		}

		if(*inputc <= '9' && *inputc >= '0')
		{
			push(&opnd,*inputc);
			inputc++;
		}		
		else
		{
			gettop(&optr,&top_item);
			e = sign(top_item,*inputc);	
			switch(e)
			{
				case'<':push(&optr,*(inputc));
					inputc++;
					break;
				case'=':pop(&optr,&op);
					inputc++;
					break;
				case'>':pop(&optr,&op);
					pop(&opnd,&op2);
					pop(&opnd,&op1);
					n = count(op1,op2,op);
					push(&opnd,n);
					break;
			}
		}
	}

	gettop(&opnd,&result);
	printf("结果为:%d\n",result - '0');

	return 0;
}

