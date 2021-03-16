#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include<string.h>

int main(int argc , char *argv[])
{
	int fd,fd1;
	
	if(argc < 2){
	for(int i = 1 ; i < 10 ; i++)
	{
		for(int j = 1; j <= i ; j++){
			printf("*");
		}
		printf("\n");
	}
	}
	
	if(argc > 2   &&  strcmp(argv[1], ">>>>") == 0){
		fd = open(argv[2] , O_RDWR  |  O_CREAT  |O_TRUNC,0666);
		if(fd == -1){
				perror("open()");
				return 1;
		}

		dup2(fd, 1);
		for(int i = 1 ; i < 10 ; i++)
		{
				for(int j = 1; j <= i ; j++){
						printf("*");
				}
				printf("\n");
		}
		close(fd);

	}


	return 0;
}











