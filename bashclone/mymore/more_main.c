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
int width;      //�ն���Ļ���
int height;     //�ն���Ļ�߶�
int filesize;   //�ļ��Ĵ�С
int readsize;   //�Ѿ���ʾ�����ݳ���
int num_of_lines;     //the lines of the file
struct termios ts,ots;     //�ն�����

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
	tcgetattr(STDIN_FILENO,&ts);    //��ȡ�ն����� 
	ots=ts;         //�����ն�����
	ts.c_lflag &= (~ECHO);    //��ֹ����
	ts.c_lflag &= (~ICANON);    //�����ն�Ϊ�Ǳ�׼ģʽ
	ts.c_cc[VMIN]=1;        //�����е���Ҫ���ն˻�ȡ�ַ�ʱ�������أ�����Ҫ���س���
	ts.c_cc[VTIME]=0;
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&ts);    //�����ն˵������ԡ�TCSAFLUSH��ʾ������п����Ժ����Ч����Ч֮ǰ��������б�flush
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
		tcsetattr(STDIN_FILENO,TCSANOW,&ots);        //TCSANOW��ʾ�޸�������Ч
//		perror("fputs error");
		exit(0);
	}
				

	
}

void do_more(FILE *fp) //model
{
	int linesize=width;
	char line[linesize];
	int reply;      //��¼see_more()�ķ���ֵ
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
		reply = ctl_more(); //�Ӽ��̻�ȡ�û����������
		if(reply == 0)
		{        //�û�����Ҫ��ʾ���������ˣ�Ҫ�˳�
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
	{            //ע������ţ���ֵ���������ҽ�ϵġ�����������Ż��getchar()!=EOF�Ľ������c
        	if(c=='q')
		{
			return 0;
	        }
        	if(c==' '|| c == 'f')      //�ո�
		{
			return height;
		}    
		if(c=='\n'|| c == 'j')
		{     //�س�
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
				filesize += buf->st_size;     //��ȡ�ļ���С
				printf("fs=%ld\n",buf->st_size);
                		do_more(fp);        //��ʾ�ļ�����
                	}
                	else
			{
				printf("get  file stst error\n");
                		fclose(fp);      //�ر��ļ�
				return -1;
                	}	
            	}
            	else
		{        //���ļ�ʧ��,�˳�����
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
