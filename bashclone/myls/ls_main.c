#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int myls(int argc, char *argv[])
{
	struct stat buf;
	struct passwd * passent;


	if ( argc > 3)
		printf("Wrong argument numbers\n");


	if (-1 == stat(argv[1] , &buf))
	{
		printf("File does not exists\n"); 
		return -1 ;
	}


	passent = getpwuid(buf.st_uid);
	if(passent == NULL)
		printf(" The owner of the file is #%d - unknown\n", buf.st_uid);

	if ( argc == 2)
	{
		printf("Access mode: 0%o\n",buf.st_mode);
		printf("file uid = %s\n",passent -> pw_name);
		printf("file size = %d\n",buf.st_size);
		printf("file last modify mtime %s\n",ctime( &(buf.st_mtime)));
		printf(" Last status change %s\n", ctime( &(buf.st_ctime)));
	}
	
	if ( argc == 3)
	{
		if ( strcmp( argv[2],"-i" ) == 0)
		{
			printf("file st_ino = %lu\n", buf.st_ino);
			return 0;
		}
		if ( strcmp( argv[2],"-s" ) == 0)
		{
			printf("file st_blocks = %d\n",buf.st_blocks);
			return 0;
		}
		if ( strcmp( argv[2],"-t" ) == 0)
		{
			printf(" Last status change %s\n", ctime( &(buf.st_ctime)));
			return 0;
		}
		printf("Argument is wrong\n");
	}
	
	return 0;
}


int main(int argc, char *argv[])
{

	myls(argc,argv);
	return 0;
}
