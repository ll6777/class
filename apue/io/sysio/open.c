#include<stdio.h>  // 输入
#include <sys/types.h> // 2 3 4 是调用open函数需要的
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>  //错误输出数字
#include<unistd.h>  //使用close关闭函数需要的头文件


int main(int argc,  char **argv)
{
/*	if(argc  <  2){
		return -1;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		printf("errno:%d\n", errno);
		perror("open()");
		return 1;
	}
	printf("fd:%d\n",fd);*/

	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if(fd == -1){
		perror("open()");
		return 1;
	}
	
	close(fd);

	return 0;
}














