#include "apue.h"
#include <fcntl.h>
int main()
{
	if(open("tags",O_RDWR) < 0)
		err_sys("open failed");
	
	if(unlink("tags") < 0)
		err_sys("unlink failed");
	printf("unlink file\n");	
	sleep(30);
	printf("done\n");
	exit(0);	
}
