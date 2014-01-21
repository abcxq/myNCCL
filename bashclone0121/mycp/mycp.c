#include "shell.h"

int mycp(int argc,char *argv[])
{
	FILE *fp1, *fp2; /* Դ�ļ���Ŀ���ļ� */
	char buf[1024];
	int n;
	
	if(argc != 3) /* ���������� */
	{ 
		printf("wrong command\n");
		return -1;
	}

	if((fp1 = fopen(argv[1], "rb")) == NULL) /* ��Դ�ļ� */
	{
		perror("fail to open");
		return -1;
	}

	if((fp2 = fopen(argv[2], "wb")) == NULL) /* ��Ŀ���ļ� */
	{
		perror("fail to open");
		return -1;
	}

	/* ��ʼ�����ļ����ļ����ܴܺ󣬻���һ��װ���£�����ʹ��һ��ѭ�����ж�д */
	while((n = fread(buf, sizeof(char), 1024, fp1)) > 0)
	/* ��Դ�ļ���ֱ�� ���ļ�����ȫ������ */
	{
		if((fwrite(buf, sizeof(char), n, fp2)) == -1)
		/* ������������ȫ��д ��Ŀ���ļ���ȥ */
		{
			perror("fail to write");
			return -1;
		}
	}

	if(n == -1) /* �����Ϊ�����ֽ�С��0������ѭ������˵�������� */
	{
		perror("fail to read");
		return -1;
	}


	fclose(fp1); /* �ر�Դ�ļ���Ŀ���ļ� */
	fclose(fp2);

        return 0;
}
