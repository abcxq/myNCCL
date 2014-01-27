#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <math.h>

int mycp(int argc,char *argv[]);
int myfile(int argc,char *argv[]);
double math(int argc,char *argv[]);

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
        { "myfile",myfile},
        { "math",math}
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

static struct math_type
{
        char name[8];
	int argc;
        void *p; 
}math_op[] =
{
        { "sqrt",2,sqrt},
        { "pow",3,pow},
        { "sin",2,sin}
};
	

double  (*p1)(double);
double  (*p2)(double,double);
int (*pf)(int argc,char *argv[]);
int shell_parse(char * buf, char * argv[]);
int do_cmd(int argc, char ** argv);



#endif  /* SHELL_H */
