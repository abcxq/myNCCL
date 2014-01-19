#include <stdio.h>
#include <string.h>
#include "shell.h"


//extern struct operation op[1];

int shell_parse(char * buf, char * argv[])
{
    int argc = 0;
    int state = 0;

    while (*buf)
    {
        if (*buf != ' ' && state == 0)
        {
            argv[argc++] = buf;
            state = 1;
        }


        if ((*buf == ' ') && state == 1)
        {
            *buf = '\0';
            state = 0;
        }

        buf++;  
    }

    return argc;
}

int do_cmd(int argc, char ** argv)
{
    int i;
#if 0
    printf("argc = %d\n", argc);

    for (i = 0; i < argc; i++)
        printf("argv[%d]: <%s>\n", i, argv[i]); 
#endif 

	for ( i = 0; i<sizeof(op)/sizeof(op[0]);i++)
	{
		if ( strcmp(argv[0],op[i].name) == 0)
		{
			pf = op[i].pf;
			pf(argc,argv);
			break;
		}
		else
		{
			printf(" command not found!\n");
			break;
		}
	}
	return 0;
}



