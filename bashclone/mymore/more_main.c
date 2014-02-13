#include<stdio.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<termios.h>

#define MAXLINES 5500  /* max lines of the file */
char *lineptr[MAXLINES];  /* pointers to text lines */
char *tmp;
int width;      //终端屏幕宽度
int height;     //终端屏幕高度
int filesize;   //文件的大小
int readsize;   //已经显示的内容长度
int num_of_lines;     //the lines of the file
struct termios ts,ots;     //终端属性

void gettermsize(int *w,int *h)
{
	struct winsize *ws;

	ws=(struct winsize*)malloc(sizeof(struct winsize));

	memset(ws,0x00,sizeof(struct winsize));
	ioctl(STDIN_FILENO,TIOCGWINSZ,ws);
	*w=ws->ws_col;
	*h=ws->ws_row;
}


void settermattr()
{
	tcgetattr(STDIN_FILENO,&ts);    //获取终端属性 
	ots=ts;         //备份终端属性
	ts.c_lflag &= (~ECHO);    //阻止回显
	ts.c_lflag &= (~ICANON);    //设置终端为非标准模式
	ts.c_cc[VMIN]=1;        //这两行当需要从终端获取字符时立即返回，不需要按回车键
	ts.c_cc[VTIME]=0;
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&ts);    //设置终端的新属性。TCSAFLUSH表示输出队列空了以后才生效，生效之前的输出队列被flush
}

int comput_size( int pos)
{
	int i;
	int sizeread =0;

	for(i = 0;i<pos;i++)
	{
		sizeread += strlen(lineptr[i]);
	}
	return sizeread;
}

void view(int startpos)
{
	int endpos;
	int i;

	endpos = startpos + height -1;


	if ( endpos > num_of_lines)
		endpos = num_of_lines;

	readsize = comput_size(endpos);

	for (i = startpos;i<endpos;i++)
	{
		printf("%s",lineptr[i]);
	}
	printf("\033[7m--more--(%2.0f%%)\033[m",(double)readsize/filesize*100);
	if(endpos == num_of_lines)
        { 
		tcsetattr(STDIN_FILENO,TCSANOW,&ots);        //TCSANOW表示修改立即生效
//		perror("fputs error");
		exit(0);
	}
				

	
}

void do_more(FILE *fp) //model
{
	int linesize=width;
	char line[linesize];
	int reply;      //记录see_more()的返回值
	char *tmp;
	FILE *fp_tty;
	int startpos = 0;
	
	num_of_lines = 0;
	
	while(fgets(line,linesize,fp))
	{   
		tmp = (char *)malloc(strlen(line)*sizeof(char));
                strcpy(tmp,line);
                lineptr[num_of_lines] = tmp;
                num_of_lines++;
	}

	while(1)
	{
		view(startpos);
		reply = ctl_more(); //从键盘获取用户输入的命令
		if(reply == 0)
		{        //用户不需要显示更多内容了，要退出
            		tcsetattr(STDIN_FILENO,TCSANOW,&ots);
              		exit(0);
		}
		else
		{
			startpos += reply;
			if(startpos < 0)
				startpos = 0;
		}

		continue;
			
	}


}

int ctl_more()
{
	int c;

	while((c=getc(stdin))!=EOF)
	{            //注意加括号，赋值操作符是右结合的。如果不加括号会把getchar()!=EOF的结果赋给c
        	if(c=='q')
		{
			return 0;
	        }
        	if(c==' '|| c == 'f')      //空格
		{
			return height;
		}    
		if(c=='\n'|| c == 'j')
		{     //回车
			return 1;
		}
		if(c == 'k')
		{
			return -1;
		}
		if(c == 'b')
			return -1*height;
	}
	
	return 0;
}


int more(int argc,char *argv[])
{
	FILE *fp;
	struct stat *buf;
	filesize=0;
	readsize=0;
	buf=(struct stat*)malloc(sizeof(struct stat));
	memset(buf,0x00,sizeof(struct stat));



	gettermsize(&width,&height);
	settermattr();


	if(argc==1)     
	{
		printf("arument is error\n");
		return -1;
	}
	else
	{       
		if((fp = fopen(*(argv+1),"r"))!=0)
		{     
                	if(stat((const char*)*(argv+1),buf)==0)
			{   
				filesize += buf->st_size;     //获取文件大小
				printf("fs=%ld\n",buf->st_size);
                		do_more(fp);        //显示文件内容
                	}
                	else
			{
				printf("get  file stst error\n");
                		fclose(fp);      //关闭文件
				return -1;
                	}	
            	}
            	else
		{        //打开文件失败,退出程序
			printf("open file error\n");
			return -1;
		}
        }



    tcsetattr(STDIN_FILENO,TCSANOW,&ots);

	return 0;
}




int main(int argc,char *argv[])
{
	more(argc,argv);
	return 0;
}
