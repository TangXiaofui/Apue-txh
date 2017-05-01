#include "apue.h"

//➜  chapter4 git:(master) ✗ ls -al bar foo
//-rw------- 1 txh txh 0  4月 28 11:11 bar
//-rw-rw-rw- 1 txh txh 0  4月 28 11:11 foo
//➜  chapter4 git:(master) ✗ ./testChmod 
//➜  chapter4 git:(master) ✗ ls -al bar foo
//-rw-rw---- 1 txh txh 0  4月 28 11:11 bar
//-rw-rwSrw- 1 txh txh 0  4月 28 11:11 foo
//

int main()
{
	struct stat statbuf;
	if(stat("foo",&statbuf) < 0)
		err_sys("stat err for statbuf");
	if(chmod("foo",(statbuf.st_mode & ~S_IXGRP)|S_ISGID) < 0)
		err_sys("chmod err for foo");
		
	if(chmod("bar",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP) < 0)
		err_sys("chmod err for bar");
	
	exit(0);
	 	
}
