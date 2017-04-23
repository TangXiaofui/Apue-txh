#include "apue.h"
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc,char* argv[])
{
	int n = 0 ;
	char buf[BUF_SIZE];
	while((n = read(STDIN_FILENO,buf,BUF_SIZE)) > 0)
	{
		if(write(STDOUT_FILENO,buf,n) != n)
		{
			err_sys("write error");		
		}
	}
	if(n < 0)
	{
		err_sys("read fail");	
	}

	exit(0);	
}
