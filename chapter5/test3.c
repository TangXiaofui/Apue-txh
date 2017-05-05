#include "apue.h"


int main(int argc,char *argv[])
{
	char name[L_tmpnam],line[MAXLINE];
	
	FILE *fp;
	
	printf("%s\n",tmpnam(NULL));
	
	tmpnam(name);
	printf("name = %s\n",name);
	
	if((fp = tmpfile()) == NULL)
	{
		err_sys("tmpfile failed");	
	}
	
	fputs("abcdefg\n",fp);
	rewind(fp);
	
	if(fgets(line,MAXLINE,fp) == NULL)
		err_sys("fgets fail");
	fputs(line,stdout);

	exit(0);

}
