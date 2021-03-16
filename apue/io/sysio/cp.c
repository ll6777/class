#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define  BUFSIZE  10

int main(int argc ,char *argv[])
{
	int fd,fd1;
	char buf[BUFSIZE] = {};
	int cnt;

	if(argc < 3) //判断个数
		return 1;
	fd = open(argv[1], O_RDONLY); //第一个文件只读
	if(fd == -1){  //错误判断处理
		perror("open()");
		return 1;
	}
	fd1 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);  //第二个文件  读写 不存在则创建 截断 
	if(fd1 == -1){
		perror("open()");
		goto ERROR1;

	}
	while(1){
		memset(buf, '\0', BUFSIZE);
		cnt = read(fd , buf, BUFSIZE); //读文件 fd
		if(cnt == -1){
			perror("read()");
			return 1;
			goto ERROR;
		}
		if(cnt == 0){ //读完结束
			break;
		}
		write(fd1, buf, cnt);  //写文件

	}
	close(fd);
	close(fd1);
		

	return 0;
ERROR1:
	close(fd);
ERROR:
	close(fd1);
	return 1;

}























