/*************************************************************************
  > File Name: sel.c
  > Author: YeZe
  > Mail:2295905420@qq.com 
  > Created Time: Thu 29 Jan 2015 14:35:26 UTC
 ************************************************************************/

#include<stdio.h>
#include<sys/select.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<fcntl.h>
#include<sys/types.h>

void useselect(int a,int b,int c,int d)
{
	printf("select begin!\n");
	char buf[1024];		
	int  retu;
	int flag=0;

	fd_set read_sets;	
fg:	FD_ZERO(&read_sets);//like memset
	FD_SET(a,&read_sets);
	FD_SET(b,&read_sets);
	FD_SET(0,&read_sets);
	memset(buf,0,1024);

	printf("start select!\n");
	retu=select(1024,&read_sets,NULL,NULL,NULL);//NULL means keep wait
	flag =0;
	if(retu){
		if(FD_ISSET(a,&read_sets))
		{
			memset(buf,0,1024);
			if(read(a,buf,1023)==0)
				flag++;
			if(strcmp(buf,"")!=0)
				printf("2 said---:%s\n",buf);
		}
		if(FD_ISSET(b,&read_sets))
		{
			memset(buf,0,1024);
			if(read(b,buf,1023)!=0)
				printf("3 said---:%s\n",buf);
			else
				flag++;
		}
		if(FD_ISSET(0,&read_sets))
		{
			memset(buf,0,1024);
			read(0,buf,1024);
			write(d,buf,strlen(buf));
			write(c,buf,strlen(buf));
			printf("read something and write finish \n");
		}
	}
	if(flag==2)
	{
		printf("noinput");
		exit(1);
	}

	goto fg;
}

