#include "apue.h"
#include <errno.h>

void make_tmp(char *template);

int main(int argc,char *argv[])
{
	char good_template[] = "/tmp/dirXXXXXX";
	char *bad_template = "tmp/dirXXXXXX";	
	
	printf("create first file :");
	make_tmp(good_template);

	printf("create second file :");
	make_tmp(bad_template);

	exit(0);
}


void make_tmp(char *template)
{
	int fd;
	struct stat buf;

	if((fd = mkstemp(template)) < 0)
		err_sys("can't create temp file");
	
	close(fd);

	if(stat(template,&buf) < 0)
	{
		if(errno == ENOENT)
			err_sys("file doesn't exist");
		else
			err_sys("stat failed");	
	}
	else
	{
		printf("file exist\n");
		unlink(template);	
	}
}
