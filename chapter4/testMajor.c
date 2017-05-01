#include "apue.h"
#include <sys/types.h>


int main(int argc,char *argv[])
{
	struct stat buf;
	int i = 0 ;
	for(i = 1; i < argc ; ++i)
	{
		if(stat(argv[i],&buf) < 0)
		{
			err_ret("stat failed");
			continue;
		}	
/*		printf("dev = %d / %d ",major(buf.st_dev),minor(buf.st_dev));
		if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
		{
			printf("(%s) rdev = %d / %d",
			S_ISCHR(buf.st_mode)?"charactor" :"block",
			major(buf.st_rdev),minor(buf.st_rdev));	
		}
		printf("\n");
*/	}
	exit(0);	
}
