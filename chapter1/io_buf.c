#include "apue.h"

int main(int argc,char* argv[])
{
	int c;
	while((c = getc(stdin)) != EOF)
	{
		if(putc(c,stdout) == EOF)
		{
			err_sys("putc fail");		
		}
	}
	if(ferror(stdin))
	{
		err_sys("input err");
	}
	exit(0);	
}
