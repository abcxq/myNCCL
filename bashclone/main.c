#include "shell.h"


int main(void)
{
    char buf[64];
    int argc = 0;
    char * argv[10];

	while(1)
	{
		printf("# ");
		fgets(buf, 64, stdin);
		buf[strlen(buf)-1] = '\0';

		argc = shell_parse(buf, argv);
		
		do_cmd(argc, argv);

	}



    return 0;
}

