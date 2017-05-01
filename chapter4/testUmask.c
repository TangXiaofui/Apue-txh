#include "apue.h"
#include <fcntl.h>

//➜  chapter4 git:(master) ✗ ls -l testUmask.c
//-rw-rw-r-- 1 txh txh 316  4月 28 11:11 testUmask.c
//➜  chapter4 git:(master) ✗ umask 
//002
//➜  chapter4 git:(master) ✗ umask -S
//u=rwx,g=rwx,o=rx
//
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
	umask(0);
	if(creat("foo",RWRWRW) < 0)
		err_sys("create error for foo");
	
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	if(creat("bar",RWRWRW) < 0)	
		err_sys("create error for bar");
	exit(0);
}
