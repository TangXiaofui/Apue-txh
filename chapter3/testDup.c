#include "apue.h"
#include <fcntl.h>
#include <unistd.h>
char buf[] = "test\n";
int main()
{
	int fd = dup(STDOUT_FILENO);
	if(fd < 0)
		err_sys("dup fail");	
	
	int fd2 = dup2(STDOUT_FILENO,5);
	int fd3 = fcntl(fd,F_DUPFD,0);
	printf("fd = %d\n",fd);		
	printf("fd2 = %d\n",fd2);
	printf("fd3 = %d\n",fd3);

	if(write(fd,buf,sizeof(buf)) != sizeof(buf))
		err_sys("write fail");
	if(write(fd2,buf,sizeof(buf)) != sizeof(buf))
		err_sys("write fail");
	if(write(fd3,buf,sizeof(buf)) != sizeof(buf))
		err_sys("write fail");
	exit(0);
}
