#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd1,fd3;
	char ch;
	int len,tmp;	
	if(argc < 3)
		return 1;

	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1){
		perror("open()");
		goto ERROR;
	}
	fd3 = open(argv[3], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if(fd3 == -1){
		perror("open()");
		goto ERROR;
	}
	for(int i = 0 ;  i < 3 ;  )
	{	
		read(fd1 , &ch , 1);
		if(ch == '\n')
			i++;
		len = lseek(fd1 , 0 , SEEK_CUR);
	}
	lseek(fd1 , 0 , SEEK_SET );
	while(1){
		tmp = read(fd1 , &ch , 1);
		write(fd3 , &ch , tmp);
		if(tmp == 0)
			break;
	}
	lseek(fd3 , len-1 , SEEK_SET);
	for(int j = 0 ; j < strlen(argv[2]); j++ )
			write(fd3 , argv[2]+j ,1 );

	close(fd1);
	close(fd3);

	return 0;




ERROR:
	return 1;
}




