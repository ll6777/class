#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include<string.h>


int main(int argc , char *argv[])
{
	int fd;
	char buf[1024] = {};
	int cnt;

	if(argc < 2){
		printf("缺少统计文件\n");
		return 1;
	}
	fd = open(argv[1] , O_RDONLY);
	if(fd == -1){
		perror("open()");
		return 1;
	}
	while(1){
		memset(buf , '\0' , 1024);
		cnt = read(fd, buf, 1024 );
		if (cnt == -1) {
			perror("read()");
			goto ERROR;
		}
		if (cnt == 0) {
			// EOF
			break;
		}
		
		int ch,flag = 1,count = 0;
		for(int i = 0;buf[i] != '\0';i++)
  		{
			if(buf[i] == ' ')
			{
	  			flag = 0;
			}
	 		else
	 		{
	   			if(flag == 0)
	   			{
					count++;
					flag = 1;
	   			}
	 		}
  		}
	printf("文件里面的单词个数为COUNT:%d\n",count);

	}
	close(fd);


ERROR:
	close(fd);
	return 0;
}


























