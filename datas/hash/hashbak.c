#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc,char *argv[])
{

	FILE *fp;
	char buf[256];
	char address[9],symlic[32],*tmp;
	char *c;
	char addr[256];
	
	if (3 != argc)
	{
		printf("Argument is error\n");
		return 0;
	}

	fp = fopen(argv[2],"rb");

	if (NULL == fp)
	{
		printf("Open file error\n");
		return 0;
	}

	while(fgets(buf,256,fp))
	{
		if (strncmp(buf,"        ",8) != 0)
		{
			strcpy(address,strtok(buf," "));
			c = strtok(NULL," ");
			strcpy(symlic,strtok(NULL," "));
			printf("%s %c %s",address,*c ,symlic);
		}
		else
		{
		//	printf("addres is  %s",address);
			strcpy(addr,address);
		//	printf("addr is %s",addr);
			strcat(addr,buf);
			printf("%s",addr);
		} 
	}
		
	
	
	fclose(fp);
	return 0;
}
