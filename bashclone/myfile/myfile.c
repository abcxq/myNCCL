#include "shell.h"

int get_type_index( Elf32_Half    e_type)
{
	int i;
	
	for ( i = 0 ;i< sizeof(type_string)/sizeof(type_string[0]);i++)
	{
		if ( e_type ==  type_string[i].type )
			return i ;
	}
	
	if ( i == sizeof(type_string)/sizeof(type_string[0]))
		return 0;

	return 0;
}
	

int  myfile(int argc,char *argv[])
{

	FILE *fp;
	Elf32_Ehdr *p;
	int sizeofhead = sizeof(Elf32_Ehdr);
	char buf[sizeofhead+1];
	memset ( buf,0,sizeofhead);
	
	int i;
	
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
	
	fread( buf,sizeofhead,1,fp);

	printf("Magic  ");


	p = (Elf32_Ehdr * ) buf;

	for (i =0 ;i<EI_NIDENT; i++)
		printf ( "%02x ",p->e_ident[i]);
	
	printf("\nType:");
	
	printf( "%s\n",type_string[get_type_index(p->e_type)].name );
	
	fclose(fp);
	return 0;

}
		
