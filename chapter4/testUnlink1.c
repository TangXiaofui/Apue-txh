#include "apue.h"
#include <fcntl.h>
int main()
{
	if(open("tags",O_RDWR) < 0)
		err_sys("open failed");
	
	printf("open file\n");	

	sleep(30);
	printf("open done\n");
	exit(0);	
}
