#include "shell.h"

int sed(int argc,char *argv[])
{
	int i = 0;
	char *bufp;
	char *cmd,*regexp, *replace, *flags = NULL;
	char flag;
	char buf[64];
 
        cmd = strtok(argv[1],"/");
	regexp = strtok(NULL,"/");
	replace = strtok(NULL,"/");
	flag = strtok(NULL,"/");

/*	while(p)
        {
		argv1_div[i] = p;
		printf("%s\n",argv1_div[i]);
		p=strtok(NULL,"/");
		i++;
	}

	argv1_div[i] = "0"; */

	fgets(buf,64,stdin);

	bufp = buf;
	p = strstr(buf, regexp);

	if( NULL == p)
		printf("String %s not found \n",regexp);
	else
	{
		while ( *bufp )
		{
			if (bufp != p)
			{
				printf("%c",*bufp);
				bufp++;
			}
			else
			{
				switch(*argv1_div[3])
				{
					case 'g':
						printf("%s",argv1_div[2]);
						bufp = p + sizeof(argv1_div[1]);
						p = strstr(bufp, argv1_div[1]);
						break;
					case '0':
						printf("%s",argv1_div[2]);
                                        	bufp = p + sizeof(argv1_div[1]);
                                        	printf("%s\n",bufp);
       	                                	return 0;
					default:
						i++;
						if ( i == atoi( argv1_div[3]))
						{
							printf("%s",argv1_div[2]);
                                        		bufp = p + sizeof(argv1_div[1]);
                                        		printf("%s\n",bufp);
       	                                		return 0;
						}
						else
						{
							printf("%s",argv1_div[1]);
							bufp = p + sizeof(argv1_div[1]);
							p = strstr(bufp, argv1_div[1]);
							break;
						}
				}	
			}	
		}	
	}
	return 0;
}
