#include "apue.h"

//./testStat /etc/passwd /etc /dev/log /dev/tty \
//> /dev/sr0 /dev/cdrom 


int main(int argc,char *argv[])
{
	if(argc < 2)
		err_quit("usage: testStat filename");
	
	int i = 0;
	struct stat buf;
	char* ptr;

	for(i = 1 ; i < argc ; ++i )
	{
		printf("%s : ",argv[i]);
		if(lstat(argv[i],&buf) < 0)
		{
			err_ret("lstat error");
			continue;
		}

		if(S_ISREG(buf.st_mode))
			ptr = "regular";
		else if(S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if(S_ISCHR(buf.st_mode))
			ptr = "charactor special";
		else if(S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if(S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if(S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if(S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "unknow";
		printf("%s\n",ptr);
		 
	}
	exit(0);
}
