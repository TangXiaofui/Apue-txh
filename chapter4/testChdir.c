#include "apue.h"

int main(int argc,char *argv[])
{
	if(chdir("/home/txh/Github") < 0)
		err_sys("chdir failed");
	
	size_t pathlen;
	char* pathname;
	pathname = path_alloc(&pathlen);
	if(getcwd(pathname,pathlen) == NULL)
		err_sys("getcwd failed");
	printf("cwd = %s\n",pathname);
	exit(0);	
}
