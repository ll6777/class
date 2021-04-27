#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

#define BUFSIZE  100


int main(void)
{
	char buf[] = {};
	time_t t;
	struct tm *tmp;
	int fd;
	
	fd = open("/home/ll/class/apue/contrl/lllll.c" , O_RDWR|O_CREAT|O_TRUNC,0666);

	while(1){
	time(&t);
	tmp = localtime(&t);
	strftime(buf ,BUFSIZE , "%Y-%m-%d-%H:%M:%S\n" ,tmp);
	
	write(fd , buf , strlen(buf));
	
	sleep(1);
	}
	
	close(fd);


	exit(0);
}




