#include "apue.h"
#include <limits.h>
#include <dirent.h>

#define FTW_F 	1
#define FTW_D 	2
#define FTW_DNR 3
#define FTW_NS  4

static char *fullpath;
static size_t pathlen;

typedef int Myfunc(const char *,const struct stat *,int);
static Myfunc myfunc;
static int myftw(char *,Myfunc *);
static int dopath(Myfunc *);
static long nreg,ndir,nblk,nchr,nfifo,nslink,nsock,nton;

int main(int argc,char *argv[])
{
	if(argc < 2)
		err_quit("usage: myftw directory");
	
	myftw(argv[1],myfunc);
	nton = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
	if(nton == 0)
		nton = 1;
	printf("regular file 	= %7ld, %5.2f %% \n",nreg,nreg*100.0/nton);
	printf("directories  	= %7ld, %5.2f %%\n",ndir,ndir*100.0/nton);
	printf("block special 	= %7ld, %5.2f %%\n",nblk,nblk*100.0/nton);
	printf("char special 	= %7ld, %5.2f %%\n",nchr,nchr*100.0/nton);
	printf("FIFOs 		= %7ld, %5.2f %%\n",nfifo,nfifo*100.0/nton);
	printf("symbolic link 	= %7ld, %5.2f %%\n",nslink,nslink*100.0/nton);
	printf("socket file 	= %7ld, %5.2f %%\n",nsock,nsock*100.0/nton);
	exit(0);
}



int myftw(char *pathname,Myfunc *func)
{
	fullpath = path_alloc(&pathlen);
	if(pathlen < strlen(pathname))
	{
			pathlen = strlen(pathname) * 2;
			if((fullpath = realloc(fullpath,pathlen)) == NULL)
				err_sys("realloc failed");
	}

	strcpy(fullpath,pathname);
	return dopath(func);
}

int dopath(Myfunc *func)
{
	struct stat buf;
	struct dirent *d;
	DIR *dir;
	int ret, n;
	if(lstat(fullpath,&buf) < 0)
		return func(fullpath,&buf,FTW_NS);
	if(S_ISDIR(buf.st_mode) == 0)
	{
		return func(fullpath,&buf,FTW_F);
	}

	if((ret = func(fullpath,&buf,FTW_D)) != 0)
	{
		return ret;
	}
	n = strlen(fullpath);
	if(n+NAME_MAX + 2 > pathlen)
	{
		pathlen *= 2;
		if((fullpath = realloc(fullpath,pathlen)) == NULL)
			err_sys("realloc failed");	
	}
	fullpath[n++] = '/';
	fullpath[n] = '\0';
	if((dir = opendir(fullpath)) == NULL)
		return func(fullpath,&buf,FTW_DNR);
	while((d = readdir(dir)) != NULL)
	{
		if(strcmp(".",d->d_name) == 0 || strcmp("..",d->d_name) == 0)
			continue;
		strcpy(&fullpath[n],d->d_name);
		if((ret = dopath(func)) != 0)
			break;	
	}
	fullpath[n-1] = '\0';
	if(closedir(dir) < 0)
		err_sys("closedir failed");
	return ret;
}


int myfunc(const char *name,const struct stat *buf,int type)
{
	switch(type){
	case FTW_F:
		switch(buf->st_mode & S_IFMT){
		case S_IFREG: nreg++; break;
		case S_IFBLK: nblk++; break;
		case S_IFCHR: nchr++; break;
		case S_IFIFO: nfifo++;break;
		case S_IFLNK:nslink++;break;
		case S_IFSOCK:nsock++;break;
		case S_IFDIR: 
			err_dump("failed");
		}
		break;
	case FTW_D:
		ndir++;
		break;
	case FTW_DNR:
		err_ret("FTW_DNR");
		break;
	case FTW_NS:
		err_ret("FTW_NS");
		break;	
	default:
		err_dump("unknow");
	}	
	return 0;
}
