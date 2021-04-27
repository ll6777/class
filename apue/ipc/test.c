#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define  BUFSIZE  10



int changestr(char *p);
int copyfile(int rfd , int wfd , int flag);

int main(int argc , char *argv[])
{
	int fd;
	pid_t pid;
	int pfd[2] = {};

	if(argc < 2)
		exit(1);
	fd = open(argv[1] , O_RDONLY);
	if(fd == -1){
		perror("open()");
		exit(1);
	}
	if(pipe(pfd) == -1){
		perror("pipe()");
		close(fd);
		exit(1);
	}
	pid = fork();
	if(-1 == pid){
		perror("fork()");
		close(pfd[0]);
		close(pfd[1]);
	}
	if(pid == 0){
		close(pfd[1]);
		copyfile(pfd[0], 1 , 1);
		close(pfd[0]);
		exit(0);
	}

	close(pfd[0]);
	copyfile(fd, pfd[1] , 0);
	close(pfd[1]);


	wait(NULL);
	exit(0);






}

int changestr(char *p)
{
	while(*p){
		if(*p >= 'A' && *p <= 'Z')
			*p = *p + ('a' - 'A');
		else if(*p >='a'  && *p <= 'z')
			*p = *p - ('a' - 'A');
	p++;
	}

	return 0;
}

int copyfile(int rfd , int wfd , int flag)
{
	char buf[BUFSIZE] = {};
	int cnt;

	while(1){
		memset(buf , '\0' , BUFSIZE);
		cnt = read(rfd , buf , BUFSIZE-1);
		if(cnt == -1){
			return errno;
		}
		if(cnt == 0)
			break;
		if(flag)
			changestr(buf);
		write(wfd , buf , cnt);
	}

	return 0;
}








