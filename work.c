#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("argc error!\n");
		return -1;
	}
	pid_t pid,ppid,uid,gid,euid,egid;
	pid=getpid();
	ppid=getppid();
	uid=getuid();
	gid=getgid();
	euid=geteuid();
	egid=getegid();
	printf("pid=%d,ppid=%d\nuid=%d,gid=%d\neuid=%d,egid=%d\n",pid,ppid,uid,gid,euid,egid);
	int fd=open(argv[1],O_RDWR);
	write(fd,"hello",5);
	close(fd);
	return 0;
}
