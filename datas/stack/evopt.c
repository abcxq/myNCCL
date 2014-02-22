#include <stdio.h>

char optr[512];
char tmpopnd[512];
int opnd[512];
int toptr = 0;
int topnd = 0;
int toptmp = 0;

void push(char c)
{
	stack[top++] = c;
}

char pop(void)
{
	return stack[--top];
}

int is_empty(void)
{
	return top == 0;
}

double  count(int op1,int op2,char op)
{
        double result;
        switch(op)
        {
                case '+':result = op1 + op2;break;
                case '-':result = op1 - op2;break;
                case '*':result = op1 * op2;break;
                case '/':result = op1 / op2;break;
        }
        return result;
}


int  main(void)
{
        char result,n;
        char *inputc;
        char buf[64];
	push(&optr,'#');

	printf("请输入表达式\n");

        fgets(buf,64,stdin);
    
        inputc = buf;

        while(1)    
        {   
		
		if(*inputc <= '9' && *inputc >= '0')
                {   
                        push(&tmpopnd,*inputc);
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
	
