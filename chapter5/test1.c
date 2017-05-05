#include "apue.h"

int main(int argc,char *argv[])
{
	char c;
	while((c = getc(stdin)) != EOF){
		if(putc(c,stdout) == EOF)
			err_sys("putc failed");	
	}	
	if(ferror(stdin))
		err_sys("stdin error");
	
	exit(0);
}
