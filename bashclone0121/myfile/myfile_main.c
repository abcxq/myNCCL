#include "shell.h"

int main(int argc,char *argv[])
{
	if ( -1 == myfile(argc,argv))
		return -1;

	return 0;
}


