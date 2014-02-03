#include "shell.h"

int sed(int argc,char *argv[])
{
	int i=0;
	char *p;
	char *bufp;
	char *argv1_div[5]; /* store sed arguments */
	char buf[64];
 
        p = strtok(argv[1],"/");

	while(p)
        {
		argv1_div[i] = p;
		printf("%s\n",argv1_div[i]);
		p=strtok(NULL,"/");
		i++;
	}

	argv1_div[i] = "0";

	fgets(buf,64,stdin);

	bufp = buf;
	p = strstr(buf, argv1_div[1]);

	i = 0;
	if(p)
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
	else
		printf("String %s not found \n",argv1_div[1]);
	
	return 0;
}
