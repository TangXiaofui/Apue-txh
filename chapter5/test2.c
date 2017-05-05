#include "apue.h"


int main(int argc,char* argv[])
{
	char buf[MAXLINE];
	char *p;
	while((p = fgets(buf,MAXLINE,stdin)) != NULL){
		if(fputs(buf,stdout) == EOF)
			err_sys("fputs failed");	
		printf("p = %s\n",p);
	}	
	if(ferror(stdin))
		err_sys("stdin error");
	
	exit(0);
}
