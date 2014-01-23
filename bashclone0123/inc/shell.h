#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <string.h>
#include <elf.h>

int mycp(int argc,char *argv[]);
int myfile(int argc,char *argv[]);
/*int file_main(int argc,char *argv[]);
int cat_main(int argc,char *argv[]);
int readelf_main(int argc,char *argv[]);*/

static struct operation
{
        char name[8];
        int (*pf)(int,char *[]);
}op[] =
{
        { "mycp",mycp},
        { "myfile",myfile}
//      { "cat", cat},
//      { "readelf",readelf}
};


static struct elf_type
{
	int type;
        char name[32];
}type_string[] =
{
	{ET_NONE,"No file type"},
	{ET_REL, "Relocatable file"},
	{ET_EXEC,"Executable file"},
	{ET_DYN,"Shared object file"},
	{ET_CORE,"Core file"}
};

int (*pf)(int argc,char *argv[]);
int shell_parse(char * buf, char * argv[]);
int do_cmd(int argc, char ** argv);



#endif  /* SHELL_H */
