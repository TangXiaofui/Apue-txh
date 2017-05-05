#include "apue.h"

#define BSZ 48

int main(int argc,char* argv[])
{
	FILE *fp;
	char buf[BSZ];
	
	memset(buf,'a',BSZ-2);

	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';

	if((fp = fmemopen(buf,BSZ,"w")) == NULL )
		err_sys("fmemopen failed");

	printf("initial buf cont : %s \n",buf);

	fprintf(fp,"hello world");
	printf("before flush\n");

	fflush(fp);
	printf("after fflush : %s(%d)\n",buf,strlen(buf));

	memset(buf,'b',BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf(fp,"hello world");
	fseek(fp,0,SEEK_SET);
	printf("after fflush : %s(%d)\n",buf,strlen(buf));

	memset(buf,'c',BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf(fp,"hello world");
	fclose(fp);
	printf("after fflush : %s(%d)\n",buf,strlen(buf));

}
