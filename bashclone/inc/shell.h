#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <string.h>

int mycp(int argc,char *argv[]);
/*int file_main(int argc,char *argv[]);
int cat_main(int argc,char *argv[]);
int readelf_main(int argc,char *argv[]);*/

static struct operation
{
        char name[8];
        int (*pf)(int,char *[]);
}op[] =
{
        { "mycp",mycp}
//      { "file",file},
//      { "cat", cat},
//      { "readelf",readelf}
};



int (*pf)(int argc,char *argv[]);
int shell_parse(char * buf, char * argv[]);
int do_cmd(int argc, char ** argv);



#endif  /* SHELL_H */
