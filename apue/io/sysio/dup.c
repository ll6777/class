#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
	int fd;

	fd = open("hello",O_WRONLY | O_CREAT | O_TRUNC ,0666);

	close(1);
	dup(fd);

//	dup2(fd, 1);

	printf("hello!!!!!\n");


	close(fd);
	return 0;
}





