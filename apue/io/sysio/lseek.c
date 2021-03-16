#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
	int fd;
//	char buf[100] = {'h','e','l','l','o','w','o','r','l','d'};
//	int cnt;
	fd = open(argv[1], O_RDWR/* | O_APPEND*/ );
	if(fd == -1){
		perror("open()");
		return 1;
	}
	lseek(fd,-100,SEEK_END);
	write(fd,"HELLO!!!!!!!", 10);
	close(fd);
	



	return 0;
}




























