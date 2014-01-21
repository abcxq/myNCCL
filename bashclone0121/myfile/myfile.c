#include "shell.h"

int  myfile(int argc,char *argv[])
{

	FILE *fp;
	int i;
	char  magic;
	
	if(argc != 2) /* 检查参数个数 */
        {
                printf("wrong command\n");
                return -1;
        }
	
	fp = fopen( argv[1],"rb");

	if ( NULL  == fp )
	{
		printf(" open file error\n");
		return -1 ;
	}

	printf("magic  ");
	for ( i = 0; i < 16 ;i++)
	{
		
		fread(&magic,sizeof( char ), 1,fp);
		printf("%x ",magic);
	}

	printf("\n");
	fread(&magic,sizeof( char ), 1,fp);

	switch( magic )
	{
		case 1: printf("ELF 32-bit LSB relocatable\n");break;
		case 2: printf("ELF 32-bit LSB executable\n");break;
		case 3: printf("ELF 32-bit LSB Shared object\n");break;
		case 4: printf("ELF 32-bit LSB Core file\n");break;
		default:  printf("No file type\n");
	}
 
	return 0;

}
		
