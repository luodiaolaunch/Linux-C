/*************************************************************************
  > File Name: 1select.c
  > Author: YeZe
  > Mail:2295905420@qq.com 
  > Created Time: Thu 29 Jan 2015 08:51:09 UTC
 ************************************************************************/
#include"1sel.h"
int main(int argc,char *argv[])
{
	int fd21,fd31,fd3,fd5;
	char buf[1024]="";
	fd31=open(argv[1],O_RDONLY);
	printf("2 open sucess!\n");
	fd21=open(argv[2],O_RDONLY);
	printf("1 open suceess\n");
	fd3=open(argv[3],O_WRONLY);
	fd5=open(argv[5],O_WRONLY);
	while(1)
	{
		memset(buf,0,1024);
		read(fd31,buf,1024);
		if(strcmp(buf,"")!=0)
			printf("from 1: %s",buf);
		memset(buf,0,1024);
		read(fd21,buf,1024);
		if(strcmp(buf,"")!=0)
			printf("from 2: %s",buf);
		memset(buf,0,1024);
		read(0,buf,1024);
		write(fd3,buf,strlen(buf));
	
		memset(buf,0,1024);
		read(0,buf,1024);
		write(fd5,buf,strlen(buf));
	}
	printf("end of program.\n");
	close(fd21);
	close(fd31);
}
