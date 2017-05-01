#include "apue.h"
#include <fcntl.h>

//chapter4 git:(master) ✗ sudo chown root testAccess
//[sudo] password for txh: 
//➜  chapter4 git:(master) ✗ ls -l testAccess
//-rwxrwxr-x 1 root txh 14780  4月 28 10:43 testAccess
//➜  chapter4 git:(master) ✗ sudo chmod u+s testAccess
//➜  chapter4 git:(master) ✗ ls -l testAccess         
//-rwsrwxr-x 1 root txh 14780  4月 28 10:43 testAccess
//➜  chapter4 git:(master) ✗ ./testStat /etc/shadow
///etc/shadow : regular
//➜  chapter4 git:(master) ✗ ./testAccess /etc/shadow
//access error for /etc/shadow: Permission denied
//open for reading ok
//➜  chapter4 git:(master) ✗ sudo ./testAccess /etc/shadow
//read access ok
//open for reading ok


int main(int argc,char *argv[])
{
	if(argc != 2)
		err_quit("usage : testAccesss filename");
		
	if(access(argv[1],R_OK) < 0)
		err_ret("access error for %s",argv[1]);
	else
		printf("read access ok\n");
	
	int fd;	
	if((fd = open(argv[1],O_RDONLY)) < 0)
		err_ret("open error for %s",argv[1]);
	else
		printf("open for reading ok\n");
	char buf[1024] = {0} ;
	int n = read(fd,buf,1024);
	printf("%s",buf);	
	return 0;	
}
