#include "shell.h"

int mycp(int argc,char *argv[])
{
	FILE *fp1, *fp2; /* 源文件和目标文件 */
	char buf[1024];
	int n;
	
	if(argc != 3) /* 检查参数个数 */
	{ 
		printf("wrong command\n");
		return -1;
	}

	if((fp1 = fopen(argv[1], "rb")) == NULL) /* 打开源文件 */
	{
		perror("fail to open");
		return -1;
	}

	if((fp2 = fopen(argv[2], "wb")) == NULL) /* 打开目标文件 */
	{
		perror("fail to open");
		return -1;
	}

	/* 开始复制文件，文件可能很大，缓冲一次装不下，所以使用一个循环进行读写 */
	while((n = fread(buf, sizeof(char), 1024, fp1)) > 0)
	/* 读源文件，直到 将文件内容全部读完 */
	{
		if((fwrite(buf, sizeof(char), n, fp2)) == -1)
		/* 将读出的内容全部写 到目标文件中去 */
		{
			perror("fail to write");
			return -1;
		}
	}

	if(n == -1) /* 如果因为读入字节小于0而跳出循环，则说明出错了 */
	{
		perror("fail to read");
		return -1;
	}


	fclose(fp1); /* 关闭源文件和目标文件 */
	fclose(fp2);

        return 0;
}
