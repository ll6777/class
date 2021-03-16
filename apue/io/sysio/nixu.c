#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	int fd,fd1;
//	char buf[100] = {};
	int len;
	char ch;

	if (argc < 3)
		return 1;

	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("open()");
		goto ERROR;
	}

	fd1 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (-1 == fd1) {
		perror("open()");
		goto ERROR2;
	}
	len = lseek(fd, 0, SEEK_END);
	printf("%d\n", len);
	if(len == -1){
		perror("lseek()");
		goto SEEKERROR;

	}


	while(len-- > 0){
		lseek(fd , len , SEEK_SET);
		read(fd, &ch , 1);
		write(fd1, &ch , 1);		

	}
	close(fd);
	close(fd1);


	return 0;
SEEKERROR:
	close(fd);
	close(fd1);
READERROR:
	close(fd);
ERROR2:
	close(fd1);
ERROR:
	return 1;
}




















