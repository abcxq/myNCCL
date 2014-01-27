#include "shell.h"

int get_mathtype_index( char *name)
{
        int i;

        for ( i = 0 ;i< sizeof(math_op)/sizeof(math_op[0]);i++)
        {
                if ( strcmp(name,math_op[i].name) == 0 )
                        return i ;
        }

        if ( i == sizeof(math_op)/sizeof(math_op[0]))
                return -1;

        return 0;
}

double math(int argc,char *argv[])
{
	int i;
	double result;
	
	i = get_mathtype_index(argv[1]);
	
	if ( -1 == i)
	{
		printf("No such math command\n");
		return 0;
	}			

	if ( argc != math_op[i].argc + 1)
	{
		printf(" Wrong argument number\n");
		return 0;
	}

	if ( argc == 3)
	{
		p1 = (double (*)(double))math_op[i].p;
		result = p1(atof(argv[2]));	
		printf (" result = %lf \n",result );
	}

	if ( argc == 4)
	{
		p2 = (double (*)(double,double))math_op[i].p;
		result = p2(atof(argv[2]),atof(argv[3]));	
		printf (" result = %lf \n",result );
	}
	
	return 0;
}
