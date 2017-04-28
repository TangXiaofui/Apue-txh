#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefg";
char buf2[] = "hijklmn";

// od -c file.hole
// ls -ls 查看文件占用的磁盘块
int main()
{
	int fd;
	if( (fd = creat("file.hole",FILE_MODE)) < 0)
		err_sys("create file failed");

	if(write(fd,buf1,sizeof(buf1)) < 0)
		err_sys("write buf1 failed");

	if(lseek(fd,16384,SEEK_SET) == -1)
		err_sys("lseek failed");

	if(write(fd,buf2,sizeof(buf2)) < 0)
		err_sys("write buf2 failed");
	
	close(fd);
	
	exit(0);
}
