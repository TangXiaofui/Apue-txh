#include "apue.h"

#define BUFFSIZE 4096
int main()
{
	char buf[BUFFSIZE];
	int n ;

	while((n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0)
	{
		if(pwrite(STDOUT_FILENO,buf,n,SEEK_END) != n )
			err_sys("write failed");	
	}

	if(n < 0)
		err_sys("read failed");
	exit(0);
		
}
