/*************************************************************************
	> File Name: 13.2.c
	> Author:YeZe 
	> Mail:2295905420@qq.com 
	> Created Time: Tue 27 Jan 2015 13:44:10 UTC
 ************************************************************************/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *read_fp;
	char buffer[BUFSIZ+1];
	int chars_read;
	memset(buffer,'\0',sizeof(buffer));
	read_fp = popen("ps ax", "r");
	if(read_fp!=NULL){
		chars_read=fread(buffer,sizeof(char),BUFSIZ,read_fp);
		while(chars_read>0){
			buffer[chars_read-1]='\0';
			printf("rending %d : -\n %s \n",BUFSIZ,buffer);
			chars_read=fread(buffer,sizeof(char),BUFSIZ,read_fp);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);


}
